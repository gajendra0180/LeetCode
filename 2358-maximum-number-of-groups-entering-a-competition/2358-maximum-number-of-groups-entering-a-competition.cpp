class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int i=1,len=2;
        while(true){
            if(i+len<=grades.size()){
                i=i+len;//3
                len++;//3
            }
            else
                return len-1;
        }
        return len;
    }
};