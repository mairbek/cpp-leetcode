#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace {

class RandomizedCollection {
 public:
  /** Initialize your data structure here. */
  RandomizedCollection() {}

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {
    bool result = values_.find(val) == values_.end();
    int idx = iterators_.size();
    auto it = values_.emplace(std::make_pair(val, idx));
    iterators_.push_back(it);
    return result;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    auto it = values_.find(val);
    if (it == values_.end()) {
      return false;
    }
    int idx = it->second;
    std::swap(iterators_[idx], iterators_[iterators_.size() - 1]);
    iterators_[idx]->second = idx;
    iterators_.pop_back();
    values_.erase(it);
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    int pos = rand() % iterators_.size();
    return iterators_[pos]->first;
  }

 private:
  std::unordered_multimap<int, int> values_;
  std::vector<std::unordered_multimap<int, int>::iterator> iterators_;
};
}  // namespace

int main(int argc, char const** argv) {
  std::cout << "Hello, World" << std::endl;

  RandomizedCollection rc;

  //   std::cout << rc.insert(1) << rc.insert(1) << " " << rc.insert(2) << " "
  //   << rc.insert(1) << " "
  //             << rc.insert(2) << " " << rc.insert(10) << " " << rc.remove(1)
  //             << " " << rc.getRandom()
  //             << " " << std::endl;

  //    for (int i = 0; i < 10; i++) {
  //        std::cout << rc.getRandom() << std::endl;
  //    }

  rc.insert(1);
  rc.insert(1);
  rc.remove(1);
  rc.getRandom();
  return 0;
}
