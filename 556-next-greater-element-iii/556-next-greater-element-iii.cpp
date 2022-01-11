class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>digits;
        int temp=n;
        while(temp>0)
        {
            digits.push_back(temp%10);
            temp=temp/10;
        }
        bool ans=false;
        int i=1;
        for(i=1;i<digits.size();i++)
        {
            if(digits[i]<digits[i-1])
            {ans=true;break;}
        }
        if(ans)
        {
            int minn=digits[i-1],pos=i-1;
            for(int j=i;j>=0;j--)
            {
                if(digits[j]>digits[i])
                {
                    if(digits[j]<minn)
                    {
                        pos=j;
                        minn=digits[j];
                    }
                }
            }
            swap(digits[i],digits[pos]); 
            for(auto i:digits)
                cout<<i<<" ";
            cout<<endl;
            cout<<i<<" "<<pos<<endl;
            sort(digits.begin(),digits.begin()+i,greater<int>());
            for(auto i:digits)
                cout<<i<<" ";
            cout<<endl;
            long long int res=0;
            reverse(digits.begin(),digits.end());
            for(int i=0;i<digits.size();i++){
                cout<<digits[i]<<" "; 
                res=res*10+digits[i];    
            }
            if(res>INT_MAX)
                return -1;
            return res;
        }
        else
            return -1;
    }
};

