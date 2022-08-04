class Solution {
public:
 
    map<char,int> notation;
    vector<int>s;
    int getScore(string word){
        int res=0;
        for(auto i:word){
            res+=s[notation[i]];
        }
        return res;
    }
    
    bool canTake(string word,map<char,int>sc){
        map<char,int>temp;
        for(auto i:word)temp[i]++;
        for(auto i:temp){
            if(i.second>sc[i.first])
                return false;
        }
        return true;
    }
    
    int m(vector<string>&v,int index,map<char,int>sc){
        if(index==v.size())
            return 0;
        if(canTake(v[index],sc)){
            int a=m(v,index+1,sc);
            for(auto i:v[index]){
                sc[i]--;
            }
            int b=getScore(v[index])+m(v,index+1,sc);
            return max(a,b);
        }
        else
            return m(v,index+1,sc);
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        s=score;
        map<char,int>mp;
        for(auto i:letters)mp[i]++;
        int index=0;
        for(char ch='a';ch<='z';ch++){
            notation[ch]=index;index++;
        }
        return m(words,0,mp);
    }
};