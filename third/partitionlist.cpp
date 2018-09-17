
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
        ListNode* partition(ListNode* head, int x) {
            ListNode *lesser = NULL , *bigger = NULL, *list = head;
            ListNode *lhead = NULL, *bhead = NULL;

            while(list) {
                if(list->val < x) {
                    if(lesser) {
                        lesser->next = list;
                    } else {
                        lhead = list;
                    }

                    lesser = list;
                } else {
                    if(bigger) {
                        bigger->next = list;
                    } else {
                        bhead = list;
                    }

                    bigger = list;
                }

                list = list->next;
            }

            if(lesser) {
                lesser->next = bhead;
                head = lhead;
            } else {
                head = bhead;
            }

            if(bigger)
                bigger->next = NULL;

            return head;
        }
};
