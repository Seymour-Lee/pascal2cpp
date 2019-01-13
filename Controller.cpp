//
//  <文件名>：Controller.cpp 
//  <文件内容>：该文件实现了Controller类的所以成员函数
//  <创建日期>：06/03/2017

//  包含头文件
#include <iostream>
#include <stdio.h>

#include "Controller.h" 
#include "syntax.tab.h"

//  引用syntax.y中的全局变量 
extern FILE * yyin;
extern int yyparse (Program **astRoot);

//
//  <函数名>：Controller::Controller()
//  <函数功能说明>：该函数为Controller类的构造函数 
Controller::Controller(){
    astRoot=NULL;
    //symbolTable=NULL;
}

//
//  <函数名>：Controller::~Controller()
//  <函数功能说明>：该函数为Controller类的析构函数
Controller::~Controller(){
    //std::cout<<"deleting Controller"<<std::endl;
    if(astRoot == NULL) delete astRoot;
    
    //delete the AST using back-traversing
}

//
//  <函数名>：Controller::parsing(const char * fileName)
//  <函数功能说明>：该函数调用词法和语法分析函数运行
//  如遇到无法忽略的错误导致语法分析未生成根节点，则分析停止 
void Controller::parsing(const char * fileName){
    if(!(yyin=std::fopen(fileName, "r")))
    	std::cout<<"未输入源文件，请采用命令行方式运行！"<<std::endl; 
    //call yyparse();
    //std::cout<<(yyin==NULL);
    else
    {
    	std::cout<<"正在编译源文件："<<fileName<<"\n";
	    yyparse(&this->astRoot); 
	    if(this->astRoot==NULL)
	    	std::cout<<"\n\n（1）词法，语法分析完成，发现错误，分析停止，请修改源文件！\n\n";
		else 
			std::cout<<"\n\n（1）词法，语法分析完成！\n\n";
    }
}

//
//  <函数名>：Controller::typeChecking()
//  <函数功能说明>：该函数调用类型检查函数运行
void Controller::typeChecking(){
    //traverse the AST to check the type-righting
    if(astRoot) {
		this->astRoot->checkType();
    	//std::cout<<"\n语义分析完成。\n\n";
	} 
        
}

//
//  <函数名>：Controller::codeGeneration()
//  <函数功能说明>：该函数调用代码生成函数运行
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
	    std::cout<<"\n\n（3）C代码生成完成，详见："<<outName<<"\n\n";
	} 
}


