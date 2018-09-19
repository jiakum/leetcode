
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
        void reorderList(ListNode* head) {
            vector<ListNode*> vl;
            ListNode *list = head, *next, *last = NULL;

            while(list) {
                vl.push_back(list);

                list = list->next;
            }

            int n = vl.size(), i;
            if(n <= 2)
                return;

            for(i = 0;i < n / 2;i++) {
                list = vl[i];
                next = vl[n - i - 1];

                if(last) {
                    last->next = list;
                }
                list->next = next;
                last = next;
            }

            if(n & 0x01) {
                next->next = vl[n / 2];
                next = next->next;
            }
            next->next = NULL;
        }
};
