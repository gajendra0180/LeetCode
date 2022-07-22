class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>> v;
        for(int i=0;i<=rowIndex;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                temp.push_back(1);
            }
            v.push_back(temp);
        }
        for(int i=1;i<=rowIndex;i++){
            for(int j=1;j<i;j++){
                v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
        return v[rowIndex];
    }
};