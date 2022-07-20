class Solution {
public:
    map<string,int> m;
//     return if s is a subsequence of t
     bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(j<t.size()&&i<s.size()){
            
            if(t[j]==s[i])
                i++;
            
            j++;
        }
        return i==s.size();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int res=0;
        for(auto i:words){
            if(m.find(i)!=m.end())
            {
                res+=m[i];
                continue;
            }
            if(isSubsequence(i,s)){
                res++;
                m[i]=1;
            }
            else
            {
                m[i]=0;
            }
        }
        return res;
    }
};