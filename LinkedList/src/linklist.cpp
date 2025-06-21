#include "../include/LinkedList.h"
#include <iostream>
using namespace std;
bool ListInit(LinkList &L){
    L=new LNode;
    L->next=nullptr;
    return true;
}
int ListLength(LinkList L){
    int len=0;
    LNode *p=L;
    while(p->next!=nullptr){
        p=p->next;
        len++;
    }
    return len;
}
ElemType GetElem(LinkList L,int p,bool &r){
	int len=ListLength(L);
    LNode *N=L;
    if(p>len){
        r=false;
        throw "查找位置不合法！";
    }
    for(int j=0;j<=p;j++){
		N=N->next;
    }
    cout << "位于第" << p << "位的元素是" << N->data << endl;
    r=true;
    return N->data;
}