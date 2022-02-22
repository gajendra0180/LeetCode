class Solution {
public:
    vector<vector<string>>res;
    bool isSafe(vector<vector<string>>board,int r,int c){
    for(int i=r-1,j=c;i>=0;i--){
        if(board[i][j]=="Q")
            return false;
    }
    for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]=="Q")
            return false;
    }
    for(int i=r-1,j=c+1;i>=0&&j<board.size();i--,j++){
        if(board[i][j]=="Q")
            return false;
    }
    return true;
}
    
void print(int row,vector<vector<string>> board,string asf){
    if(row==board.size())
    {
        vector<string>t;
        for(auto i:board){
        string ress;
            for(auto j:i){
                // cout<<j<<" ";
                ress+=j;
            }
            t.push_back(ress);
            // cout<<endl;
        }
        res.push_back(t);
        return ;
    }
   for(int col=0;col<board.size();col++){
       if(isSafe(board,row,col)){
        board[row][col]="Q";
        print(row+1,board,asf+to_string(row)+to_string(col)+"_");
        board[row][col]=".";
       }
   }
}
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>v;
    for(int i=0;i<n;i++){
        vector<string>temp;
        for(int j=0;j<n;j++){
            temp.push_back(".");
        }
            v.push_back(temp);
    }
        print(0,v,"");
        return res;
    }
};