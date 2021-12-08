class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        bool ans=false;
        for(int i=0;i<matrix.size();i++)
        {
            ans=binary_search(matrix[i].begin(),matrix[i].end(),target);
            
            if(ans==true)
                return ans;
        }
        return ans;
    }
};