class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> v=answers;
        map<int, int> m;
    int res = 0;
    for (auto i : v)
    {
        if (m.find(i) == m.end())
        {
            res = res + i + 1;
            if (i != 0)
                m[i]+= i;
        }
        else
        {
            m[i]--;
            if (m[i] == 0)
                m.erase(i);
        }
    }
        return res;
    }
};