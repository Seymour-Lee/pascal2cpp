#include <iostream>
#include <stdio.h>

#include "Controller.h" 
#include "syntax.tab.h"

extern FILE * yyin;
extern int yyparse (Program **astRoot);

Controller::Controller(){
    astRoot=NULL;
    //symbolTable=NULL;
}

Controller::~Controller(){
    //std::cout<<"deleting Controller"<<std::endl;
    if(astRoot == NULL) delete astRoot;
    
    //delete the AST using back-traversing
}

void Controller::parsing(const char * fileName){
    if(!(yyin=std::fopen(fileName, "r")))
    	std::cout<<"can not open file"<<std::endl; 
    //call yyparse();
    //std::cout<<(yyin==NULL);
    else
    {
    	std::cout<<"open file "<<fileName<<"\n";
	    yyparse(&this->astRoot); 
	    if(this->astRoot==NULL)
	    	std::cout<<"\n\nastRoot is nullptr\n\n";
		else 
			std::cout<<"\n\nGot the astRoot\n\n";
    }
}

void Controller::typeChecking(){
    //traverse the AST to check the type-righting
    if(astRoot) {
		this->astRoot->checkType();
	} 
        
}

void Controller::codeGeneration(const char * fileName){
    //call this function after parsing();
    //deal with the AST to print the c-code
    if(astRoot) {
    	char *outName=new char[strlen(fileName)+1];
		strcpy(outName,fileName);
	    //std::cout<<strtok(pureName,".");
	    if(strtok(outName,".")!=NULL)
	    	outName=strcat(strtok(outName,"."),".c");
	    else 
	    	outName=strcat(outName,".c");
	    this->astRoot->printCodes(outName);
	    std::cout<<"\n\noutput file is "<<outName<<"\n\n";
	} 
}


