class Solution {
public:
    
   // subarray having sum k
int lenOfLongSubarr(vector<int> A, int N, int K)
{
 
    int i = 0, j = 0, sum = 0;
    int maxLen = INT_MIN;
   
    while (j < N) {
        sum += A[j];
        if (sum < K) {
            j++;
        }
        else if (sum == K) {
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else if (sum > K) {
            while (sum > K) {
                sum -= A[i];
                 i++;
            }
              if(sum == K){
              maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
    }
    return maxLen;
}
 
    
    int minOperations(vector<int>& nums, int x) {
        
        int s=0;
        for(auto i:nums)
            s+=i;
        int req=s-x;
        cout<<req<<endl;
        if(req<0)return -1;
        int res=lenOfLongSubarr(nums,nums.size(),req);
        if(res==INT_MIN)
            return -1;
        return nums.size()-res;
    }
};


