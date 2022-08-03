class MyCalendar {
public:
   map<int,int>booking;
    MyCalendar() {
        
    }
    bool book(int s1, int e1) {
       for(auto i:booking){
           int s2=i.first,e2=i.second;
           if(s1<e2 && s2<e1)
               return false;
       }
        booking[s1]=e1;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */