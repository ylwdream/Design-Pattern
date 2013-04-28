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
class Product
{
    string partA;
    string partB;
public:
    void set_partA(string partA){
        this->partA=partA;
    }
    void set_partB(string partB){
        this->partB=partB;
    }
    void show_product(){
        cout<<partA<<" "<<partB<<endl;
    }
};
class Builder
{
public:
    virtual void set_partA()=0;
    virtual void set_partB()=0;
    virtual Product* get_product()=0;
};
class ProductBuilderA:public Builder
{
    Product *product;
    void set_partA(){//必须重写的纯虚函数
        product->set_partA("xx");//私有的，必须利用get_product调用
    }
    void set_partB(){//确保产品必须被定制
        product->set_partB("yy");
    }
public:
    ProductBuilderA(){
        product=new Product;
    }
    Product*get_product(){//修改此函数可以改变定制
        set_partA();
        set_partB();
        return product;
    }
};
void client(){
    Builder *builder=new ProductBuilderA;
    Product *A=builder->get_product();
    A->show_product();
    delete builder;
    delete A;
}
int main(){
    client();
    return 0;
}


