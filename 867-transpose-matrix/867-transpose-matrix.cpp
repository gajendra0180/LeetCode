class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>v;
        for(int i=0;i<matrix[0].size();i++){
            vector<int>temp;
            for(int j=0;j<matrix.size();j++){
                temp.push_back(0);
            }
            v.push_back(temp);
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                v[j][i]=matrix[i][j];
            }
        }
        return v;
    }
};