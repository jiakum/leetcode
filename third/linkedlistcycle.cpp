
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
        bool hasCycle(ListNode *head) {
            ListNode *list = head;
            map<ListNode *, ListNode *> lmap;

            while(list) {
                if(lmap.find(list) != lmap.end())
                    return true;

                lmap[list] = list;
                list = list->next;
            }

            return false;
        }
};
