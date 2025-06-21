#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef int ElemType;
typedef struct LNode{
	ElemType data;
    struct LNode *next;
}LNode,*LinkList;
bool InitList(LinkList &L);//初始化一个带头结点的单链表
int ListLength(LinkList L);//求单链表的表长
int GetElem(LinkList L,int p,bool &r);//根据序号查找结点,p即所要使用的序号，r用来传出运行状况



#endif //LINKEDLIST_H