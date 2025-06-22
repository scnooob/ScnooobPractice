#ifndef DLINK_H
#define DLINK_H
typedef int ElemType;
typedef struct DNode{
	ElemType data;
    struct DNode *prior,*next;
}DNode,*DList;
struct Result{
	ElemType x;
    DNode *r;
};
bool DListInit(DList &L);//初始化一个带头结点的双链表
Result GetElem(DList L,int p);//根据位置查找结点的值，使用结构体返回结点与值 
DNode *LocateElem(DList L,ElemType x);//根据给定的值查找结点，并返回该结点
bool DListInsert(DNode &P,ElemType x);//在给定的结点前方或后方插入给定值的结点
bool NodeDel(DNode &P);//删除给定的结点
bool DListCH(DList &L);//使用头插法建立双链表
bool DListCT(DList &L);//使用尾插法建立双链表
void PrintList(DList L);//打印整个表
void DestroyList(DList &L);//删除链表
#endif //DLINK_H