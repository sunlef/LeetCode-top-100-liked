// https://leetcode.cn/problems/linked-list-cycle-ii

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
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    do {
      if (!fast || !fast->next) {
        return nullptr;
      }

      fast = fast->next->next;
      slow = slow->next;
    } while (slow != fast);

    while (head != slow) {
      head = head->next;
      slow = slow->next;
    }
    return head;
  }
};