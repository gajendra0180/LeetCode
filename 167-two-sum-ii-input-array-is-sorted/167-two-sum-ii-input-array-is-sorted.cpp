class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int i=0,j=v.size()-1;
        while(i<j){
            if(v[i]+v[j]==target)
                return {i+1,j+1};
            else if(v[i]+v[j]>target)
                    j--;
            else
                i++;
        }
        return {-1,-1};
    }
};