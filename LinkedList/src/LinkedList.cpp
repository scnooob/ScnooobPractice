#include "../include/LinkedList.h"
#include <iostream>
#include <unordered_set>
using namespace std;

bool ListInit(LinkList &L) {
    L = new LNode;
    L->next = nullptr;
    return true;
}
int ListLength(LinkList L) {
    int len = 0;
    LNode *p = L->next;
    while (p) {
        p = p->next;
        len++;
    }
    return len;
}
bool GetElem(LinkList L,int p,ElemType &e) {
    if (p <= 0) return false;
    LNode *cur = L->next;
    int i = 1;
    while (cur && i < p) {
        cur = cur->next;
    }
    if (cur && i == p) {
        e = cur->data;
        return true;
    }
    return false;
}
LNode *LocateElem(LinkList L,ElemType x) {
    LNode *p = L->next;
    while (p) {
        if (p->data == x) return p;
        p = p->next;
    }
    return nullptr;
}
LNode *GetNode(LinkList L,int p) {
    if (p <= 0) return nullptr;
    LNode *cur = L;
    int i = 0;
    while (cur && i < p) {
        cur = cur->next;
        i++;
    }
    if (cur && i == p) return cur;
    return nullptr;
}
bool ListInsert(LinkList &L,int pos,ElemType x) {
    if (pos <= 0) return false;
    LNode *p = L;
    int i = 0;
    while (p && i < pos-1) {
		p = p->next;
        i++;
    }
    if (!p) return false;
    LNode *s = new LNode;
    s->data = x;
    s->next = p->next;
    p->next = s;
    return true;
}
bool ListInsertH(LinkList &L,int pos,ElemType x) {
    if(pos <= 0) return false;
    LNode *prev = L;
    int i = 0;
    while (prev && i < pos-1) {
        prev = prev->next;
        i++;
    }
    if (!prev || !prev->next) return false;
    LNode *s = new LNode;
    s->data = x;
    s->next = prev->next;
    prev->next = s;
    return true;
}
bool NodeDel(LinkList &L,int pos,ElemType &e) {
    if (pos <= 0) return false;
    LNode *p = L;
    int i = 0;
    while (p && 1 < pos-1) {
        p = p->next;
        i++;
    }
    if (!p || !p->next) return false;
    LNode *d = p->next;
    e = d->data;
    p->next = d->next;
    delete d;
    return true;
}
bool NodeDelByVal(LinkList &L,ElemType x) {
    LNode *p = L;
    while (p->next){
        if (p->next->data == x) {
            LNode *d = p->next;
            p->next = d->next;
            delete d;
            return true;
        }
        p = p->next;
    }
    return false;
}
LinkList ListCreateH() {
    cout << "开始使用头插法建立链表\n";
    LinkList L;
    ListInit(L);
    int n;
    cout << "请输入元素数量:\n";
    cin >> n;
    for (int j = 0;j < n;j++) {
        ElemType x;
        cout << "请输入元素:\n";
        cin >> x;
        LNode *s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
    }
    return L;
}
LinkList ListCreateT() {
    cout << "开始使用尾插法建立链表\n";
    LinkList L;
    ListInit(L);
    int n;
    cout << "请输入元素数量:\n";
    cin >> n;
    LNode *tail = L;
    for (int i = 0;i < n;i++) {
        ElemType x;
        cout << "请输入元素的值:\n";
        cin >> x;
        LNode *s = new LNode;
        s->data = x;
        s->next = nullptr;
        tail->next = s;
        tail = s;
    }
    return L;
}
void ListPrint(LinkList L) {
    if (!L || !L->next) {
        cout << "链表为空\n";
        return;
    }
    LNode *p = L->next;
    int cnt = 0;
	while (p) {
        cout << p->data << " ";
        cnt++;
        if (cnt%10 == 0) cout << endl;
        p = p->next;
    }
    cout << endl;
}
bool DelX(LinkList &L,ElemType x) {
    bool flag = false;
    LNode *p = L;
    while (p->next) {
        if (p->next->data == x) {
            LNode *del = p->next;
            p->next = del->next;
            delete del;
            flag = true;
        } else {
            p = p->next;
        }
    }
    return flag;
}
bool DelMin(LinkList &L,ElemType &minVal) {
    if (!L || !L->next) {
        cout << "链表为空!\n";
        return false;
    }
    LNode *minPre = L, *cur = L->next;
    minVal = cur->data;
    while (cur->next) {
    	if (cur->next->data < minVal) {
            minVal = cur->next->data;
            minPre = cur;
        }
        cur = cur->next;
    }
    LNode *minNode = minPre->next;
    minPre->next = minNode->next;
    minVal = minNode->data;
    delete minNode;
    return true;
}
bool ListRevert(LinkList &L) {
    if (!L || !L->next) return false;
    LNode *prev = nullptr, *cur = L->next, *next = nullptr;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    L->next = prev;
    return true;
}
bool DelBet(LinkList &L,ElemType a,ElemType b) {
    if (!L || !L->next) {
        cout << "链表为空!\n";
        return false;
    }
    LNode *cur = L->next, *pre = L;
    while (cur) {
        if (cur->data < b && cur->data > a) {
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
        } else {
        	pre = cur;
        	cur = cur->next;
        }
    }
    return true;
}
bool SplitList(LinkList C,LinkList &A,LinkList &B) {
    if (!C || !C->next) {
        cout << "链表为空!\n";
        return false;
    }
    LNode *p = C->next;
    LNode *temp;
    LNode *aTail = A;
    int t = 1;
    while (p) {
		if(t%2 == 0){
            temp = p;
            p = p->next;
			temp->next = B->next;
            B->next = temp;
        } else {
            temp = p;
            p = p->next;
            temp->next = aTail->next;
            aTail->next = temp;
            aTail = aTail->next;
        }
        t++;
    }
    cout << "拆分完成\n";
    return true;
}
bool DelRep(LinkList &L) {
    if (!L || !L->next) {
        cout << "链表为空!\n";
    }
    unordered_set<ElemType> st;
    LNode *p = L,*cur = L->next;
    while (cur) {
        if (st.count(cur->data)) {
            p->next = cur->next;
            delete cur;
            cur = p->next;
        } else {
            st.insert(cur->data);
            p = cur;
            cur = cur->next;
        }
    }
    return true;
}
LinkList MergeCommonElement(LinkList A,LinkList B) {
    if (!A || !B) {
        cout << "有链表不存在!\n";
    }
	LNode *a = A->next;
    LNode *b = B->next;
    LNode *i;
    LinkList C;
    ListInit(C);
    LNode *t = C;
    while (a && b) {
		if (a->data > b->data) {
            b = b->next;
        } else if (a->data < b->data) {
            a = a->next;
        } else {
            i = new LNode;
            i->data = a->data;
            t->next = i;
            i->next = nullptr;
			t = i;
            a = a->next;
            b = b->next;
        }
    }
    cout << "链表已生成." << endl;
    return C;
}
bool IntersectList(LinkList &A,LinkList B) {
    if (!A || !B) {
		cout << "链表不存在!\n";
        return false;
    }
    LNode *pre = A;
    LNode *cur = A->next;
    LNode *b = B->next;
    int len = 0;
    while (cur && b) {
        if (cur->data > b->data) {
            b = b->next;
        } else if (cur->data < b->data) {
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
        } else {
			pre = cur;
            cur = pre->next;
            b = b->next;
            len++;
        }
    }
    cout << "交集计算完毕，共有" << len << "位." << endl;
    return true;
}
bool IsSubarray(LinkList A,LinkList B) {
    if (!A || !B) {
        cout << "有链表不存在!\n";
    }
    if (!A->next || !B->next) {
        cout << "有链表为空!\n";
    }
    int al,bl;
    al = ListLength(A);
    bl = ListLength(B);
    if (al < bl) {
        return false;
    }
    LNode *a = a->next;
    LNode *b = b->next;
    int p = 0;
    while (al-p >= bl) {
        if (a->data==b->data) {
			while (b->next != nullptr) {
                b = b->next;
                if (a->data==b->data) {
					continue;
                } else {
                    break;
                }
            }
            if (b->next == nullptr) {
                return true;
            }
            b = B->next;
            a = a->next;
        } else if (a->next != nullptr) {
			a = a->next;
        } else {
            return false;
        }
    }
    return false;
}