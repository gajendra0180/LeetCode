class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        vector<int>v;
        for(auto i:nums)s.insert(i);
        for(auto i:s){
            v.push_back(i);
        }
        int i=0,cs=0,ms=0;
        while(i<v.size())
        {
            cs=1;
            while(i<v.size()-1&&v[i+1]==v[i]+1){
                cs++;
                i++;
            }        
            i++;
            ms=max(ms,cs);
        }
        return ms;
    }
};


