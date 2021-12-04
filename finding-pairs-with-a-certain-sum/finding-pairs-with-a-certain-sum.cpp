class FindSumPairs {
public:
    map<int,int> m;
    vector<int>second;
    vector<int> first;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        first=nums1;
        
        for(int i=0;i<100005;i++)
            second.push_back(0);
        
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]]++;
            second[i]=nums2[i];
        }
    }
    
    void add(int index, int val) {
        int prev=second[index];
        int new_num=prev+val;
        second[index]=new_num;
        
        if(prev!=0)
            m[prev]--;
        
        m[new_num]++;
    }
    int count(int tot) {
        int res=0;
       for(auto i:first)
       {
           int target=tot-i;
           res=res+m[target];
       }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */