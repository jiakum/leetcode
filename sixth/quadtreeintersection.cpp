
/*
// Definition for a QuadTree node.
class Node {
public:
bool val;
bool isLeaf;
Node* topLeft;
Node* topRight;
Node* bottomLeft;
Node* bottomRight;

Node() {}

Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
val = _val;
isLeaf = _isLeaf;
topLeft = _topLeft;
topRight = _topRight;
bottomLeft = _bottomLeft;
bottomRight = _bottomRight;
}
};
 */
class Solution {
    private:
        pair<bool,bool> combine(Node* qt){
            if (qt == nullptr) return make_pair(true,true);
            if (qt->isLeaf) return make_pair(qt->val,true);
            bool uniform = true;
            pair<bool,bool> tr,tl,br,bl;
            tr = combine(qt->topRight);
            tl = combine(qt->topLeft);
            br = combine(qt->bottomRight);
            bl = combine(qt->bottomLeft);
            uniform = (tr.second && tl.second) && (br.second && bl.second) && (tr.second && bl.second);
            if (uniform && (((tr.first == tl.first) && (br.first == bl.first)) && (tr.first == bl.first))) {
                qt->topLeft = qt->topRight = qt->bottomLeft = qt->bottomRight = nullptr;
                qt->val = tr.first;
                qt->isLeaf = true;
                return make_pair(tr.first,true);
            }
            else return make_pair(tr.first,false);
        }
    public:
        Node* intersect(Node* quadTree1, Node* quadTree2) {
            if (quadTree1 == nullptr) return quadTree2;
            if (quadTree2 == nullptr) return quadTree1;
            if (quadTree1->isLeaf){
                if (quadTree1->val == true) return quadTree1;
                combine(quadTree2);
                return quadTree2;
            }
            if (quadTree2->isLeaf) return intersect(quadTree2,quadTree1);
            quadTree1->topLeft = intersect(quadTree1->topLeft,quadTree2->topLeft);
            quadTree1->topRight = intersect(quadTree1->topRight,quadTree2->topRight);
            quadTree1->bottomLeft = intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
            quadTree1->bottomRight = intersect(quadTree1->bottomRight,quadTree2->bottomRight);
            combine(quadTree1);
            return quadTree1;
        }
};
