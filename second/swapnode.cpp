

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
        ListNode* swapPairs(ListNode* head) {
            ListNode *list = head, *next, *last, *pos;

            if(head == NULL || head->next == NULL)
                return head;

            pos = head->next;            
            next = pos->next;
            pos->next = head;
            head->next = next;

            last = head;
            list = next;
            head = pos;
            while(list) {
                if(list->next == NULL)
                    break;

                pos = list->next;            
                next = pos->next;
                last->next = pos;
                pos->next = list;
                list->next = next;

                last = list;
                list = next;
            }

            return head;
        }
};
