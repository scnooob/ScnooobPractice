#include "../include/dlink.h"
#include <iostream>
#include <string>
using namespace std;
bool DListInit(DList &L){
    L=new DNode;
    L->next=nullptr;
    L->prior=nullptr;
    return true;
}
Result GetElem(DList L,int p){
	DNode *s=L;
    Result result;
    for(int j=0;j<p-1;j++){
        if(s==nullptr){
            throw runtime_error("该位置不合法");
        }
        s=s->next;
    }
    result.x=s->data;
    result.r=s;
    cout << "成功找到位于第" << p << "位的结点，该节点的值为" << s->data << "." << endl;
    return result;
}
DNode *LocateElem(DList L,ElemType x){
    DNode *s=L->next;
    int l=1;
    while(s!=nullptr && s->data!=x){
        s=s->next;
        l++;
    }
    if(s==nullptr || s->data!=x){
        throw runtime_error("该元素不存在于该表！");
    }
	cout << "第一个具有该值的结点位于第" << l << "位." << endl;
    return s;
}
bool DListInsert(DNode *P,ElemType x){
    DNode *n=new DNode;
    n->data=x;
    cout << "输入1以在该结点前方插入结点，输入其他在该节点后方插入." << endl;
    string choose="0";
    cin.ignore();
    getline(cin,choose);
    if(choose=="1"){
        if(P->prior==nullptr){
            throw runtime_error("该节点的前方无法插入结点！");
        }
        n->prior=P->prior;
        n->next=P;
        n->prior->next=n;
        P->prior=n;
    }else{
        if(P->next!=nullptr){
        	n->next=P->next;
        	P->next=n;
        	n->prior=P;
        	n->next->prior=n;
        }else{
            P->next=n;
            n->prior=P;
            n->next=nullptr;
        }
    }
    cout << "插入完成！" << endl;
    return true;
}
bool NodeDel(DNode *P){
    if(P==nullptr){
        throw runtime_error("该结点不存在！");
    }
    DNode *p=P->prior;
    DNode *n=P->next;
    if(p!=nullptr && n!=nullptr){
    	p->next=n;
    	n->prior=p;
    }else if(p==nullptr){
		throw runtime_error("不能删除头结点！");
    }else{
        p->next=nullptr;
    }
    delete P;
    P=nullptr;
    return true;
}
bool DListCH(DList &L){
    DNode *s;
    string choose="y";
    ElemType x;
    while(choose !="n" && choose != "N"){
        s=new DNode;
        cout << "请输入结点的值:" << endl;
        cin >> x;
        s->data=x;
        s->prior=L;
        if(L->next==nullptr){
            s->next=nullptr;
            L->next=s;
        }else{
            s->next=L->next;
            L->next->prior=s;
            L->next=s;
        }
        cout << "是否继续填充结点?输入n以结束填充." << endl;
        cin.ignore();
        getline(cin,choose);
    }
    return true;
}
bool DListCT(DList &L){
	DNode *s,*t;
    t=L;
    string choose="y";
    ElemType x;
    while(choose != "n" && choose != "N"){
        s=new DNode;
        cout << "请输入结点的值:" << endl;
        cin >> x;
        s->data=x;
        s->prior=t;
        t->next=s;
        s->next=nullptr;
        t=t->next;
        cout << "是否继续填充结点?输入n以结束填充." << endl;
        cin.ignore();
        getline(cin,choose);
    }
    return true;
}
void PrintList(DList L){
    DNode *s=L->next;
    int t=0;
    cout << "==========开始打印==========" << endl;
    while(s!=nullptr){
		cout << s->data << " ";
        t++;
        s=s->next;
        if(t%5==0){
            cout << endl;
        }
    }
    cout << endl;
    cout << "==========打印结束==========" << endl;
}
void DestroyList(DList &L){
    if(L->next==nullptr){
		delete L;
        L=nullptr;
        return;
    }
    DNode *d=L->next;
    while(d->next!=nullptr){
        d=d->next;
    }
    DNode *t;
    while(d!=L){
		t=d;
        d=d->prior;
        delete t;
        t=nullptr;
        d->next=nullptr;
    }
    delete L;
    L=nullptr;
    cout << "删除完成." << endl;
    return;
}