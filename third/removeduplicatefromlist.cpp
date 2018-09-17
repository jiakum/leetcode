
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
            ListNode *list = head, *next = NULL, *last = NULL;

            while(list) {
                int val = list->val;
                next = list->next;

                if(next && next->val == val) {
                    printf("val:%d\n", val);
                    while(list && list->val == val) {
                        next = list->next;
                        delete list;
                        list = next;
                    }

                    if(last) {
                        last->next = list;
                    } else {
                        head = list;
                    }
                } else {
                    last = list;
                    list = list->next;
                }
            }

            return head;
        }
};
