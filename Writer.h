#ifndef Writer_h
#define Writer_h

#include <iostream>
#include <fstream>
#include <string>

class Writer{
public:
    static Writer & getInstance();
        
    std::streambuf* rdbuf() const;
    std::streambuf* rdbuf(std::streambuf* sb);
    
    operator std::ostream&();
    
    void addTabCounter();
    void decTabCounter();
    void printTabs();  
    
private:
    Writer();
    
    int tabCounter;
    
    std::ostream stream;
};


#endif /* Writer_h */

