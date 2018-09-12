
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
        ListNode* rotateRight(ListNode* head, int k) {
            int i, j, n = 0, pos;
            ListNode *list = head;
            vector<ListNode *> vl;

            while(list) {
                vl.push_back(list);
                list = list->next;
                n++;
            }

            if(n == 0)
                return head;

            k = k % n;
            if(k == 0)
                return head;

            pos = n - k;
            head = vl[pos];
            list = head;
            for(i = 1;i < n;i++) {
                if(++pos >= n)
                    pos = 0;

                printf("pos:%d\n", pos);
                list->next = vl[pos];
                list = list->next;
            }

            list->next = NULL;

            return head;
        }
};
