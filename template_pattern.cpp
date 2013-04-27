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
//抽象模板类
class Template
{
public:
    virtual void altertableOperation1()=0;//模板中的可变操作部分
    virtual void altertableOperation2()=0;
    void fixOperation1(){cout<<"fixOperation1 has done"<<endl;}
    void fixOperation2(){cout<<"fixOperation2 has done"<<endl;}
    void templateMethod(){
        fixOperation1();
        altertableOperation1();//填空，把以后需要改变的地方声明为虚函数
        fixOperation2();
        altertableOperation2();
    }
};
//实际应用模板类A
class concreteClassA:public Template
{
public:
    void altertableOperation1(){
        cout<<"classA op1 has done"<<endl;
    }
    void altertableOperation2(){
        cout<<"classA op2 has done"<<endl;
    }
};
//实际应用模板类B
class concreteClassB:public Template
{
public:
    void altertableOperation1(){
        cout<<"classB op1 has done"<<endl;
    }
    void altertableOperation2(){
        cout<<"classB op2 has done"<<endl;
    }
};
//用户代码
void client(){
    Template *p=new concreteClassA;
    p->templateMethod();
}
int main(){
    client();
    return 0;
}


