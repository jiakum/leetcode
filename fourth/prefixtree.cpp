
class Trie {
    private:
#define PREFIX_TREE_CHILD (26)
#define PREFIX_TREE_NODE_VALID (1 << 31)
        struct priv_data {
            unsigned int c;
            unsigned int flag;
            struct priv_data *child[PREFIX_TREE_CHILD];
            priv_data(char ch) :c(ch), flag(0) {
                for(int i = 0;i < PREFIX_TREE_CHILD;i++)
                    child[i] = NULL;
            }
        };
        priv_data *root;
    public:
        /** Initialize your data structure here. */
        Trie() {
            root = new priv_data(0);
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            if(word.size() == 0)
                return;

            priv_data *node = root;
            for(int i = 0;i < word.size();i++) {
                char c = word[i];
                unsigned int index = c - 'a';
                if(index >= PREFIX_TREE_CHILD)
                    return;

                if(node->child[index] == NULL) {
                    node->child[index] = new priv_data(c);
                }
                node = node->child[index];
            }

            node->flag |= PREFIX_TREE_NODE_VALID;
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            priv_data *node = root;
            for(int i = 0;i < word.size();i++) {
                char c = word[i];
                unsigned int index = c - 'a';
                if(index >= PREFIX_TREE_CHILD)
                    return false;

                node = node->child[index];
                if(node == NULL) {
                    return false;
                }
            }

            return node->flag & PREFIX_TREE_NODE_VALID ? true: false;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            priv_data *node = root;
            for(int i = 0;i < prefix.size();i++) {
                char c = prefix[i];
                unsigned int index = c - 'a';
                if(index >= PREFIX_TREE_CHILD)
                    return false;

                node = node->child[index];
                if(node == NULL) {
                    return false;
                }
            }

            return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
