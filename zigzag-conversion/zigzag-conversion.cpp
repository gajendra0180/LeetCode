class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        bool decreasing=false;
        vector<vector<char>>v;
        for(int i=0;i<numRows;i++)
        {
            vector<char> temp;
            for(int j=0;j<s.length();j++)
            {
              temp.push_back(' ');  
            }
            v.push_back(temp);
        }
        int row=0,col=0;
        for(auto i:s)
        {
            if(decreasing)
            {
                col++;
                v[row][col]=i;
                row--;
                if(row<=0)
                {decreasing=false;row=0;col++;}
            }
            else
            {
                v[row][col]=i;
                if(row==numRows-1)
                {
                    decreasing=true;row--;
                }
                else
                    row++;
                if(row==0)
                {
                    decreasing=false;col++;
                }
            }
        }
        string res;
        for(auto i:v)
        {
            for(auto j:i)
            {
                // cout<<j<<" ";
                if(j!=' ')
                res.push_back(j);
            }
            // cout<<endl;
        }
        return res;
    }
};