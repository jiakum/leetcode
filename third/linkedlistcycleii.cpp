
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
        ListNode *detectCycle(ListNode *head) {
            ListNode *list = head;
            map<ListNode*, ListNode*> lmap;
            map<ListNode*, ListNode*>::iterator iter;

            while(list) {
                iter = lmap.find(list);
                if(iter != lmap.end())
                    return iter->second;

                lmap[list] = list;
                list = list->next;
            }

            return NULL;
        }
};
