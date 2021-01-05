#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
 private:
  list<pair<int, int> > doubleLinkList;
  unordered_map<int, list<pair<int, int> >::iterator> map;
  int _capacity;

 public:
  explicit LRUCache(int capacity)
      : _capacity(capacity) {
  }

  int get(int key) {
    auto itermap = map.find(key);
    if (itermap == map.end())
      return -1;

    doubleLinkList.push_front(*(itermap->second));
    doubleLinkList.erase(itermap->second);
    map[key] = doubleLinkList.begin();
    return map[key]->second;
  }

  void put(int key, int value) {
    auto itermap = map.find(key);
    if (itermap == map.end()) {
      if (map.size() >= _capacity) {
        map.erase(doubleLinkList.back().first);
        doubleLinkList.pop_back();
      }
    } else {
      doubleLinkList.erase(itermap->second);
    }
    doubleLinkList.push_front(pair<int, int>(key, value));
    map[key] = doubleLinkList.begin();
  }
};
