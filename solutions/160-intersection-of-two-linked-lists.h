// https://leetcode.cn/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto x = headA, y = headB;

    while (x != y) {
      x = (x == nullptr) ? headB : x->next;
      y = (y == nullptr) ? headA : y->next;
    }

    return x;
  }
};