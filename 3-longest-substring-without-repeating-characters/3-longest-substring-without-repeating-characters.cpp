class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()==0)
            return 0;
        
        int i=0,j=1,lenOfWindow=1;
        map<char,int> m;
        m[s[0]]++;
        while(j<s.size())
        {
            m[s[j]]++;
            
            if(m[s[j]]>1)
            {
                while(true)
                {
                    if(m[s[j]]==1)
                        break;
                    
                    m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                                 
                    i++;
                }
            }
          lenOfWindow=max(lenOfWindow,int(m.size()));     
            j++;
        }
        return lenOfWindow;
    }
};