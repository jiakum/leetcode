
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
        ListNode* mergesort(ListNode *left, ListNode *right) {
            ListNode *last = NULL, *head, *next;
            if(left->val < right->val) {
                head = left;
                left = left->next;
            } else {
                head = right;
                right = right->next;
            }
            last = head;
            while(left && right) {
                if(left->val < right->val) {
                    next = left->next;
                    last->next = left;
                    left = next;
                } else {
                    next = right->next;
                    last->next = right;
                    right = next;
                }

                last = last->next;
            }

            if(left) {
                last->next = left;
            } else if(right) {
                last->next = right;
            }

            return head;
        }
        ListNode* sortList(ListNode* head) {
            if(head == NULL)
                return NULL;

            vector<ListNode*> scan, back;
            while(head) {
                ListNode * next = head->next;

                head->next = NULL;
                back.push_back(head);
                head = next;
            }

            while(back.size() > 1) {
                scan = back;
                back.clear();
                for(int i = 0;i < scan.size() - 1;i += 2) {
                    head = mergesort(scan[i], scan[i + 1]);
                    back.push_back(head);
                }

                if(scan.size() & 0x01) {
                    back.push_back(scan.back());
                }
            }

            return back[0];
        }
};
