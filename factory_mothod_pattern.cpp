#include<iostream>
#include<time.h>
#include <stdlib.h>
#include<cmath>
#include<set>
#include<vector>
#include<string.h>
#include<deque>
#include<list>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
class oper
{
protected://使用保护成员，子类可以访问。子类不能访问私有成员
    double lhs;
    double rhs;
public:
    double virtual getResult()=0;//纯虚函数
    void set_lhs(double lhs){this->lhs=lhs;}
    void set_rhs(double rhs){this->rhs=rhs;}
};

class oper_add:public oper
{
public:
    double getResult(){
        return lhs+rhs;
    }
};

class oper_minus:public oper
{
public:
    double getResult(){
        return lhs-rhs;
    }
};
//抽象工厂类
class factory
{
protected:
    oper *op;
public:
    factory(){op=NULL;}
    ~factory(){if(op)delete op;}
    virtual oper* createOperator()=0;
};
//加法工厂类
class add_factory:public factory
{
public:
    oper* createOperator(){
        op=new oper_add;
        return op;
    }
};
//减法工厂类
class minus_factory:public factory
{
public:
    oper* createOperator(){
        op=new oper_minus;
        return op;
    }
};
//用户代码，计算器
double clientCounter(double lhs,double rhs,char oper_char){
    oper *op=NULL;
    factory *fac=NULL;
    switch(oper_char){
        case '+':
            fac=new add_factory;
            op=fac->createOperator();
            break;
        case '-':
            fac=new minus_factory;
            op=fac->createOperator();
            break;
        default:
            cout<<"operator error"<<endl;
            return 0;
    }
    op->set_lhs(lhs);
    op->set_rhs(rhs);
    double result=op->getResult();//使用父类指针调用纯虚函数实现多态
    if(fac)delete fac;
    return result;
}
int main(){
    cout<<clientCounter(4.5,4.3,'*')<<endl;
    return 0;
}


