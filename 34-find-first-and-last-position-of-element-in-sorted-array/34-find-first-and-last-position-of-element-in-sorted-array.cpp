class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int left=0,right=nums.size()-1,bestLeft=-1,bestRight=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                bestLeft=mid;
                right=mid-1;
            }
            else if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        cout<<bestLeft<<endl;
        left=0,right=nums.size()-1;
        while(left<=right){
             int mid=(left+right)/2;
            if(nums[mid]==target){
                bestRight=mid;
                left=mid+1;
            }
            else if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        cout<<bestRight<<endl;
        if(bestLeft!=-1&&bestRight!=-1&&nums[bestLeft]==target&&nums[bestRight]==target)
            return {bestLeft,bestRight};
        else
            return {-1,-1};
    }
};