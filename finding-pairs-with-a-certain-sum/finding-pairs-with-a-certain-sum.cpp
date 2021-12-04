class FindSumPairs {
public:
    unordered_map<int,int> m;
    vector<int>second;
    vector<int> first;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        first=nums1;
        sort(first.begin(),first.end());
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
           if(i>tot)
               break;
           int target=tot-i;
           res=res+m[target];
       }
        return res;
    }
};

