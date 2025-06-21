#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef int ElemType;
typedef struct LNode{
	ElemType data;
    struct LNode *next;
}LNode,*LinkList;
bool InitList(LinkList &L);//初始化一个带头结点的单链表
int ListLength(LinkList L);//求单链表的表长
int GetElem(LinkList L,int p);//根据序号查找结点,p即所要使用的序号，r用来传出运行状况
LNode *LocateElem(LinkList L,ElemType x);//根据元素值查找对应结点
LNode *GetNode(LinkList L,int p);//获取指定位置的结点
bool ListInsert(LinkList &L);//在指定位置使用后插法插入一个元素
bool ListInsertH(LinkList &L);//在指定位置前方插入一个元素
bool NodeDelete(LinkList &L);//删除指定结点
LinkList ListCreateH(LinkList &L);//头插法建立单链表
LinkList ListCreateT(LinkList &L);//尾插法建立单链表
#endif //LINKEDLIST_H