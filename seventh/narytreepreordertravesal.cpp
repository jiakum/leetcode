
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
 */
class Solution {
    public:
        void subTravesal(Node *root, vector<int> &result) {
            if(root == NULL)
                return;

            result.push_back(root->val);
            vector<Node*> &vn = root->children;
            int i, size = vn.size();
            for(i = 0;i < size;i++) {
                subTravesal(vn[i], result);
            }
        }
        vector<int> preorder(Node* root) {
            vector<int> result;

            subTravesal(root, result);

            return result;
        }
};
