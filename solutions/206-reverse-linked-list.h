// https://leetcode.cn/problems/reverse-linked-list

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
  ListNode *reverseList(ListNode *head) {
    ListNode *f = nullptr;
    for (ListNode *x = head, *y; x != nullptr; f = x, x = y) {
      y = x->next;
      x->next = f;
    }
    return f;
  }
};