class Solution {
public:
    string decToBinary(int n)
{
   string s;
   int i = 0;
   while (n > 0)
   {

      s.push_back(n % 2 + '0');
      n = n / 2;
      i++;
   }

return s;
    }
   
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<s.length();i++){
            string temp;
            for(int j=i;j<i+k&&j<s.length();j++){
                temp.push_back(s[j]);
            }
                // cout<<temp<<endl;
                m[temp]=1;
        }
        for(int i=0;i<pow(2,k);i++){
            string t=decToBinary(i);
            while(t.length()!=k)
                t.push_back('0');
            if(m.find(t)==m.end())
                return false;
        }
        
        return true;
    }
};