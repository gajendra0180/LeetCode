/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void t(Node* root,map<int,vector<Node*>> &m,int depth)
    {
        if(root==NULL)
            return;
        m[depth].push_back(root);
        t(root->left,m,depth+1);
        t(root->right,m,depth+1);
    }
    Node* connect(Node* root) {
        map<int,vector<Node*>> m;
        t(root,m,0);
        
        for(auto &i:m)
        {
           for(int j=1;j<i.second.size();j++)
           {
               i.second[j-1]->next=i.second[j];
           }
        }
        
        return root;
    }
};