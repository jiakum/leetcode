
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

static void heap_sort(int data[], int n)
{
    int i,j,k,r,l;

    l = ((n-1)>>1) + 1; r = n - 1;

    while(1) {
        if(l > 0) {
            l -= 1;
            k = data[l];
        } else if(r > 0) {
            k = data[r];
            data[r] = data[l];
            data[l] = k;
            r--;
        } else
            break;

        i = l; j = i << 1;
        while(j < r) {
            if(data[j] < data[j+1])
                j += 1;
            if(data[j] <= k)
                break;
            data[i] = data[j];
            i = j; j <<= 1;
        }
        if((j == r) && (data[j] > k)) {
            data[i] = data[j];
            i = j;
        }
        data[i] = k;
    }
}

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode *head = NULL, *node = NULL;
            int n = 0, i;

            for(i = 0;i < (int)lists.size();i++) {
                ListNode *pos = lists[i];
                if(pos) {
                    if(node) {
                        node->next = pos;
                        node = pos;
                    } else {
                        node = pos;
                        head = pos;
                    }
                    n++;
                } else
                    continue;

                while(pos->next) {

                    pos = pos->next;
                    n++;
                }

                node = pos;
            }

            if(n == 0)
                return NULL;

            node->next = NULL;
            int data[n];

            node = head;
            for(i = 0;i < n;i++) {
                data[i] = node->val;
                node = node->next;
            }

            heap_sort(data, n);

            node = head;
            for(i = 0;i < n;i++) {
                node->val = data[i];
                node = node->next;
            }

            return head;
        }
};

int main(int argc, char **argv)
{
    Solution sol;

    

    return 0;
}
