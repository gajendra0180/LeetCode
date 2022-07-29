class Solution {
public:
    string getPatternINT(string s){
          map<char,int>m;
          int c=0;
        string patternINT;
         for(auto i:s){
            if(m.find(i)==m.end())
            {   
                m[i]=c;
                c++;
            }
            patternINT=patternINT+(to_string(m[i]));
        }
        return patternINT;
}
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      vector<string>res;
        string p=getPatternINT(pattern);
        for(auto i:words){
            string p1=getPatternINT(i);
            if(p==p1)
                res.push_back(i);
        }
    return res;
    }
};