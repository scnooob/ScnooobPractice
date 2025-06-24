#include "../include/LinkedList.h"
#include <iostream>
#include <string>
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
    if(p>len || p<=0){
        throw "查找位置不合法！";
    }
    for(int j=0;j<p;j++){
		N=N->next;
    }
    cout << "位于第" << p << "位的元素是" << N->data << endl;
    return N->data;
}
LNode *LocateElem(LinkList L,ElemType x){
    LNode *p=L->next;
    int l=1;
    while(p!=nullptr && p->data!=x){
		p=p->next;
        l++;
    }
    if(p==nullptr){
        throw "单链表中不存在该值！";
    }
    cout << "元素" << x << "位于第" <<l <<"位." <<endl;
    return p;
}
LNode *GetNode(LinkList L,int p){
    if(p>ListLength(L)||p<=0){
        throw "选择的位置不合法！";
    }
    LNode *x=L;
    for(int j=0;j<p;j++){
		x=x->next;
    }
    return x;
}
bool ListInsert(LinkList &L){
    int l;
    cout << "请输入要插入的位置:" << endl;
    cin >> l;
    if(l>ListLength(L)+1||l<=0){
        throw "插入位置不合法！";
    }
    ElemType x;
    cout << "请输入要插入的值:" << endl;
    cin >> x;
    LNode *p;
    if(l == 1){
        p = L;
    } else {
        p = L;
        for(int j=0; j<l-1; j++){
            p = p->next;
        }
    }
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
    if(l>ListLength(L)||l<1){
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
        if(l>ListLength(L)||l<1){
        	throw "删除位置不合法！";
    	}
        LNode *prev;
        if(l == 1){
            prev = L;
        } else {
            prev = L;
            for(int j=0; j<l-1; j++){
                prev = prev->next;
            }
        }
        LNode *d=prev->next;
        prev->next=d->next;
        ElemType temp=d->data;
        delete d;
        d=nullptr;
        cout << "删除的结点的值为" << temp << "." << endl;
        return true;
    }else{
        ElemType x;
        cout << "请输入要删除的结点的值：" << endl;
        cin >> x;
		LNode *p=L;
        int l=1;
    	while(p->next!=nullptr && p->next->data!=x){
			p=p->next;
            l++;
    	}
    	if(p->next==nullptr){
        	throw "单链表中不存在该值！";
    	}
        LNode *d=p->next;
        p->next=d->next;
        delete d;
        cout << "删除的元素位于第" << l << "位." <<endl;
        return true; 
    }
    return false;
}
LinkList ListCreateH(LinkList &L){
    LNode *s;
    ElemType X;
    int l=0;
    string choose="y";
    while(choose!="n" && choose!="N"){
        s=new LNode;
        cout << "请输入一个值" << endl;
        cin >>X;
        s->data=X;
        s->next=L->next;
        L->next=s;
        l++;
        cout << "输入n以外的内容以继续输入内容(不区分大小写)." << endl;
        cin.ignore();
        getline(cin,choose);
    }
    cout << "创建完毕，共有" << l << "位数据！" << endl;
    return L;
}
LinkList ListCreateT(LinkList &L){
    LNode *s,*n=L;
    string choose="y";
    while(choose != "n" && choose != "N"){
        ElemType x;
        cout << "请输入要插入的值：" << endl;
        cin >> x;
        s=new LNode;
		s->data=x;
        s->next=nullptr;
		n->next=s;
        n=n->next;
        cout << "请问是否要继续输入？输入n以结束(不区分大小写)." << endl;
        cin.ignore();
        getline(cin,choose);
    }
    return L;
}
void ListPrint(LinkList L){
    if(L == nullptr || L->next == nullptr){
        cout << "链表为空";
        return;
    }
    LNode *s=L->next;
    int l=0;
	while(s!=nullptr){
        cout << s->data << " ";
        l++;
        s=s->next;
        if(l%10==0){
            cout << endl;
        }
    }
}
bool DelX(LinkList &L,ElemType x){
    LNode *s=L;
    LNode *d=s->next;
    int t=0;
    while(d!=nullptr){
        if(d->data==x){
            s->next=d->next;
            delete d;
            d=s->next;
            t++;
            continue;
        }
        if(d->next==nullptr){
            break;
        }
        s=s->next;
        d=s->next;
    }
    cout << "删除完成,共删除了" << t << "个值为" << x <<"的元素" << endl;
    return true;
}
bool DelMin(LinkList &L){
    if(L==nullptr||L->next==nullptr){
        throw runtime_error("链表为空！");
    }
    LNode *minPre,*pre,*cur;//minPre是指向已扫描过的结点中值最小的结点的前驱结点的指针，pre是指向扫描结点的前驱结点的指针，cur是用于扫描的指针
    cur=L->next;
    pre=L;
    minPre=L;
    while(cur!=nullptr){
    	if(cur->data < minPre->next->data){
            minPre=pre;
        }
        pre=cur;
        cur=cur->next;
    }
    LNode *minNode=minPre->next;
    minPre->next=minNode->next;
    cout << "已删除值最小的结点，该结点值为" << minNode->data << "." << endl;
    delete minNode;
    return true;
}
bool ListRevert(LinkList &L){
    if(L==nullptr || L->next==nullptr){
        throw runtime_error("链表为空！");
    }
    LNode *f=L->next;
    LNode *n;
    while(f->next!=nullptr){
		n=f->next;
        f->next=n->next;
        n->next=L->next;
        L->next=n;
    }
    cout << "逆置完成！" << endl;
    return true;
}
bool DelBet(LinkList &L,ElemType a,ElemType b){
    if(L==nullptr || L->next==nullptr){
        throw runtime_error("链表为空！");
    }
    LNode *cur,*pre;
    pre=L;
    cur=L->next;
    LNode *del;
    while(cur!=nullptr){
        if(cur->data<b && cur->data > a){
            del=cur;
            cur=cur->next;
            pre->next=cur;
            delete del;
            continue;
        }
        pre=cur;
        cur=cur->next;
    }
    return true;
}
bool SplitList(LinkList &C,LinkList &A,LinkList &B){
    if(C==nullptr||C->next==nullptr){
        throw runtime_error("链表为空！");
    }
    LNode *p=C->next;
    LNode *temp;
    LNode *a=A;
    int t=1;
    while(p!=nullptr){
		if(t%2==0){
            temp=p;
            p=p->next;
			temp->next=B->next;
            B->next=temp;
        }else{
            temp=p;
            p=p->next;
            temp->next=a->next;
            a->next=temp;
            a=a->next;
        }
        t++;
    }
    cout << "拆分完成" << endl;
    return true;
}
bool DelRep(LinkList &L);