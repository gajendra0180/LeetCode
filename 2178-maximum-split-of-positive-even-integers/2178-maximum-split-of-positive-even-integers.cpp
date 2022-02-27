class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0)return {};
        if(finalSum==2||finalSum==4)
            return {finalSum};
        vector<long long>res;
        long long i = 2;
        while(true){
            finalSum=finalSum-i;
            res.push_back(i);
            i+=2;
            if(finalSum-i<=i){
                res.push_back(finalSum);
                break;
            }
        }
        return res;
    }
};