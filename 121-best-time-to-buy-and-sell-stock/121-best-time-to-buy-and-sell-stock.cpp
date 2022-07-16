class Solution {
public:
    int arr[2][100001];
    int p(vector<int>&prices,int isBuy,int index){
        
        if( index==prices.size() || isBuy==-1 )
            return 0;
        
        if(arr[isBuy][index]!=-1)
            return arr[isBuy][index];
        
        if(isBuy==1){
            return arr[isBuy][index] = max(-prices[index]+p(prices,0,index+1),p(prices,1,index+1));
        }
        else
        {
            return arr[isBuy][index] = max(prices[index]+p(prices,-1,index+1),p(prices,0,index+1));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        for(int i=0;i<2;i++){
            for(int j=0;j<100001;j++){
                arr[i][j]=-1;
            }
        }
        return p(prices,1,0);
    }
};