class Strategy
{
public:
    virtual double algorithm(double cash){//虚函数，用户实现多态
        return cash;
    }
};

class StrategyA:public Strategy
{
public:
    double algorithm(double cash){
        return 0.8*cash;//八折
    }
};

class StrategyB:public Strategy
{
public:
    double algorithm(double cash){
        return cash>=100?cash-30:cash;//满100减30
    }
};

class Context
{
    Strategy *stra;
public:
    void loadStrategy(Strategy *s){//加载算法
        stra=s;
    }
    double getResult(double cash,int mode){
        switch(mode){
            case 0:
                this->loadStrategy(new StrategyA);break;
            case 1:
                this->loadStrategy(new StrategyB);break;
            default:
                this->loadStrategy(new Strategy);
        }
        return stra->algorithm(cash);
    }
    Context(){stra=NULL;}
    ~Context(){if(stra)delete stra;}
};

//用户只需维护context类。如要增加算法，只需修改context类并给出新的算法类即可。
//用户接触不到算法，实现了算法与用户的隔离。修改算法的时候也无需修改用户代码
double clientFunction(double cash,int mode){
    Context context;
    return context.getResult(cash,mode);
}
