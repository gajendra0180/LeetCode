class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        deque<pair<string,int>>dq;
        dq.push_back({beginWord,1});
        map<string,int> vis;
        map<string,int> wl;for(auto i:wordList)wl[i]=1;
        vis[beginWord]=1;
        while(dq.size()){
            auto pr=dq.front();
            dq.pop_front();
            if(pr.first==endWord)
                return pr.second;
            for(int i=0;i<beginWord.size();i++){
                for(char ch='a';ch<='z';ch++){
                    string word=pr.first;
                    word[i]=ch;
                    if(wl.find(word)!=wl.end() && !vis[word]){
                        vis[word]=1;
                        dq.push_back({word,pr.second+1});
                    }
                }
            }
        }
        return 0;
    }
};