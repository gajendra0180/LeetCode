class MyCalendar {
    map<int, int>bookings;
public:    
    bool book(int s1, int e1) {
        
        for(auto  i: bookings) 
        {
            int s2=i.first;
            int e2=i.second;
            if( s1 < e2 && s2 < e1 )   
			    return false; 
        }
        bookings[s1] = e1;                
        return true;
    }
};