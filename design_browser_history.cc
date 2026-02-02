#include <iostream>
#include <string>
#include <vector>

// https://leetcode.com/problems/design-browser-history/
namespace {

class BrowserHistory {
 private:
  std::vector<std::string> history_;
  int current_page_;

 public:
  BrowserHistory(std::string homepage) {
    history_.push_back(homepage);
    current_page_ = 1;
  }

  void visit(std::string url) {
    history_.resize(current_page_);
    history_.push_back(url);
    current_page_++;
  }

  std::string back(int steps) {
    current_page_ = std::max(current_page_ - steps, 1);
    return history_[current_page_ - 1];
  }

  std::string forward(int steps) {
    int max_pages = history_.size();
    current_page_ = std::min(current_page_ + steps, max_pages);
    return history_[current_page_ - 1];
  }
};

}  // namespace

int main(int argc, char const** argv) {
  // Example:
  // ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
  // [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
  // Output:
  // [null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

  BrowserHistory browserHistory("leetcode.com");
  browserHistory.visit("google.com");
  browserHistory.visit("facebook.com");
  browserHistory.visit("youtube.com");

  std::cout << "back(1): " << browserHistory.back(1)
            << " expected: facebook.com" << std::endl;
  std::cout << "back(1): " << browserHistory.back(1) << " expected: google.com"
            << std::endl;
  std::cout << "forward(1): " << browserHistory.forward(1)
            << " expected: facebook.com" << std::endl;

  browserHistory.visit("linkedin.com");

  std::cout << "forward(2): " << browserHistory.forward(2)
            << " expected: linkedin.com" << std::endl;
  std::cout << "back(2): " << browserHistory.back(2) << " expected: google.com"
            << std::endl;
  std::cout << "back(7): " << browserHistory.back(7)
            << " expected: leetcode.com" << std::endl;

  return 0;
}
