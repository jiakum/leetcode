
/*
// Definition for a Node.
class Node {
public:
int val = NULL;
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
        vector<vector<int>> levelOrder(Node* root) {
            vector<vector<int>> result;
            if(root == NULL)
                return result;

            vector<Node*> history;
            history.push_back(root); 

            while(!history.empty()) {
                vector<Node*> next;
                vector<int> vi;

                for(int j = 0;j < history.size();j++){
                    root = history[j];
                    vi.push_back(root->val);

                    vector<Node*> &vn = root->children;
                    for(int i = 0;i < vn.size();i++) {
                        Node* n = vn[i];
                        if(n != NULL)
                            next.push_back(n);
                    }

                }

                history = next;
                result.push_back(vi);
            }

            return result;
        }
};
