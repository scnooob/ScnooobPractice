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
ElemType GetElem(LinkList L,int p){
	int len=ListLength(L);
    LNode *N=L;
    if(p>len){
        throw "查找位置不合法！";
    }
    for(int j=0;j<=p;j++){
		N=N->next;
    }
    cout << "位于第" << p << "位的元素是" << N->data << endl;
    return N->data;
}
LNode *LocateElem(LinkList L,ElemType x){
    LNode *p=L->next;
    int l=1;
    while(p->data!=x && p->next!=nullptr){
		p=p->next;
        l++;
    }
    if(p->next==nullptr && p->data!=x){
        throw "单链表中不存在该值！";
    }
    cout << "元素" << x << "位于第" <<l <<"位." <<endl;
    return p;
}
LNode *GetNode(LinkList L,int p){
    if(p>ListLength(L)){
        throw "选择的位置不合法！";
    }
    LNode *x=L;
    for(int j=0;j<p-1;j++){
		x=x->next;
    }
    return x;
}
bool ListInsert(LinkList &L){
    int l;
    cout << "请输入要插入的位置:" << endl;
    cin >> l;
    if(l>ListLength(L)){
        throw "插入位置不合法！";
    }
    ElemType x;
    cout << "请输入要插入的值:" << endl;
    cin >> x;
    LNode *p=GetNode(L,l);
    LNode *s=new LNode;
	s->data=x;
    s->next=p->next;
    p->next=s;
    return true;
}
bool ListInsertH(LinkList &L){
    int l;
    cout << "请输入要插入的位置:" << endl;
    cin >> l;
    if(l>ListLength(L)){
        throw "插入位置不合法！";
    }
	ElemType x;
    cout << "请输入想插入的元素的值:" << endl;
    cin >> x;
    LNode *a=GetNode(L,l);
	LNode *s=new LNode;
    s->next=a->next;
    s->data=a->data;
    a->data=x;
    a->next=s;
    return true;
}
bool NodeDelete(LinkList &L){
    char choose;
    cout << "请选择是按位置删除结点还是按值删除结点，输入a以按位置删除，输入其他以按值删除" << endl;
    cin >> choose;
    if(choose=='a'){
        int l;
        cout << "请输入要删除的结点所处的位置：" << endl;
        cin >> l;
        if(l>ListLength(L)){
        	throw "删除位置不合法！";
    	}
		LNode *a=GetNode(L,l);
        LNode *d=a->next;
        a->next=d->next;
        ElemType temp=d->data;
        delete(d);
        cout << "删除的结点的值为" << temp << "." << endl;
        return true;
    }else{
        ElemType x;
        cout << "请输入要删除的结点的值：" << endl;
        cin >> x;
		LNode *p=L;
        int l=1;
    	while(p->next->data!=x && p->next!=nullptr){
			p=p->next;
            l++;
    	}
    	if(p->next==nullptr && p->data!=x){
        	throw "单链表中不存在该值！";
    	}
        LNode *d=p->next;
        p->next=d->next;
        cout << "删除的元素位于第" << l << "位." <<endl;
        return true; 
    }
    return false;
}