class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        vector<long long int> prefix{beans.back()};
        long long int s=beans.back();
        for(int i=beans.size()-2;i>=0;i--){
            s+=beans[i];
            prefix.push_back(s);
        }
        reverse(prefix.begin(),prefix.end());
        long long int fs=0;
        set<long long int> res;
        for(int i=0;i<beans.size()-1;i++)
        {
            res.insert(fs+prefix[i+1]-(beans.size()-(i+1))*beans[i]);
            fs+=beans[i];
        }
        res.insert(fs);
        return *res.begin();
    }
};