/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    ListNode *mid = find_mid(head);
    ListNode *tail = reverseList(mid);

    bool returnB = true;
    ListNode *x = head, *y = tail;
    while (y) {
      returnB &= (x->val == y->val);
      x = x->next;
      y = y->next;
    }

    reverseList(tail);
    return returnB;
  }

  ListNode *find_mid(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow->next;
  };

  ListNode *reverseList(ListNode *head) {  // 206-reverse-linked-list
    ListNode *f = nullptr;
    for (ListNode *x = head, *y; x != nullptr; f = x, x = y) {
      y = x->next;
      x->next = f;
    }
    return f;
  }
};