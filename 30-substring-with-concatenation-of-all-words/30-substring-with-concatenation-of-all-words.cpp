class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), w = words[0].size(), m = words.size();
        int j = 0;
        vector<int>res;
        unordered_map<string, int> pm;
        for (auto i : words)
            pm[i]++;
        for (int j = 0; j < n; j++)
        {
            int i = j;
            unordered_map<string, int> tm;
            bool check=true;
            while (i < j + w*m)
            {
                if(i+w>n)
                    break;
                string subs=s.substr(i,w);
                tm[subs]++;
                if(pm.find(subs)==pm.end()){
                    check=false;break;}
                // cout << s.substr(i, w) << " ";
                i = i + w;
            }
            if (check && tm == pm)
               res.push_back(j);
            // cout << endl;
        }
        return res;
    }
};