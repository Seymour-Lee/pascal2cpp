#ifndef Controller_h
#define Controller_h

#include "AbstractSyntaxTree.h"
#include "SymbolTable.h"

class Controller{
public:
    Controller();
    ~Controller();
    
    void parsing(const char * fileName);
    void typeChecking();
    void codeGeneration(const char * fileName);
    
private:
    //SymbolTable * symbolTable;
    
    Program * astRoot;//AST root node
    
};

#endif /* Controller_h */

