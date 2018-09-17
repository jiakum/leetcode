
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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode *list = head, *next = NULL;

            while(list) {
                int val = list->val;
                next = list->next;

                if(next && next->val == val) {
                    while(next && next->val == val) {
                        ListNode * tmp = next->next;
                        delete next;
                        next = tmp;
                    }

                    list->next = next;
                    list = next;
                } else {
                    list = list->next;
                }
            }

            return head;
        }
};
