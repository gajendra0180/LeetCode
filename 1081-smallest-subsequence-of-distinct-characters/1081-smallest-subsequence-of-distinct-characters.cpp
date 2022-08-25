class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        map<char,int>count;
        map<char,int>vis;
        for(auto i:s)count[i]++;
        for(auto i:s){
            if(vis[i]){count[i]--;}
            if(!vis[i]){
                if(st.size()){
                    while(st.size() && i<=st.top() && count[st.top()] ){
                        vis[st.top()]=0;
                        st.pop();
                    }
                    st.push(i);
                    vis[i]=1;
                    count[i]--;
                    if(count[i]==0)
                        count.erase(i);
                }
                else
                {
                    vis[i]=1;
                    st.push(i);
                    count[i]--;
                }
            }
        }
        string res="";
        while(st.size()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};