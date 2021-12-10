class Solution {
public:
    bool condition(int mid,string s)
    {
        map<char,int> m;
        for(int i=0;i<mid;i++)
            m[s[i]]++;
        for(int i=0;i<s.length()-mid;i++)
        {
            if(m.size()==mid)
                return false;
            m[s[i]]--;
            if(m[s[i]]==0)
                m.erase(s[i]);
            m[s[i+mid]]++;
        }
          if(m.size()==mid)
            return false;
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        
        set<char>se;
        for(auto i:s)
            se.insert(i);
        
        if(s==" "||s.length()==1)
            return 1;
        
        int left=0,right=se.size()+1;
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(condition(mid,s))
                right=mid;
            else
                left=mid+1;
        }
        return max(0,left-1);
    }
};