class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m1;        map<char,int> m2;
        for(auto i:s)m1[i]++;
        for(auto i:t)m2[i]++;
        int res=0;
        for(char ch='a';ch<='z';ch++){
            res=res+abs(m1[ch]-m2[ch]);
        }
        return res;
    }
};