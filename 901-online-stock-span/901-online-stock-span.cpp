class StockSpanner {
public:
   stack<pair<int, int>> s;
    int i=0;
    StockSpanner() {
        
    }
    
    int next(int vi) {
        
       if (s.size() == 0)
        {
            s.push({vi, i});
            i++;
            return 1;
        }
        else
        {
            while (s.size() > 0 && s.top().first <= vi)
                s.pop();
            int res=0;
            if (s.size() > 0)
                res = i - s.top().second;
            else
                res = i+1;
            s.push({vi, i});
            i++;
            return res;
        }
        
    }
};
