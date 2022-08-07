class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int>s;
        for(auto i:matrix){
            for(auto j:i)
                s.insert(j);
        }
        return *next(s.begin(),k-1);
    }
};