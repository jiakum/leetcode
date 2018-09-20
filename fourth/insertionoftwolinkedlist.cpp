
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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            map<ListNode *,ListNode *> lmap;
            ListNode *list = headA;

            while(list) {
                lmap[list] = list;
                list = list->next;
            }

            list = headB;
            while(list) {
                if(lmap.find(list) != lmap.end())
                    return list;
                list = list->next;
            }

            return NULL;
        }
};
