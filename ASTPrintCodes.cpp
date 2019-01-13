#include "AbstractSyntaxTree.h"
#include "Writer.h"
#include "SymbolTable.h"

#define tab Writer::getInstance().printTabs()

using namespace std;

int func_location=0;

void Program::printCodes(char* outName){
    std::ofstream fout;
    fout.open(outName);
    
    Writer::getInstance().rdbuf(fout.rdbuf());
    
    ostream& cout = Writer::getInstance();
    
    tab;cout<<"#include <stdio.h>"<<endl;
    tab;cout<<"#include <stdlib.h>"<<endl;
    tab;cout<<"#include <math.h>"<<endl;
    tab;cout<<"#include <string.h>"<<endl;
    tab;cout<<"typedef enum {false, true} bool;"<<endl;
    
    cout<<endl;
    
    this->head->printCodes();
    this->body->printCodes();
}

void ProgramHead::printCodes(){
    //ostream& cout=Writer::getInstance();
}

void ProgramBody::printCodes(){
    ostream& cout=Writer::getInstance();
    for (int i=0; i<constDeclarations.size(); i++) {
        tab;constDeclarations[i]->printCodes();
    }
    if(constDeclarations.size())
        cout<<endl;
    
    for (int i=0; i<typeDeclarations.size(); i++) {
        tab;typeDeclarations[i]->printCodes();
    }
    if(typeDeclarations.size())
        cout<<endl;
    
    for (int i=0; i<varDeclarations.size(); i++) {
        tab;varDeclarations[i]->printCodes();
    }
    if(varDeclarations.size())
        cout<<endl;
    
    for (int i=0; i<subprogramDeclarations.size(); i++) {
        tab;subprogramDeclarations[i]->printCodes();
        cout<<endl;
    }
    if(subprogramDeclarations.size())
        cout<<endl;
    
    func_location=0;
    tab;cout<<"int main()"<<endl;
    tab;cout<<"{"<<endl;
    Writer::getInstance().addTabCounter();
    
    compoundStatement->printCodes();
    
    
    tab;cout<<"return 0;"<<endl;
    Writer::getInstance().decTabCounter();
    tab;cout<<"}"<<endl;
    
}

void ConstDeclaration::printCodes(){
    ostream& cout=Writer::getInstance();
    
    if(dynamic_cast<UnsignedIdentifierFD *>(constVariable) != NULL){
        UnsignedIdentifierFD * temp = dynamic_cast<UnsignedIdentifierFD *>(constVariable);
        cout<<"#define "+this->id+" ";
        temp->printCodes();
        cout<<""<<endl;
    }
    else if(dynamic_cast<SignedIdentifierFD *>(constVariable) != NULL){
        SignedIdentifierFD * temp = dynamic_cast<SignedIdentifierFD *>(constVariable);
        cout<<"#define "+this->id+" ";
        temp->printCodes();
        cout<<""<<endl;
    }
    else if(dynamic_cast<UnsignedNumFD *>(constVariable) != NULL){
        UnsignedNumFD * temp = dynamic_cast<UnsignedNumFD *>(constVariable);
        cout<<"#define "+this->id+" ";
        temp->printCodes();
        cout<<""<<endl;
    }
    else if(dynamic_cast<SignedNumFD *>(constVariable) != NULL){
        SignedNumFD * temp = dynamic_cast<SignedNumFD *>(constVariable);
        cout<<"#define "+this->id+" ";
        temp->printCodes();
        cout<<""<<endl;
    }
    else if(dynamic_cast<LettersFD *>(constVariable) != NULL){
        LettersFD * temp = dynamic_cast<LettersFD *>(constVariable);
        cout<<"#define "+this->id+" ";
        temp->printCodes();
        cout<<""<<endl;
    }
}

void UnsignedIdentifierFD::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<id;
}

void SignedIdentifierFD::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<(sign? "+": "-")+id;
}

void UnsignedNumFD::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<num;
}

void SignedNumFD::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<(sign? "+": "-")+num;
}

void LettersFD::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<letters;
}

void TypeDeclaration::printCodes(){
    ostream& cout=Writer::getInstance();
    
    if(dynamic_cast<IntegerType *>(type)!=NULL){
        cout<<"typedef int "<<id<<";"<<endl;
    }
    else if(dynamic_cast<RealType *>(type)!=NULL){
        cout<<"typedef double "<<id<<";"<<endl;
    }
    else if(dynamic_cast<BooleanType *>(type)!=NULL){
        cout<<"typedef bool "<<id<<";"<<endl;
    }
    else if(dynamic_cast<CharType *>(type)!=NULL){
        cout<<"typedef char "<<id<<";"<<endl;
    }
    else if(dynamic_cast<RecordType *>(type)!=NULL){
        RecordType * recordType=dynamic_cast<RecordType *>(type);
        cout<<"typedef ";
        recordType->printCodes();
        cout<<id+";"<<endl;
    }
    else if(dynamic_cast<ArrayType *>(type)!=NULL){
        ArrayType * arrayType=dynamic_cast<ArrayType*>(type);
        cout<<"typedef ";
        
        arrayType->printType();
        
        cout<<" "<<id;
        
        arrayType->printPeriods();
        //arrayType->printCodes();
        cout<<";"<<endl;
    }
}

void VarDeclaration::printCodes(){
    ostream& cout=Writer::getInstance();
    if(dynamic_cast<IntegerType *>(type)!=NULL){
        IntegerType * integerType=dynamic_cast<IntegerType *>(type);
        integerType->printCodes();
        cout<<" ";
        for (int i=0; i<identifierList.size(); i++) {
            cout<<identifierList[i];
            if(i!=(identifierList.size()-1))
                cout<<", ";
        }
        cout<<";"<<endl;
    }
    else if(dynamic_cast<RealType *>(type)!=NULL){
        RealType * realType=dynamic_cast<RealType *>(type);
        realType->printCodes();
        cout<<" ";
        for (int i=0; i<identifierList.size(); i++) {
            cout<<identifierList[i];
            if(i!=(identifierList.size()-1))
                cout<<", ";
        }
        cout<<";"<<endl;
    }
    else if(dynamic_cast<BooleanType *>(type)!=NULL){
        BooleanType * booleanType=dynamic_cast<BooleanType *>(type);
        booleanType->printCodes();
        cout<<" ";
        for (int i=0; i<identifierList.size(); i++) {
            cout<<identifierList[i];
            if(i!=(identifierList.size()-1))
                cout<<", ";
        }
        cout<<";"<<endl;
    }
    else if(dynamic_cast<CharType *>(type)!=NULL){
        CharType * charType=dynamic_cast<CharType *>(type);
        charType->printCodes();
        cout<<" ";
        for (int i=0; i<identifierList.size(); i++) {
            cout<<identifierList[i];
            if(i!=(identifierList.size()-1))
                cout<<", ";
        }
        cout<<";"<<endl;
    }
    else if(dynamic_cast<RecordType *>(type)!=NULL){
        RecordType * recordType=dynamic_cast<RecordType *>(type);
        recordType->printCodes();
        cout<<" ";
        for (int i=0; i<identifierList.size(); i++) {
            cout<<identifierList[i];
            if(i!=(identifierList.size()-1))
                cout<<", ";
        }
        cout<<";"<<endl;
    }
    else if(dynamic_cast<ArrayType *>(type)!=NULL){
        ArrayType * arrayType=dynamic_cast<ArrayType *>(type);
        //arrayType->printCodes();
        arrayType->printType();
        cout<<" ";
        for (int i=0; i<identifierList.size(); i++) {
            cout<<identifierList[i];
            arrayType->printPeriods();
            if(i!=(identifierList.size()-1))
                cout<<", ";
        }
        cout<<";"<<endl;
    }
}

void RecordType::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<"struct {"<<endl;
    Writer::getInstance().addTabCounter();
    for (int i=0; i<varDeclarations.size(); i++) {
        tab;varDeclarations[i]->printCodes();
    }
    Writer::getInstance().decTabCounter();
    cout<<"}";
}

void ArrayType::printType(){
    if(dynamic_cast<IntegerType *>(type)!=NULL){
        IntegerType * integerType=dynamic_cast<IntegerType *>(type);
        integerType->printCodes();
    }
    else if(dynamic_cast<RealType *>(type)!=NULL){
        RealType * realType=dynamic_cast<RealType *>(type);
        realType->printCodes();
    }
    else if(dynamic_cast<BooleanType *>(type)!=NULL){
        BooleanType * booleanType=dynamic_cast<BooleanType *>(type);
        booleanType->printCodes();
    }
    else if(dynamic_cast<CharType *>(type)!=NULL){
        CharType * charType=dynamic_cast<CharType *>(type);
        charType->printCodes();
    }
    else if(dynamic_cast<RecordType *>(type)!=NULL){
        RecordType * recordType=dynamic_cast<RecordType *>(type);
        recordType->printCodes();
    }
}

void ArrayType::printPeriods(){
    for (int i=0; i<periods.size(); i++) {
        periods[i]->printCodes();
    }
}

void ArrayType::printCodes(){
    //ostream& cout=Writer::getInstance();
    if(dynamic_cast<IntegerType *>(type)!=NULL){
        IntegerType * integerType=dynamic_cast<IntegerType *>(type);
        integerType->printCodes();
    }
    else if(dynamic_cast<RealType *>(type)!=NULL){
        RealType * realType=dynamic_cast<RealType *>(type);
        realType->printCodes();
    }
    else if(dynamic_cast<BooleanType *>(type)!=NULL){
        BooleanType * booleanType=dynamic_cast<BooleanType *>(type);
        booleanType->printCodes();
    }
    else if(dynamic_cast<CharType *>(type)!=NULL){
        CharType * charType=dynamic_cast<CharType *>(type);
        charType->printCodes();
    }
    else if(dynamic_cast<RecordType *>(type)!=NULL){
        RecordType * recordType=dynamic_cast<RecordType *>(type);
        recordType->printCodes();
    }
    else if(dynamic_cast<ArrayType *>(type)!=NULL){
        ArrayType * arrayType=dynamic_cast<ArrayType *>(type);
        arrayType->printCodes();
    }
    
    for (int i=0; i<periods.size(); i++) {
        periods[i]->printCodes();
    }
}

void Period::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<"[(";
    
    if(dynamic_cast<UnsignedIdentifierFD *>(upper) != NULL){
        UnsignedIdentifierFD * temp = dynamic_cast<UnsignedIdentifierFD *>(upper);
        temp->printCodes();
    }
    else if(dynamic_cast<SignedIdentifierFD *>(upper) != NULL){
        SignedIdentifierFD * temp = dynamic_cast<SignedIdentifierFD *>(upper);
        temp->printCodes();
    }
    else if(dynamic_cast<UnsignedNumFD *>(upper) != NULL){
        UnsignedNumFD * temp = dynamic_cast<UnsignedNumFD *>(upper);
        temp->printCodes();
    }
    else if(dynamic_cast<SignedNumFD *>(upper) != NULL){
        SignedNumFD * temp = dynamic_cast<SignedNumFD *>(upper);
        temp->printCodes();
    }
    else if(dynamic_cast<LettersFD *>(upper) != NULL){
        LettersFD * temp = dynamic_cast<LettersFD *>(upper);
        temp->printCodes();
    }
    
    cout<<")-(";
    

    if(dynamic_cast<UnsignedIdentifierFD *>(lower) != NULL){
        UnsignedIdentifierFD * temp = dynamic_cast<UnsignedIdentifierFD *>(lower);
        temp->printCodes();
    }
    else if(dynamic_cast<SignedIdentifierFD *>(lower) != NULL){
        SignedIdentifierFD * temp = dynamic_cast<SignedIdentifierFD *>(lower);
        temp->printCodes();
    }
    else if(dynamic_cast<UnsignedNumFD *>(lower) != NULL){
        UnsignedNumFD * temp = dynamic_cast<UnsignedNumFD *>(lower);
        temp->printCodes();
    }
    else if(dynamic_cast<SignedNumFD *>(lower) != NULL){
        SignedNumFD * temp = dynamic_cast<SignedNumFD *>(lower);
        temp->printCodes();
    }
    else if(dynamic_cast<LettersFD *>(lower) != NULL){
        LettersFD * temp = dynamic_cast<LettersFD *>(lower);
        temp->printCodes();
    }
    
    cout<<")+1]";
}

void IntegerType::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<"int";
}

void RealType::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<"double";
}

void BooleanType::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<"bool";
}

void CharType::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<"char";
}

void SubprogramDeclaration::printCodes(){
    ostream& cout=Writer::getInstance();
    head->printCodes();
    cout<<"{"<<endl;
    Writer::getInstance().addTabCounter();
    body->printCodes();
    Writer::getInstance().decTabCounter();
    cout<<"}"<<endl;
}

void SubprogramHead::printCodes(){
	func_location++;
    ostream& cout=Writer::getInstance();
    if(dynamic_cast<IntegerType *>(ret)!=NULL){
        IntegerType * integerType=dynamic_cast<IntegerType *>(ret);
        integerType->printCodes();
    }
    else if(dynamic_cast<RealType *>(ret)!=NULL){
        RealType * realType=dynamic_cast<RealType *>(ret);
        realType->printCodes();
    }
    else if(dynamic_cast<BooleanType *>(ret)!=NULL){
        BooleanType * booleanType=dynamic_cast<BooleanType *>(ret);
        booleanType->printCodes();
    }
    else if(dynamic_cast<CharType *>(ret)!=NULL){
        CharType * charType=dynamic_cast<CharType *>(ret);
        charType->printCodes();
    }
    else{
        cout<<"void";
    }
    cout<<" "+id+"(";
    
    for (int i=0; i<parameterLists.size(); i++) {
        parameterLists[i]->printCodes();
        if(i!=(parameterLists.size()-1))
            cout<<", ";
    }
    
    cout<<")"<<endl;
}

void SubprogramBody::printCodes(){
    ostream& cout=Writer::getInstance();
    for (int i=0; i<constDeclarations.size(); i++) {
        tab;constDeclarations[i]->printCodes();
    }
    if(constDeclarations.size())
        cout<<endl;
    
    for (int i=0; i<typeDeclarations.size(); i++) {
        tab;typeDeclarations[i]->printCodes();
    }
    if(typeDeclarations.size())
        cout<<endl;
    
    for (int i=0; i<varDeclarations.size(); i++) {
        tab;varDeclarations[i]->printCodes();
    }
    if(varDeclarations.size())
        cout<<endl;
    
    for (int i=0; i<subprogramDeclarations.size(); i++) {
        tab;subprogramDeclarations[i]->printCodes();
    }
    if(subprogramDeclarations.size())
        cout<<endl;
    
    compoundStatement->printCodes();
}

void ParameterList::printCodes(){
    ostream& cout=Writer::getInstance();
    string typeStr;
    if(dynamic_cast<IntegerType *>(type)!=NULL){
        typeStr="int";
    }
    else if(dynamic_cast<RealType *>(type)!=NULL){
        typeStr="double";
    }
    else if(dynamic_cast<BooleanType *>(type)!=NULL){
        typeStr="bool";
    }
    else if(dynamic_cast<CharType *>(type)!=NULL){
        typeStr="char";
    }
    string isReference=byReference?"*":""; 
    for (int i=0; i<identifierList.size(); i++) {
        cout<<typeStr+" "+isReference+identifierList[i];
        if(i!=(identifierList.size()-1))
            cout<<", ";
    }
}

void Statement::printCodes(){
    if (dynamic_cast<AssignStatement *>(this)!=NULL) {
        AssignStatement * assignStatement=dynamic_cast<AssignStatement *>(this);
        assignStatement->printCodes();
    }
    else if(dynamic_cast<CallProcedureStatement *>(this)!=NULL){
        CallProcedureStatement * callProcedureStatement=dynamic_cast<CallProcedureStatement *>(this);
        callProcedureStatement->printCodes();
    }
    else if(dynamic_cast<CompoundStatement *>(this)!=NULL){
        CompoundStatement * compoundStatement=dynamic_cast<CompoundStatement *>(this);
        compoundStatement->printCodes();
    }
    else if(dynamic_cast<IfStatement *>(this)!=NULL){
        IfStatement * ifStatement=dynamic_cast<IfStatement *>(this);
        ifStatement->printCodes();
    }
    else if(dynamic_cast<CaseStatement *>(this)!=NULL){
        CaseStatement * caseStatement=dynamic_cast<CaseStatement *>(this);
        caseStatement->printCodes();
    }
    else if(dynamic_cast<WhileStatement *>(this)!=NULL){
        WhileStatement * whileStatement=dynamic_cast<WhileStatement *>(this);
        whileStatement->printCodes();
    }
    else if(dynamic_cast<RepeatStatement *>(this)!=NULL){
        RepeatStatement * repeatStatement=dynamic_cast<RepeatStatement *>(this);
        repeatStatement->printCodes();
    }
    else if(dynamic_cast<ForStatement *>(this)!=NULL){
        ForStatement * forStatement=dynamic_cast<ForStatement *>(this);
        forStatement->printCodes();
    }
    else if(dynamic_cast<ReadStatement *>(this)!=NULL){
        ReadStatement * readStatement=dynamic_cast<ReadStatement *>(this);
        readStatement->printCodes();
    }
    else if(dynamic_cast<WriteStatement *>(this)!=NULL){
        WriteStatement * writeStatement=dynamic_cast<WriteStatement *>(this);
        writeStatement->printCodes();
    }
    
}

void AssignStatement::printCodes(){
    ostream& cout=Writer::getInstance();

	if (SymbolTable::getInstance()->find_in_global(variable->id) && (dynamic_cast<Function *>(SymbolTable::getInstance()->getType(variable->id))!=NULL)){
        tab;cout<<"return ";
		      
    }
    else{
        tab;variable->printCodes();
        cout<<"=";
    }
    
    
    expression->printCodes();
    cout<<";"<<endl;
}

void CallProcedureStatement::printCodes(){
    ostream& cout=Writer::getInstance();
    
    tab;cout<<id<<"(";
    
    for (int i=0; i<expressionList.size(); i++) {
    	if(SymbolTable::getInstance()->isParaReference(id,i))
        	cout<<"&";
        expressionList[i]->printCodes();
        //var???
        if(i!=(expressionList.size()-1))
            cout<<", ";
    }
    
    cout<<");"<<endl;
}

void CompoundStatement::printCodes(){
    //ostream& cout=Writer::getInstance();
    for (int i=0; i<statementList.size() && statementList[i]!=NULL; i++) {
        statementList[i]->printCodes();
    }
}

void IfStatement::printCodes(){
    ostream& cout=Writer::getInstance();
    tab;cout<<"if(";
    expression->printCodes();
    cout<<")"<<endl;
    tab;cout<<"{"<<endl;
    Writer::getInstance().addTabCounter();
    
    thenStatement->printCodes();
    
    Writer::getInstance().decTabCounter();
    tab;cout<<"}"<<endl;
    
    if(elseStatement){
        tab;cout<<"else"<<endl;
        tab;cout<<"{"<<endl;
        Writer::getInstance().addTabCounter();
        
        elseStatement->printCodes();
        
        Writer::getInstance().decTabCounter();
        tab;cout<<"}"<<endl;
    }
}

void CaseStatement::printCodes(){
    ostream& cout=Writer::getInstance();
    
    tab;cout<<"switch(";
    expression->printCodes();
    cout<<")"<<endl;
    tab;cout<<"{"<<endl;
    Writer::getInstance().addTabCounter();
    
    for (int i=0; i<branchList.size(); i++) {
        branchList[i]->printCodes();
    }
    
    tab;cout<<"default: break;"<<endl;
    
    Writer::getInstance().decTabCounter();
    tab;cout<<"}"<<endl;
}

void Branch::printCodes(){
    ostream& cout=Writer::getInstance();
    
    for (int i=0; i<constVariable.size(); i++) {
        tab;cout<<"case ";
        constVariable[i]->printCodes();
        cout<<":"<<endl;
    }
    Writer::getInstance().addTabCounter();
    
    statement->printCodes();
    
    tab;cout<<"break;"<<endl;
    Writer::getInstance().decTabCounter();
}

void WhileStatement::printCodes(){
    ostream& cout=Writer::getInstance();
    
    tab;cout<<"while(";
    
    expression->printCodes();
    
    cout<<")"<<endl;
    tab;cout<<"{"<<endl;
    Writer::getInstance().addTabCounter();
    
    statement->printCodes();
    
    Writer::getInstance().decTabCounter();
    tab;cout<<"}"<<endl;
}

void RepeatStatement::printCodes(){
    ostream& cout=Writer::getInstance();
    
    tab;cout<<"do"<<endl;
    tab;cout<<"{"<<endl;
    Writer::getInstance().addTabCounter();
    
    for (int i=0; i<statementList.size(); i++) {
        statementList[i]->printCodes();
    }
    
    Writer::getInstance().decTabCounter();
    tab;cout<<"}while(!(";
    
    expression->printCodes();
    
    cout<<"));"<<endl;
}

void ForStatement::printCodes(){
    ostream& cout=Writer::getInstance();
    
    tab;cout<<"for(int "<<id<<"=";
    lower->printCodes();
    cout<<"; "<<id<<(updown==TO? "<=": ">=");
    upper->printCodes();
    cout<<"; "<<id<<(updown==TO? "++": "--")<<")"<<endl;
    tab;cout<<"{"<<endl;
    Writer::getInstance().addTabCounter();
    
    statement->printCodes();
    
    Writer::getInstance().decTabCounter();
    tab;cout<<"}"<<endl;
}

void ReadStatement::printCodes(){
    ostream& cout=Writer::getInstance();
    
    tab;cout<<"scanf(\"";
    
    for (int i=0; i<identifierList.size(); i++) {
        if (dynamic_cast<Integer *>(SymbolTable::getInstance()->getType(identifierList[i]))) {
            cout<<"%d";
        }
        else if(dynamic_cast<Char *>(SymbolTable::getInstance()->getType(identifierList[i]))){
            cout<<"%c";
        }
        else if(dynamic_cast<Real *>(SymbolTable::getInstance()->getType(identifierList[i]))){
            cout<<"%f";
        }
        else if(dynamic_cast<Bool *>(SymbolTable::getInstance()->getType(identifierList[i]))){
            cout<<"%d";
        }
    }
    
    cout<<"\"";
    
    for (int i=0; i<identifierList.size(); i++) {
        cout<<", &";
        cout<<identifierList[i];
    }
    cout<<");"<<endl;
}

void WriteStatement::printCodes(){
    ostream& cout=Writer::getInstance();
    
    tab;cout<<"printf(\"";
    
    for (int i=0; i<expressionList.size(); i++) {
    	if (expressionList[i]->checkType()==CONST_T) {
            cout<<"%d";
        }
        else if (expressionList[i]->checkType()==INT_T) {
            cout<<"%d";
        }
        else if(expressionList[i]->checkType()==CHAR_T){
            cout<<"%c";
        }
        else if(expressionList[i]->checkType()==REAL_T){
            cout<<"%f";
        }
        else if(expressionList[i]->checkType()==BOOL_T){
            cout<<"%d";
        }
    }
    
    cout<<"\"";
    
    for (int i=0; i<expressionList.size(); i++) {
        cout<<", ";
        expressionList[i]->printCodes();
    }
    
    cout<<");"<<endl;
}

void BinaryExpression::printCodes(){
    ostream& cout=Writer::getInstance();
    
    left->printCodes();
    
    if(relop==EQUAL){
        cout<<"==";
    }
    else if(relop==NOTEQUAL){
        cout<<"!=";
    }
    else if(relop==LESSTHAN){
        cout<<"<";
    }
    else if(relop==LESSEQUAL){
        cout<<"<=";
    }
    else if(relop==GREATERTHAN){
        cout<<">";
    }
    else if(relop==GREATEREQUAL){
        cout<<">=";
    }
    
    right->printCodes();
}

void BinarySimpleExpression::printCodes(){
    ostream& cout=Writer::getInstance();
    
    simpleExpression->printCodes();
    
    if(addop==PLUS){
        cout<<"+";
    }
    else if(addop==MINUS){
        cout<<"-";
    }
    else if(addop==OR){
        cout<<"||";
    }
    
    term->printCodes();
}

void SignedTerm::printCodes(){
    ostream& cout=Writer::getInstance();
    
    cout<<(sign? "+": "-");
    term->printCodes();
}

void BinaryTerm::printCodes(){
    ostream& cout=Writer::getInstance();
    term->printCodes();
    
    if(mulop==MULTIPLY){
        cout<<"*";
    }
    else if(mulop==REALDIVIDE){
        cout<<"/";
    }
    else if(mulop==INTDIVIDE){
        cout<<"/";
    }
    else if(mulop==MOD){
        cout<<"%";
    }
    else if(mulop==AND){
        cout<<"&&";
    }
    
    factor->printCodes();
}

void Variable::printCodes(){
    ostream& cout=Writer::getInstance();
    if(SymbolTable::getInstance()->isParaReference(func_location,id))
    	cout<<"(*"<<id<<")";
    else
    	cout<<id;
    for (int i=0; i<idVarParts.size(); i++) {
        idVarParts[i]->printCodes();
    }
}

void ArrayPart::printCodes(){
    ostream& cout=Writer::getInstance();
    for (int i=0; i<expressionList.size(); i++) {
        cout<<"[";
        expressionList[i]->printCodes();
        cout<<"]";
    }
}

void MemberPart::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<"."<<id;
}

void FunctionCall::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<id<<"(";
    for (int i=0; i<expressionList.size(); i++) {
        if(SymbolTable::getInstance()->isParaReference(id,i))
        	cout<<"&";
		expressionList[i]->printCodes();
        if(i!=(expressionList.size()-1))
            cout<<", ";
    }
    cout<<")";
}

void Parenthesis::printCodes(){
    ostream& cout=Writer::getInstance();
    
    cout<<"(";
    expression->printCodes();
    cout<<")";
}

void Not::printCodes(){
    ostream& cout=Writer::getInstance();
    
    cout<<"!(";
    
    if(dynamic_cast<Num *>(factor)!=NULL){
        Num * num=dynamic_cast<Num *>(factor);
        num->printCodes();
    }
    else if(dynamic_cast<Letters *>(factor)!=NULL){
        Letters * letters=dynamic_cast<Letters *>(factor);
        letters->printCodes();
    }
    else if(dynamic_cast<Variable *>(factor)!=NULL){
        Variable * variable=dynamic_cast<Variable *>(factor);
        variable->printCodes();
    }
    else if(dynamic_cast<FunctionCall *>(factor)!=NULL){
        FunctionCall * functionCall=dynamic_cast<FunctionCall *>(factor);
        functionCall->printCodes();
    }
    else if(dynamic_cast<Parenthesis *>(factor)!=NULL){
        Parenthesis * parenthesis=dynamic_cast<Parenthesis *>(factor);
        parenthesis->printCodes();
    }
    else if(dynamic_cast<Not *>(factor)!=NULL){
        Not * nott=dynamic_cast<Not *>(factor);
        nott->printCodes();
    }
    else if(dynamic_cast<Boolean *>(factor)!=NULL){
        Boolean * boolean=dynamic_cast<Boolean *>(factor);
        boolean->printCodes();
    }
    cout<<")";
}

void Boolean::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<(value? "true": "false");
}

void UnsignedConst::printCodes(){
    if(dynamic_cast<Num *>(this)!=NULL){
        Num * num=dynamic_cast<Num *>(this);
        num->printCodes();
    }
    else if(dynamic_cast<Letters *>(this)!=NULL){
        Letters * letters=dynamic_cast<Letters *>(this);
        letters->printCodes();
    }
}

void Num::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<num;
}

void Letters::printCodes(){
    ostream& cout=Writer::getInstance();
    cout<<letters;
}


