#include <iostream>
#include "../include/cdll.h"
using namespace std;

bool ListInit(CDLL &L) {
    L=new CDLN;
    L->next = L;
    L->prior = L;
    return true;
}
bool ListFill(CDLL &L) {
    if (!L) {
        cout << "链表不存在!\n";
        return false;
    }
    cout << "请输入元素数量:";
    int n;
    cin >> n;
	ElemType x;
    CDLN *tail = L;
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个元素\n";
        cin >> x;
        CDLN *N = new CDLN;
        N->data = x;
		tail->next = N;
        N->prior = tail;
        N->next = L;
        L->prior = N;
        tail = N;	
    }
    return true;
}
void PrintList(CDLL L){
    CDLN *p = L->next;
    int count=0;
    while (p != L) {
        cout << p->data << " ";
        count++;
        if (count%10 == 0) {
            cout << endl;
        }
        p=p->next;
    }
    cout << "\n打印完成!\n";
}
bool ListLink(CDLL &h1,CDLL &h2){
    if(!h1 || !h2){
        cout << "链表不存在!\n";
        return false;
    }
	CDLN *h1tail,*h2tail;
    h1tail = h1->prior;
    h2tail = h2->prior;
    h1tail->next = h2;
    h2->prior = h1tail;
    h2tail->next = h1;
    h1->prior = h2;
    return true;
}