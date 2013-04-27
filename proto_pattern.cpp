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
//可克隆抽象父类
class Prototype
{
public:
    virtual Prototype* clone()=0;
    static void freeClone(Prototype *pclone){
        delete pclone;
    }
};
//实际类，如简历类
class resume:public Prototype
{
    string name;
    int &age;//引用类型声明时必须初始化，因此必须使用初始化列表
    string experience;
public:
    resume(string name,int &age,string experience):name(name),age(age),experience(experience){}
    void set_age(int new_age){
        this->age=new_age;
    }
    void display(){
        cout<<this->age<<endl<<this->name<<endl<<this->experience<<endl;
    }
    Prototype* clone(){//实现深复制的话只能另外new一个resume对象
                       //因为resume有引用成员变量，引用被初始化以后就不能改变引用目标
        resume *presume=(resume*)malloc(sizeof(resume));//直接浅复制，不必调用构造函数
        memcpy(presume,this,sizeof(resume));//也无视访问权限
        return presume;
    }
};
int main(){
    int age=25;
    resume resumeA("yjh",age,"student");
    resumeA.display();
    resumeA.display();
    resumeA.set_age(26);//动态复制，克隆的结果为最新的值
    resume *resumeB=(resume*)resumeA.clone();
    resumeB->display();
    resumeB->set_age(17);//改变B的age也是也改变了A的
    resumeB->display();
    resumeA.display();//age=17,浅复制，只复制了地址，克隆体的引用类型还是引用了原型的
    Prototype::freeClone(resumeB);
    return 0;
}


