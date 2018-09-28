
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    public:

        void scan_tree(TreeNode * root, queue<TreeNode*> &data) {
            if(root == NULL)
                return;

            data.push(root->left);
            data.push(root->right);

            scan_tree(root->left, data);
            scan_tree(root->right, data);
        }
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            queue<TreeNode*> data;

            data.push(root);
            scan_tree(root, data);

            string result;
            char num[16];
            result.push_back('[');

            while(!data.empty()) {
                root = data.front();
                data.pop();

                if(root)
                    snprintf(num, sizeof(num), "%d,", root->val);
                else
                    snprintf(num, sizeof(num), "null,");
                result.append(num);
            }

            result.pop_back(); /* remove the last ',' */
            result.push_back(']');

            return result;
        }

        void constructTree(queue<TreeNode*> &data, TreeNode *root) {
            if(root == NULL || data.empty())
                return;

            TreeNode *node;
            node = data.front();
            data.pop();
            root->left = node;

            if(data.empty())
                return;

            node = data.front();
            data.pop();
            root->right = node;

            constructTree(data, root->left);
            constructTree(data, root->right);

            return;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string s) {
            int i, size = s.size();
            const char *ptr = s.c_str();
            queue<TreeNode*> data;
            TreeNode *root;
            string num;

            for(i = 1;i < size;) {
                num.clear();    
                while(s[i] != ',' && s[i] != ']') {
                    num.push_back(s[i]);
                    i++;
                }
                i++;

                if(num == "null") {
                    root = NULL;
                } else {
                    root = new TreeNode(strtol(num.c_str(), NULL, 0));
                }

                data.push(root);
            }

            root = data.front();
            data.pop();

            constructTree(data, root);

            return root;
        }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
