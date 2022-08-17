class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string prev=countAndSay(n-1);
        int i=0;
        string res;
        while(i<prev.size()){
            int j=i+1;
            while(j<prev.size()&&prev[j]==prev[i])
                j++;
            int diff=j-i;
            res.push_back(diff+'0');
            res.push_back(prev[i]);
            i=j;
        }
        return res;
    }
};

    // 1
    // 11
    // 21
    // 1211
    // 111221