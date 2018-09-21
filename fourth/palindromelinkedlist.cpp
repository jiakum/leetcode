
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
        bool isPalindrome(ListNode* head) {
            vector<int> vi;

            while(head) {
                vi.push_back(head->val);
                head = head->next;
            }

            int size = vi.size();
            for(int i = 0;i < size / 2;i++) {
                if(vi[i] != vi[size - i - 1])
                    return false;
            }

            return true;
        }
};
