//抽象父类
class Subject
{
public:
    void virtual request()=0;
};
//真实对象类
class Real_subject:public Subject
{
public:
    void request(){
        cout<<"my real request"<<endl;
    }
};
//代理类
class Proxy:public Subject
{
    Real_subject *subject;
public:
    void request(){
        if(subject==NULL)subject=new Real_subject;//延迟创建Realsubject，用时才创建
        cout<<"I am a proxy"<<endl;//通过代理可以添加或屏蔽真实对象的功能
        subject->request();
    }
    Proxy(){subject=NULL;}
    ~Proxy(){if(subject)delete subject;}
};
//客户端代码
void dosomething(Subject &subject){
    subject.request();
}
int main(){
    Proxy proxy;
    dosomething(proxy);
    return 0;
}
