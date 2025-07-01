#ifndef DLISTN_H
#define DLISTN_H
typedef int ElemType;
typedef struct DNode{
	ElemType data;
    struct DNode *prior,*next;
    int freq;
}DNode,*DList;

bool DListInit(DList &L);
DNode *Locate(DList &L,ElemType x);
bool ListFill(DList &L);
#endif //DLISTN_H
