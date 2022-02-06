class Solution {
public:
    long long smallestNumber(long long num) {
        if(num>0){
             vector<int> v;
            bool checkZero=false;
            while(num){
                v.push_back(num%10);
                if(num%10==0)checkZero=true;
                num/=10;
            }
            sort(v.begin(),v.end(),greater<int>());
            int pos=v.size()-1;
            while(v[pos]==0&&pos>0)pos--;
            if(checkZero==true)swap(v[v.size()-1],v[pos]);
            long long res=0;
            for(int i=0;i<v.size();i++){
                res=res+v[i]*pow(10,i);
            }
            return res;
        }
        else
        {
            vector<int> v;
            num=abs(num);
             while(num){
                v.push_back(num%10);
                num/=10;
            }
             sort(v.begin(),v.end());
            long long res=0;
            for(int i=0;i<v.size();i++){
                res=res+v[i]*pow(10,i);
            }
            return -res;
        }
    }
};