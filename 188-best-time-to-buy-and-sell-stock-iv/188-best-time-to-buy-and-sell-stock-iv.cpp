class Solution {
public:
    int arr[2][101][1001];
    int p(vector<int>&prices,int isBuy,int index,int k){
        
        if( index==prices.size() || k<0)
            return 0;
        
        if(arr[isBuy][k][index]!=-1)
            return arr[isBuy][k][index];
        
        if(isBuy==1){
            return arr[isBuy][k][index] = max(-prices[index]+p(prices,0,index+1,k),p(prices,1,index+1,k));
        }
        else
        {
            return arr[isBuy][k][index] = max(prices[index]+p(prices,1,index+1,k-1),p(prices,0,index+1,k));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        for(int i=0;i<2;i++){
            for(int k=0;k<101;k++){
                for(int j=0;j<1001;j++){
                    arr[i][k][j]=-1;
                }
            }
        }
        return p(prices,1,0,k-1);
    }
};