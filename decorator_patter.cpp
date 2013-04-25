class Component
{
public:
    virtual void operation()=0;
};
//具体的对象
class ConcreteComponent:public Component
{
public:
    void operation(){cout<<"I am a man"<<endl;}
};
//装饰类
class Decorator:public Component
{
protected:
    Component *comp;
public:
    Decorator(){comp=NULL;}
    ~Decorator(){if(comp)delete comp;}
    void set_component(Component *comp){
        this->comp=comp;
    }
    void operation(){
        if(comp)comp->operation();//关键，运行set_component所设置的行为
    }
};
//具体装饰类A，穿衣服
class ConcreteDecoratorA:public Decorator
{
public:
    void operation(){
        Decorator::operation();//执行之前的装饰
        cout<<"dress clothes"<<endl;//本装饰类自有的行动
    }
};
//具体装饰类B，穿裤子
class ConcreteDecoratorB:public Decorator
{
public:
    void operation(){
        Decorator::operation();//执行之前的装饰
        cout<<"dress trousers"<<endl;//本装饰类自有的行动
    }
};
//客户端代码,穿着函数
void clientDress(){
    ConcreteComponent man;
    ConcreteDecoratorA *decA=new ConcreteDecoratorA;
    ConcreteDecoratorB *decB=new ConcreteDecoratorB;
    decA->set_component(&man);//decA父类的comp设置成了man，operation为man的行为
    decB->set_component(decA);//decB父类的conp设置成了decA，operation为decA的行为
    decB->operation();//先运行祖先decA的operation，而A的operation则先要运行祖先man的。
    delete decA;//因此先man->opertion，再A->opertion，再B->opertion
    delete decB;//其实就是通过set_component每层改变comp为不同的实体装饰
}
