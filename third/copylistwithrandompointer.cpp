
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            map<RandomListNode *, RandomListNode*> rmap;
            RandomListNode *list, *orig = head, *result;

            if(head == NULL)
                return NULL;

            result = new RandomListNode(orig->label);
            list = result;
            rmap[orig] = list;

            while(orig->next) {
                RandomListNode * next = orig->next;
                list->next = new RandomListNode(next->label);

                list = list->next;
                orig = next;
                rmap[orig] = list;
            }

            orig = head;
            list = result;
            while(orig) {
                map<RandomListNode *, RandomListNode*>::iterator iter;
                if(orig->random) {
                    iter = rmap.find(orig->random);
                    list->random = iter->second;
                }
                orig = orig->next;
                list = list->next;
            }

            return result;
        }
};
