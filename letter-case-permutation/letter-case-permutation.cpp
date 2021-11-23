class Solution {
public:
    void permute(string s,int ind,vector<string> &res)
    {
        if(ind<0)
       {
            res.push_back(s);
            return;
        }
        if(s[ind]>='a'&&s[ind]<='z'||s[ind]>='A'&&s[ind]<='Z')
        {
            string temp=s;
            if(temp[ind]>='a'&&temp[ind]<='z')
                temp[ind]=temp[ind]-32;
            else
                temp[ind]+=32;
            permute(temp,ind-1,res);
            permute(s,ind-1,res);
        }
        else
        permute(s,ind-1,res);
    }
    
    vector<string> letterCasePermutation(string s) {
            vector<string> res;
            permute(s,s.length()-1,res);
        return res;
    }
};