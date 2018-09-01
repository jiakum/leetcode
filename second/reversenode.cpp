
class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(head == NULL || head->next == NULL || k <= 1)
                return head;

            ListNode *list = head, *next, *last, *pos[k];
            int i;

            for(i = 0;i < k;i++) {
                if(list)
                    pos[i] = list;
                else
                    return head;

                list = list->next;
            }                
            next = pos[k - 1]->next;
            for(i = k - 1;i > 0;i--) {
                pos[i]->next = pos[i - 1];
            }
            pos[0]->next = next;

            head = pos[k - 1];
            last = pos[0];
            list = next;
            while(list) {
                for(i = 0;i < k;i++) {
                    if(list)
                        pos[i] = list;
                    else
                        return head;

                    list = list->next;
                }  

                last->next = pos[k - 1];
                next = pos[k - 1]->next;
                for(i = k - 1;i > 0;i--) {
                    pos[i]->next = pos[i - 1];
                }
                pos[0]->next = next;

                last = pos[0];
                list = next;
            }

            return head;
        }
};
