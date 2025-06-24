#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef int ElemType;
typedef struct LNode{
	ElemType data;
    struct LNode *next;
}LNode,*LinkList;
bool ListInit(LinkList &L);//初始化一个带头结点的单链表
int ListLength(LinkList L);//求单链表的表长
ElemType GetElem(LinkList L,int p);//根据序号查找结点,p即所要使用的序号
LNode *LocateElem(LinkList L,ElemType x);//根据元素值查找对应结点
LNode *GetNode(LinkList L,int p);//获取指定位置的结点
bool ListInsert(LinkList &L);//在指定位置使用后插法插入一个元素
bool ListInsertH(LinkList &L);//在指定位置前方插入一个元素
bool NodeDelete(LinkList &L);//删除指定结点
LinkList ListCreateH(LinkList &L);//头插法建立单链表
LinkList ListCreateT(LinkList &L);//尾插法建立单链表
void ListPrint(LinkList L);//打印整个链表内容
bool DelX(LinkList &L,ElemType x);//删除所有值为x的结点并释放空间
bool DelMin(LinkList &L);//删除一个最小值结点
bool ListRevert(LinkList &L);//就地逆置
bool DelBet(LinkList &L,ElemType a,ElemType b);//删除值介于给定的两个参数之间的结点
bool SplitList(LinkList &C,LinkList &A,LinkList &B);//将C拆分为A和B两个单链表，a里是奇数项，b里是偶数项且顺序倒过来
bool DelRep(LinkList &L);//删除链表中重复的元素
#endif //LINKEDLIST_H