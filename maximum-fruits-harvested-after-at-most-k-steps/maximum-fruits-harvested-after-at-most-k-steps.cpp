
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& v, int startPos, int k) {
        unordered_map<int,int> m;
        for(auto i:v)m[i[0]]=i[1];
         int sum1=m[startPos];
        for(int i=startPos+1;i<=k+startPos;i++)
            sum1+=m[i];
         int res=sum1;
        int left=startPos-1,right=startPos+k;
        while(left>=0&&left<right)
        {
            res=max(res,sum1);
            sum1-=m[right];
            right--;
            sum1-=m[right];
            right--;
            sum1+=m[left];
            left--;
        }
            res=max(res,sum1);
            sum1=m[startPos],left=startPos-k,right=startPos+1;
            for(int i=startPos-1;i>=startPos-k;i--)
               sum1+=m[i];
        
          while(right<=v.back()[0]&&left<right)
           {
               res=max(res,sum1);
               sum1-=m[left];
               left++;
               sum1-=m[left];
               left++;
               sum1+=m[right];
               right++;
           }
            res=max(res,sum1);
        return res;
        
    }
};