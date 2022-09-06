class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>ms;
        vector<double>res;
        int i=0;
        for(i=0;i<k;i++)ms.insert(nums[i]);
        auto it=ms.begin();
        int temp=k/2;
        while(temp--)it++;
        auto tt=it;
        if(k%2==0)
            res.push_back((double(*it)+double(*(--tt)))/2);
        else
            res.push_back(*it);
        while(i<nums.size()){
               ms.insert(nums[i]);
            if(nums[i]<*it)
                it--;
            if(nums[i-k]<=*it)
                it++;
            auto itr = ms.find(nums[i-k]);
            if(itr!=ms.end())ms.erase(itr);
            i++;
            auto tte=it;
            if(k%2==0)
                res.push_back((double(*it)+double(*(--tte)))/2);
            else
                res.push_back(*it);
        }
        return res;
    }
};
