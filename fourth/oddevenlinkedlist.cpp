
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
        ListNode* oddEvenList(ListNode* head) {
            ListNode *list = head, *even, *odd = head, *evenstart;
            bool isodd = true;

            if(head == NULL || head->next == NULL)
                return head;

            evenstart = even = head->next;
            list = even->next;
            while(list) {
                if(isodd) {
                    odd->next = list;
                    odd = list;
                } else {
                    even->next = list;
                    even = list;
                }

                list = list->next;
                isodd = !isodd;
            }

            even->next = NULL;
            odd->next = evenstart;

            return head;
        }
};
