class Solution {
public:
    bool canChange(string start, string target) {
        
        deque<pair<char,int>> s;     
        deque<pair<char,int>> t;
        
        for(int i=0;i<start.size();i++){
            if(start[i]!='_')
            s.push_back({start[i],i});
        }
        
        for(int i=0;i<start.size();i++){
            if(target[i]!='_')
            t.push_back({target[i],i});
        }
        
        string temp1;string temp2;
        for(auto i:start)
            if(i!='_')
                temp1.push_back(i);
        for(auto i:target)
            if(i!='_')
                temp2.push_back(i);
        
        if(s.size()!=t.size())
            return false;
        while(s.size()){
            auto it1=s.front();
            auto it2=t.front();
            s.pop_front();
            t.pop_front();
            if(it1.first!=it2.first)
                return false;
            if(it1.first=='L'){
                if(it2.second>it1.second)
                    return false;
            }
            if(it1.first=='R'){
                if(it1.second>it2.second)
                    return false;
            }
        }
        return true;
    }
};