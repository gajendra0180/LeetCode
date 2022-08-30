class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        map<int,vector<int>> m;
int k=0;
for (auto i  :matrix ) {
    m[k]=i;
    k++;
}
   int matsize=matrix.size()-1;
    for (int i = 0; i <= matsize; ++i) {
        for (int j = matsize; j >=0; j--) {
            matrix[i][matsize-j]=m[j][i];
        }
    }
    }
};