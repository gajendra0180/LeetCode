class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            bool b=binary_search(matrix[i].begin(),matrix[i].end(),target);
            if(b)
                return true;
        }
        return false;
    }
};