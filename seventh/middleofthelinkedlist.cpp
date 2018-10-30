
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
        ListNode* middleNode(ListNode* head) {
            ListNode *result = head, *list = head;

            while(list && list->next) {
                result = result->next;

                list = list->next->next;
            }

            return result;
        }
};
