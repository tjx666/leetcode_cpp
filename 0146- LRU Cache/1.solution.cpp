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

int main() {
  LRUCache lRUCache(2);
  lRUCache.put(1, 1);  // 缓存是 {1=1}
  lRUCache.put(2, 2);  // 缓存是 {1=1, 2=2}
  lRUCache.get(1);     // 返回 1
  lRUCache.put(3, 3);  // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  lRUCache.get(2);     // 返回 -1 (未找到)
  lRUCache.put(4, 4);  // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  lRUCache.get(1);     // 返回 -1 (未找到)
  lRUCache.get(3);     // 返回 3
  lRUCache.get(4);     // 返回 4

  return 0;
}