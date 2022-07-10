class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0,right=matrix.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(matrix[mid][0]==target)
                {left=mid;
                break;}
            else if(matrix[mid][0]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        // cout<<left<<endl;
        if(matrix[left][0]>target)
            left--;
        if(left<0)return false;
        return binary_search(matrix[left].begin(),matrix[left].end(),target);
    }
};