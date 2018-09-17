
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
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            ListNode *list = head, *last = NULL, *next;
            ListNode *firsthalf, *first;
            int i = 0, j = 0;

            if(m == n)
                return head;

            while(++i < m) {
                last = list;
                list = list->next;
            }

            if(list == NULL)
                return head;

            firsthalf = last;
            first = list;
            last = list;
            list = list->next;
            while(++i <= n) {
                next = list->next;
                list->next = last;
                last = list;
                list = next;
            }

            first->next = list;
            if(firsthalf) {
                firsthalf->next = last;
            } else {
                head = last;
            }

            return head;
        }
};
