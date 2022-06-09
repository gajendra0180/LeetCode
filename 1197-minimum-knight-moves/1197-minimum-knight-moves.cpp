class Solution {
public:
    int minKnightMoves(int x, int y) {

        int arr[601][601];
        for(int i=0;i<601;i++){
            for(int j=0;j<601;j++){
                arr[i][j]=-1;
            }
        }
        
        deque<pair<int,pair<int,int>>>dq;
        dq.push_back({0,{0,0}});
        
        while(dq.size()){

            auto it=dq.front();
            int c=it.first;
            auto [a,b]=it.second;
            dq.pop_front();
            
            if(arr[a+300][b+300]==1)
                continue;
            
            if(a==x&&b==y)
                return c;
            
            arr[a+300][b+300]=1;
            
            dq.push_back({c+1,{a+1,b+2}});
            dq.push_back({c+1,{a+1,b-2}});
            dq.push_back({c+1,{a+2,b-1}});
            dq.push_back({c+1,{a+2,b+1}});
            dq.push_back({c+1,{a-1,b-2}});
            dq.push_back({c+1,{a-1,b+2}});
            dq.push_back({c+1,{a-2,b-1}});
            dq.push_back({c+1,{a-2,b+1}});
        }
        return -1;
    }
};