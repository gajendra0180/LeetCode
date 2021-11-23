class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<deque<char>,int>m;
        if(s.length()<=10)
            return {};
        deque<char> dq;
        for(int i=0;i<10;i++)
            dq.push_back(s[i]);
        m[dq]++;
        int j=10;
        while(j<s.length())
        {
            dq.pop_front();
            dq.push_back(s[j]);
            m[dq]++;
            j++;
        }
        vector<string> res;
        for(auto i:m)
        {
            if(i.second>1)
            {
                string temp;
                for(auto j:i.first)
                    temp.push_back(j);
                res.push_back(temp);
            }
        }
        return res;
    }
};