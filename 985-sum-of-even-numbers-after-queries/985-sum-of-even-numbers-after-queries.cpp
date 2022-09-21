class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(auto i:nums){
            if(i%2==0)
                sum+=i;
        }
        vector<int>res;
        for(auto i:queries){
            // for(auto i:res)cout<<i<<" ";
            // cout<<endl;            cout<<endl;
            int index=i[1];
            int val=i[0];
            // cout<<val<<" "<<nums[index]<<endl;
            if(nums[index]%2==0 && (val+nums[index])%2!=0){
                sum-=nums[index];   
            }
            else if((val+nums[index])%2==0)
            {
                // cout<<"Reaching"<<endl;
                if(nums[index]%2!=0)
                    sum+=nums[index]+val;
                else
                    sum+=val;
                // cout<<sum<<endl;
            }
            nums[index]=val+nums[index];
            res.push_back(sum);
        }
        // for(auto i:res)cout<<i<<" ";
        // cout<<endl;
        return res;
    }
};