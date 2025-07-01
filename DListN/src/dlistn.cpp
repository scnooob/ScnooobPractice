#include <iostream>
#include "../include/dlistn.h"
using namespace std;

bool DListInit(DList &L) {
    L->next = nullptr;
    L->prior = nullptr;
    return true;
}
bool ListFill(DList &L) {
    DNode *tail = L;
    cout << "请输入元素数量:\n";
    int n;
    cin >> n;
    DNode *temp;
    ElemType x;
    for (int j = 0;j < n;j++) {
        temp = new DNode;
        cout << "请输入第" << j+1 << "个元素的值:\n";
        cin >> x;
        temp->data = x;
        temp->next = nullptr;
        temp->prior = tail;
        tail->next = temp;
        temp->freq = 0;
        tail = temp;
        L->prior = tail;
    }
    cout << "链表填充完成!\n";
    return true;
}
DNode *Locate(DList &L,ElemType x) {
    if (!L || !L->next) {
        throw runtime_error("链表为空!");
    }
    DNode *p = L,*pre;
    while (p && p->data != x) {
		p=p->next;
    }
    if (!p) {
        throw runtime_error("链表中不存在该值!");
    } else {
        p->freq++;
		if (p->prior == L || p->prior->freq > p->freq) return p;
        if (p->next != nullptr) p->next->prior = p->prior;
        p->prior->next = p->next;
        pre = p->prior;
        while (p != L && pre->freq < p->freq) {
            pre = pre->prior;
            p->next = pre->next;
            if (pre->next != nullptr) pre->next->prior = p;
            p->prior = pre;
            pre->next =p;
        }    
    }
    return p;
}