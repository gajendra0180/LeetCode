class Solution {
public:
    set<string> st;
void get(string &s, char prev, int index, string &res, map<char, int> &isDone)
{
	if (index == s.size())
	{
		// prn(res);
		st.insert(res);
		return;
	}
	for (char i = '1'; i <= '9'; i++)
	{
		if (isDone[i])
			continue;
		if (s[index] == 'I' && !isDone[i])
		{
			// le skte h?
			if (i > prev)
			{
				res.push_back(i);
				isDone[i] = 1;
				get(s, i, index + 1, res, isDone);
				isDone[i] = 0;
				res.pop_back();
			}
			else
				continue;
		}
		else
		{
			if (i < prev && !isDone[i])
			{
				res.push_back(i);
				isDone[i] = 1;
				get(s, i, index + 1, res, isDone);
				isDone[i] = 0;
				res.pop_back();
			}
			else
				continue;
		}
	}
}
    string smallestNumber(string pattern) {
        string t = "", s = pattern;
        for (char i = '1'; i <= '9'; i++)
        {
            map<char, int> isDone;
            string res;
            res.push_back(i);
            isDone[i] = 1;
            get(s, i, 0, res, isDone);
        }
        return *st.begin();
    }
};