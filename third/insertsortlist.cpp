
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
        ListNode* insertionSortList(ListNode* head) {
            ListNode *result = head, *list = head;

            if(head == NULL)
                return NULL;

            list = list->next;
            result->next = NULL;
            while(list) {
                ListNode *pos = result, *next;
                if(result->val > list->val) {
                    pos = list->next;
                    list->next = result;
                    result = list;

                    list = pos;
                } else {
                    while(pos->next && pos->next->val < list->val) {
                        pos = pos->next;
                    }
                    next = pos->next;
                    pos->next = list;

                    pos = list->next;
                    list->next = next;
                    list = pos;
                }

            }

            return result;
        }
};
