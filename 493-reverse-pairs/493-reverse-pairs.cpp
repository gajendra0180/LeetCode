class Solution {
public:
    int ress=0;
    vector<int>merge(vector<int>&a,vector<int>&b){
        vector<int>res;
        int left=0,right=0;
        while(left<a.size() && right<b.size()){
            if(a[left]/2.0>b[right]){
                ress+=a.size()-left;
                right++;
            }
            else
            {
                left++;
            }
        }
        left=0,right=0;
        while(left<a.size() && right<b.size()){
            if(a[left]<=b[right]){
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

    int reversePairs(vector<int>& nums) {
        vector<int> t = mergeSort(nums,0,nums.size());
        return ress;

    }
};