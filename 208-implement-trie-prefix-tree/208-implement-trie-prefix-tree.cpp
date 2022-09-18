class Node{
    public:
        char val;
        int count;
        vector<Node*>child;
        Node(char x,int y){
            val=x;
            count=y;
        }
};
class Trie {
public:
    Node* root = new Node('#',0);
    map<string,int> m;
    Trie() {
    }
    void dfs(Node* root,string word){
        Node* curr=root;
        for(auto i:word){
            bool found = false;
            for(auto c:curr->child){
                if(c->val==i){
                    c->count=c->count+1;
                    found=true;
                    curr=c;
                    break;
                }
            }
            if(found==false){
                curr->child.push_back(new Node(i,1));
                curr=curr->child.back();
            }
        }
    }
    void insert(string word) {
       dfs(root,word);
        m[word]=1;
    }
    
    bool search(string word) {
        return m.find(word)!=m.end();
    }
    
    bool startsWith(string prefix) {
            Node* curr = root;
        for(auto i:prefix){
            bool found=false;
            for(auto c:curr->child){
                if(c->val==i)
                {
                    curr=c;
                    found=true;
                    break;
                }
            }
            if(found==false)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */