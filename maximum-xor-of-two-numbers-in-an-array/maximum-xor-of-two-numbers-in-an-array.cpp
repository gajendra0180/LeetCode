class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask=0,output=0;
        for(int i=31;i>=0;i--)
        {
            mask=mask|1<<i;
            set<int> found;
            for(auto i:nums)
                found.insert(i&mask);
            int temp=output|1<<i;
            for(auto i:found)
            {
                if(found.find(i^temp)!=found.end())
                    output=temp;
            }
        }
        return output;
    }
};