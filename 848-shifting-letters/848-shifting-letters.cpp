class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int index=0;
        map<char,int>aplhabetMap;
        for(char ch='a';ch<='z';ch++){
            aplhabetMap[ch]=index;
            index++;
        }
        int sum=0;
        for(int i=shifts.size()-1;i>=0;i--){
            sum+=shifts[i]%26;
            shifts[i]=sum;
        }
        // for(auto i:shifts)cout<<i<<" ";
        // cout<<endl;
        string res;
        index=0;
        for(auto i:s){
            int ch=(i-97)%26;
            char c=(ch+shifts[index])%26+97;
            index++;
            // cout<<ch<<" "<<c<<endl;
            res.push_back(c);
        }
        return res;
    }
};