class Solution {
public:
    string res="";
    bool checkEqual(map<char,int>&m,map<char,int>&t){
        // O(N)
        for(auto i:t)if(m[i.first]<i.second)return false;
        return true;
    }
    bool condition(string &s,map<char,int>&t,int lengthOfWindow){
        // O(N)
        map<char,int>m;
        int i=0;
        for(i=0;i<lengthOfWindow;i++){
            m[s[i]]++;
        }
    if(checkEqual(m,t)){
            string temp;
            for(int ind=i-lengthOfWindow;ind<i;ind++)
                temp.push_back(s[ind]);
            res=temp;
        return true;
        }
        while(i<=s.size()){
            if(checkEqual(m,t)){
                    string temp;
                    for(int ind=i-lengthOfWindow;ind<i;ind++)
                        temp.push_back(s[ind]);
                    res=temp;
                return true;
                }
            m[s[i-lengthOfWindow]]--;
            if(m[s[i-lengthOfWindow]]==0)
                m.erase(s[i-lengthOfWindow]);
            m[s[i]]++;
          i++;
        }
        return false;
    }
    string minWindow(string s, string t) {
        int left=1,right=s.size()+1;
        map<char,int>tMap;
        for(auto i:t)tMap[i]++;
        // O(logN)
        while(left<right){
            int mid=(left+right)/2;
            if(condition(s,tMap,mid))
                right=mid;  
            else
                left=mid+1;
        }
        return res;
    }
};


