
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *list, *head;

            if(l1 == NULL)
                return l2;
            if(l2 == NULL)
                return l1;

            if(l1->val > l2->val) {
                head = l2;
                l2 = l2->next;
            } else {
                head = l1;
                l1 = l1->next;
            }

            list = head;
            while(l1 && l2) {
                if(l1->val > l2->val) {
                    list->next = l2;
                    l2 = l2->next;
                } else {
                    list->next = l1;
                    l1 = l1->next;
                }

                list = list->next;
            }

            if(l1) {
                list->next = l1;
            }

            if(l2) {
                list->next = l2;
            }

            return head;
        }
};

int main(int argc, char **argv)
{
    Solution sol;

    

    return 0;
}
