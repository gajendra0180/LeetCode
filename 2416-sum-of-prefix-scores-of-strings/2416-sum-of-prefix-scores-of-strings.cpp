class Node{
    public:
        int count;
        char character;
        vector<Node*>child;
        Node(char ch,int c){
            character=ch;
            count=c;
        }
};
class Solution {
public:
     Node* root= new Node('#',0);
    void buildTrie(Node* root,string word){
        Node* currNode=root;
        for(auto ch:word){
//      Iterating all the child nodes of the curr node
            bool found=false;
            for(auto childNode:currNode->child){
                if(childNode->character==ch){
                    currNode=childNode;
                    currNode->count++;
                    found=true;
                    break;
                }
            }
            if(found==false){
                Node* newChild= new Node(ch,1);
                currNode->child.push_back(newChild);
                currNode=currNode->child.back();
            }
        }
    }
    int dfs(Node* root,string word){
        Node* currNode=root;
        int res=0;
        for(auto ch:word){
            for(auto childNode:currNode->child){
                if(childNode->character==ch){
                    res+=childNode->count;
                    currNode=childNode;
                    break;
                }
            }
        }
        return res;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto i:words){
            buildTrie(root,i);
        }
        vector<int>res;
        for(auto i:words){
            res.push_back(dfs(root,i));
        }
        return res;
    }
};