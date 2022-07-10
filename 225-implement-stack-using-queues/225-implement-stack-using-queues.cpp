class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        queue<int>q2;
        vector<int>v;
        while(q1.size()){
            v.push_back(q1.front());
            q1.pop();
        }
        int num=v.back();
        v.pop_back();
        for(auto i:v)
            q1.push(i);
        return num;
    }
    
    int top() {
     return q1.back();
    }
    
    bool empty() {
        return q1.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */