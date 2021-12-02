class Solution {
public:
    vector<int> getRow(int rowIndex) {
            vector<vector<int>> t;
        for(int i=0;i<rowIndex+1;i++)
        {
            vector<int> temp;
            for(int j=0;j<i+1;j++)
                temp.push_back(1);
            t.push_back(temp);
        }
        for(int i=0;i<rowIndex+1;i++)
        {
            for(int j=1;j<i;j++){
                t[i][j]=t[i-1][j-1]+t[i-1][j];
            }
        }
        // for(auto i:t)
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        return t[rowIndex];
    }
};


