class Solution {
public:
    int arr[10001];
    bool can(vector<int>&nums,int i){
      if(i>=nums.size()-1)
          return true;
        
        // cout<<i<<endl;
        if(arr[i]!=-1)
            return arr[i];
        
        for(int j=i+1;j<=i+nums[i];j++){
            if(can(nums,j))
                return arr[j] =  true;
        }
        return arr[i] = false;
    }
    bool canJump(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));
        return can(nums,0);
    }
};