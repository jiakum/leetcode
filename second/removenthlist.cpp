
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *list = head, *last = head, *tobedel = head;
            int i = 0;

            if(n == 0)
                return head;

            for(i = 0;i < n;i++) {
                if(list)
                    list = list->next;
                else 
                    break;
            }

            if(list == NULL) {
                list = head->next;
                delete head;

                return list;
            }

            tobedel = head;
            last = head;
            while(list) {


                list = list->next;
                last = tobedel;
                tobedel = tobedel->next;
            }

            last->next = tobedel->next;
            delete tobedel;

            return head;
        }
};

int main(int argc, char **argv)
{
    Solution sol;

    

    return 0;
}
