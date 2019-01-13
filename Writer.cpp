#include "Writer.h"

Writer& Writer::getInstance() {
    static Writer instance;
    return instance;
}

std::streambuf * Writer::rdbuf() const {
    return stream.rdbuf();
}

std::streambuf * Writer::rdbuf(std::streambuf * sb) {
    return stream.rdbuf(sb);
}

Writer::operator std::ostream&() {
    return stream;
}

Writer::Writer() : stream(std::cout.rdbuf()) {
    tabCounter=0;
}

void Writer::addTabCounter(){
    tabCounter++;
}

void Writer::decTabCounter(){
    tabCounter--;
}

void Writer::printTabs(){
    std::ostream& cout=Writer::getInstance();
    for (int i=0; i<tabCounter; i++) {
        cout<<"    ";
    }
}

