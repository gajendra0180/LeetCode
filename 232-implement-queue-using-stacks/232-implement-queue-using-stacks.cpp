class MyQueue {
public:
    stack<int>s;
    MyQueue() {
        
    }
    void push(int x) {
        vector<int>temp;
        while(s.size())
        {
            temp.push_back(s.top());
            s.pop();
        }
        s.push(x);
        reverse(temp.begin(),temp.end());
        for(auto i:temp)
            s.push(i);
    }
    
    int pop() {
        int ele=s.top();
        s.pop();
        return ele;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */