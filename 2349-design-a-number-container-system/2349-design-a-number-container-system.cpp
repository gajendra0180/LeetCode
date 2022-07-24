class NumberContainers {
public:
    NumberContainers() {
        
    }
    map<int,set<int>>m1;
    map<int,int> m2;
    void change(int index, int number) {
        int originalNumber=m2[index];
        m1[originalNumber].erase(index);
        m2[index]=number;
        m1[number].insert(index);
    }
    int find(int number) {
        if(m1[number].size()==0)
            return -1;
        return *m1[number].begin();
    }
};

// 7->1 3 5     7 number 1,3 and 5 index pe h
    
// 5->10 5we index pe 10 kro