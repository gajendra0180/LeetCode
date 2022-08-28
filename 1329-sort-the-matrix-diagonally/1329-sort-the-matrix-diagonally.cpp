class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0;i<mat[0].size();i++){
            int x=0,y=i;
            vector<int>temp;
            while(true){
                if(x>=mat.size() || y>=mat[0].size())
                    break;
                temp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x=0,y=i;int c=0;
            while(true){
                if(x>=mat.size() || y>=mat[0].size())
                    break;
                mat[x][y]=temp[c];
                x++;
                y++;
                c++;
            }
            for(int i=0;i<mat.size();i++){
                int x=i,y=0;
                vector<int>temp;
                while(true){
                if(x>=mat.size() || y>=mat[0].size())
                    break;
                    temp.push_back(mat[x][y]);
                    x++;y++;
                }
                sort(temp.begin(),temp.end());
                x=i,y=0;int c=0;
                while(true){
                    if(x>=mat.size() || y>=mat[0].size())
                        break;
                    mat[x][y]=temp[c];
                    x++;
                    y++;
                    c++;
                }
            }
        }
        return mat;
    }
};
