class Solution {
public:
    
    int finder(int target, vector<int>&nums, int left, int right){
        
        int ans = -1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target){
                ans = mid;
                break;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
            
            
        }
        
        return ans;
        
        
    }
    int search(vector<int>& nums, int target) {
//         case when len is 1 done
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            return -1;
        }
//         already normal sorted 
        if(nums[0]<=nums.back()){
            
            return finder(target,nums,0,nums.size()-1);
            
            
        }
        
        else{
            
            
            int left = 0;
            int right = nums.size()-1;
            int pivot = -1;
            while(left<=right){
                
                int mid = left+(right-left)/2;
                if(mid>0 && nums[mid-1]>nums[mid]){
                    pivot = mid;
                    break;
                }
                if(nums[0]<=nums[mid]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
                
            }
            
          
            int case1 = finder(target,nums,0,pivot-1);
            int case2 = finder(target,nums,pivot,nums.size()-1);
            if(case1!=-1){
                return case1;
            }
            else if(case2!=-1){
                return case2;
            }
            return -1;
            
            
        }
        
        return -1;
        
    }
};