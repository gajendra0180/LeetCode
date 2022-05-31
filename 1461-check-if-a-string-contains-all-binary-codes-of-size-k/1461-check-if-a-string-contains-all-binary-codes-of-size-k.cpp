class Solution {
public:
   
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<s.length();i++){
            string temp;
            for(int j=i;j<i+k&&j<s.length();j++){
                temp.push_back(s[j]);
            }
                // cout<<temp<<endl;
                if(temp.size()==k)
                m[temp]=1;
        }
       
        cout<<m.size()<<endl;
        return m.size()==pow(2,k);
    }
};