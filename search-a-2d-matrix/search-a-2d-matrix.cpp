class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int left=0,right=matrix.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(matrix[mid][0]==target)
                return true;
            if(matrix[mid][0]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        if(left==0)
            left=left;
        else
            left--;
        // cout<<left-1<<endl;
        return binary_search(matrix[left].begin(),matrix[left].end(),target);
    }
};