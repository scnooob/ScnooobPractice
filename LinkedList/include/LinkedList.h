#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef int ElemType;
typedef struct LNode{
	ElemType data;
    LNode *next;
}LNode;
typedef LNode *LinkList;


bool ListInit(LinkList &L);//初始化
int ListLength(LinkList L);//求长度
bool GetElem(LinkList L,int p,ElemType &e);//查找第p个元素
LNode *LocateElem(LinkList L,ElemType x);//按值查找结点
LNode *GetNode(LinkList L,int p);//获取第p个结点指针
bool ListInsert(LinkList &L,int pos,ElemType x);//在pos处插入x
bool ListInsertH(LinkList &L,int pos,ElemType x);//在pos前插入x
bool NodeDel(LinkList &L,int pos,ElemType &e);//删除第pos个结点，返回结点的值
bool NodeDelByVal(LinkList &L,ElemType x);//按值删除结点
LinkList ListCreateH();//头插法建表
LinkList ListCreateT();//尾插法建表
void ListPrint(LinkList L);//打印链表
bool DelX(LinkList &L,ElemType x);//删除所有值为x的结点
bool DelMin(LinkList &L,ElemType &minVal);//删除最小值结点并返回该值
bool ListRevert(LinkList &L);//就地逆置
bool DelBet(LinkList &L,ElemType a,ElemType b);//删除值介于两个参数之间的结点
bool SplitList(LinkList C,LinkList &A,LinkList &B);//将单链表拆分为两个单链表，A里是奇数项，B里是偶数项且逆置
bool DelRep(LinkList &L);//删除重复元素
LinkList MergeCommonElement(LinkList A,LinkList B,LinkList &C);//从两个元素递增有序的链表的公共元素中产生新的单链表
bool IntersectList(LinkList &A,LinkList B);//求两个代表集合的有序单链表的交集，并存放到第一个链表中
bool IsSubarray(LinkList A,LinkList B);//判断第二个序列是否是第一个序列的连续子序列
#endif //LINKEDLIST_H