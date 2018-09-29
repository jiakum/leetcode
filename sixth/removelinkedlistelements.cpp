
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
        ListNode* removeElements(ListNode* head, int val) {
            ListNode *list = head, *last = NULL, *next;

            head = NULL;
            while(list) {
                if(list->val == val) {
                    next = list->next;
                    if(last) {
                        last->next = next;
                    }
                    delete list;

                    list = next;
                } else {
                    if(last == NULL)
                        head = list;
                    last = list;
                    list = list->next;
                }
            }

            return head;
        }
};
