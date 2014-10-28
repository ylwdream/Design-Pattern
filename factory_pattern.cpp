class oper
{
protected://使用保护成员，子类可以访问。子类不能访问私有成员
    double lhs;
    double rhs;
public:
    double virtual getResult()=0;//纯虚函数
    virtual ~oper();
    void set_lhs(double lhs){this->lhs=lhs;}
    void set_rhs(double rhs){this->rhs=rhs;}
};

class oper_add:public oper
{
public:
    double getResult(){
        return lhs+rhs;
    }
     ~oper_add(){}
};

class oper_minus:public oper
{
public:
    double getResult(){
        return lhs-rhs;
    }
    ~oper_minus(){}
};

class factory
{
    oper *op;
public:
    factory(){op=NULL;}
    ~factory(){if(op)delete op;}
    oper* createOperator(char oper_char){
        switch(oper_char){
            case '+':op=new oper_add;break;
            case '-':op=new oper_minus;break;
            default:cout<<"operator error"<<endl;
        }
        return op;
    }
};
//用户代码，计算器
double clientCounter(double lhs,double rhs,char oper_char){
    factory fac;
    oper *op=fac.createOperator(oper_char);
    if(op==NULL)return 0;
    op->set_lhs(lhs);
    op->set_rhs(rhs);
    return op->getResult();//使用父类指针调用纯虚函数实现多态
}
