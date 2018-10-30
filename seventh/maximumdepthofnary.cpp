
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
        int traveal(Node *root, int depth) {
            if(root == NULL)
                return depth;

            depth++;
            vector<Node*> &vn = root->children;
            int i, size = vn.size(), ret = depth;
            for(i = 0;i < size;i++) {
                ret = max(ret, traveal(vn[i], depth));
            }

            return ret;
        }
        int maxDepth(Node* root) {
            return traveal(root, 0);
        }
};
