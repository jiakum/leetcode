
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    public:
        UndirectedGraphNode *subClone(UndirectedGraphNode *node) {
            map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator iter;
            iter = umap.find(node);
            if(iter != umap.end())
                return iter->second;

            UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
            root->neighbors = node->neighbors;
            umap[node] = root;

            for(int i = 0;i < root->neighbors.size();i++) {
                UndirectedGraphNode *pos = root->neighbors[i];
                if(pos ) { 
                    if(pos == node) {
                        root->neighbors[i] = root;
                    } else {
                        root->neighbors[i] = subClone(pos);
                    }
                }
            }

            return root;
        }
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if(node == NULL)
                return node;

            umap.clear();
            return subClone(node);
        }
    private:
        map<UndirectedGraphNode*, UndirectedGraphNode*> umap;
};
