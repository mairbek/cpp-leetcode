class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* result = head;
    ListNode* current = head;
    bool swap = false;
    while (current != nullptr && current->next != nullptr) {
      ListNode* nxt = current->next;
      if (prev != nullptr) {
        prev->next = nxt;
      }
      ListNode* tmp = nxt->next;
      nxt->next = current;
      current->next = tmp;
      prev = current;
      current = tmp;
      if (!swap) {
        result = nxt;
        swap = true;
      }
    }
    return result;
  }
};
