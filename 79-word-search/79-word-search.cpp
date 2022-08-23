class Solution {
public:
    bool solve(vector<vector<char>>& board,int i,int j,string w,int pos,map<pair<int,int>,int> &vis){
        // cout<<i<<" "<<j<<" "<<pos<<endl;
        if(pos==w.size()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[{i,j}] || board[i][j]!=w[pos])
            return false;
        vis[{i,j}]=1;
        bool a=solve(board,i,j+1,w,pos+1,vis);
        bool b=solve(board,i+1,j,w,pos+1,vis);
        bool c=solve(board,i-1,j,w,pos+1,vis);
        bool d=solve(board,i,j-1,w,pos+1,vis);
        vis[{i,j}]=0;
        return a||b||c||d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        map<pair<int,int>,int> vis;
        bool res=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0])
                    res=res | solve(board,i,j, word,0,vis);
            }
        }
        return res;
    }
};