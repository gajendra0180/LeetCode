class Solution {
public:
    vector<int>merge(vector<int>&a,vector<int>&b){
        vector<int>res;
        int left=0,right=0;
        while(left<a.size() && right<b.size()){
            if(a[left]<b[right]){
                res.push_back(a[left]);
                left++;
            }
            else
            {
                res.push_back(b[right]);
                right++;
            }
        }
        while(left<a.size())
        {
            res.push_back(a[left]);
            left++;
        }
        while(right<b.size())
        {
            res.push_back(b[right]);
            right++;
        }
        return res;
    }
    vector<int> mergeSort(vector<int>&nums,int left,int right){
      if(left==right-1){
          return {nums[left]};
      }
      vector<int> leftt =  mergeSort(nums,left,(left+right)/2);
      vector<int> rightt = mergeSort(nums,(left+right)/2,right);
      vector<int>merged = merge(leftt,rightt);
      return merged;
    }

    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums,0,nums.size());
    }
};  
