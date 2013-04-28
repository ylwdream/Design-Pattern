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
class Observer
{
public:
    virtual void update()=0;
};
class Subject
{
    int state;
    list<Observer*> observer_list;
public:
    void set_state(int new_state){
        this->state=new_state;
    }
    int get_state(){
        return this->state;
    }
    void add_observer(Observer* observer){
        observer_list.push_back(observer);
    }
    void del_observer(Observer* observer){
        observer_list.erase(find(observer_list.begin(),observer_list.end(),observer));
    }
    void notify(){
        for(list<Observer*>::iterator it=observer_list.begin();it!=observer_list.end();++it){
            (*it)->update();//由subject统一更新observer
        }
    }
};
class concreteObserverA:public Observer
{
public:
    void update(){
        cout<<"concreteObserverA is updated"<<endl;
    }
};
class concreteObserverB:public Observer
{
public:
    void update(){
        cout<<"concreteObserverB is updated"<<endl;
    }
};
void client(){
    Observer *observerA=new concreteObserverA;
    Observer *observerB=new concreteObserverB;
    Subject *subject=new Subject;
    subject->add_observer(observerA);
    subject->add_observer(observerB);
    subject->set_state(1);
    if(subject->get_state()){//如果状态改变了，所有的observer需要协同改变
        subject->notify();
    }
    delete observerA;
    delete observerB;
    delete subject;
}
int main(){
    client();
    return 0;
}


