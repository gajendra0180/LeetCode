class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& v, int time) {
        vector<int> dec,inc,res;
        dec.push_back(0);
        inc.push_back(0);
        int c=0;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<=v[i-1])
                c++;
            else
                c=0;
            dec.push_back(c);
        }
        c=0;
        for(int i=v.size()-1;i>0;i--)
        {
            if(v[i-1]<=v[i])
                c++;
            else
                c=0;
            inc.push_back(c);
        }
        reverse(inc.begin(),inc.end());
        for(auto i:dec)
            cout<<i;
        cout<<endl;
        for(auto i:inc)
            cout<<i;
        for(int i=0;i<v.size();i++)
        {
            if(inc[i]>=time&&dec[i]>=time)
                res.push_back(i);
        }
        return res;
    }
};