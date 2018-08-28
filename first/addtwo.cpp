
#include <stdlib.h>
#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            struct ListNode *node, *head, *last = NULL;
            int n, plus = 0; 

            while(1) {
                if(l1 == NULL && l2 == NULL)
                    break;

                if(l1 && l2) {
                    n = l1->val + l2->val + plus;
                    l1 = l1->next;
                    l2 = l2->next;
                } else if(l1) {
                    n = l1->val + plus;
                    l1 = l1->next;
                } else if(l2) {
                    n = l2->val + plus;
                    l2 = l2->next;
                }

                if(n >= 10) {
                    n -= 10;
                    plus = 1;
                } else {
                    plus = 0;
                }

                node = new ListNode(n);
                node->next = NULL;
                if(last) {
                    last->next = node;
                } else {
                    head = node;
                }

                last = node;
            }

            if(plus) {
                node = new ListNode(plus);
                node->next = NULL;
                last->next = node;
            }

            return head;
        }
};

int main(int argc, char **argv)
{
}
