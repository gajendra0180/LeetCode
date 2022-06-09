class Solution {
public:
     bool condition(int len,vector<int>&cards){
        int i=0;
        // unordered_map<int,int> m;
         int arr[1000001];
         for(int i=0;i<1000001;i++){
             arr[i]=0;
         }
        while(i<len){
                arr[cards[i]]++;
                if(arr[cards[i]]>1)
                    return true;
                i++;
        }
         
        while(i<cards.size()){
            arr[cards[i]]++;
            arr[cards[i-len]]--;
            if(arr[cards[i]]>1)
                return true;
            i++;
        }
         return false;
    }
    bool isTrue(int len,vector<int>&cards){
        int i=0;
        // unordered_map<int,int> m;
         int arr[1000001];
         for(int i=0;i<1000001;i++){
             arr[i]=0;
         }
        while(i<len){
                arr[cards[i]]++;
                if(arr[cards[i]]>1)
                    return true;
                i++;
        }
          while(i<cards.size()){
        arr[cards[i]]++;
            arr[cards[i-len]]--;
            if(arr[cards[i]]>1)
                return true;
            i++;
        }
        return false;
    }
    
    int minimumCardPickup(vector<int>& cards) {
        if(cards.size()<=1)
            return -1;
        int left=2,right=cards.size();
        while(left<right){
            int mid = left+(right-left)/2;
            if(condition(mid,cards))
                right=mid;
            else
                left=mid+1;
        }
        if(isTrue(left,cards))
            return left;
        return -1;
    }
};

