
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
        ListNode* reverseRecursive(ListNode *head, ListNode *last) {
            ListNode *next = head->next;

            head->next = last;

            if(next) {
                return reverseRecursive(next, head);
            } else {
                return head;
            }
        }
        ListNode* reverseList(ListNode* head) {
            if(head == NULL)
                return NULL;

            return reverseRecursive(head, NULL);
        }
};
