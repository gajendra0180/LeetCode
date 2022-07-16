class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(auto i:s)
            m[i]++;
        int res=0;
        int found=0;
        for(auto i:m){
            if(i.second%2!=0){
                if(found!=0)
                {
                    res+=i.second-1;
                }
                else
                {
                    res+=i.second;
                    found=1;
                }
            }
            else
            {
                res+=i.second;
            }
        }
        return res;
    }
};