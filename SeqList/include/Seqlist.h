#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>
#include <string>
using namespace std;
#define ElemType int
typedef struct SeqList{
    ElemType *data;
    int MaxSize,length;
}SeqList;
int SearchElem(SeqList L,ElemType a);
int SearchMin(SeqList L);
int DelMin(SeqList &L,bool &S);
bool ListInit(SeqList &L,int size);
bool ListCheck(SeqList L);
void ListPrint(SeqList L);
void ListRev(SeqList &L);
void DelX(SeqList &L);
bool DelBet(SeqList &L);
SeqList ListMerge(SeqList L,SeqList K);
void DestroyList(SeqList &L);
#endif // SEQLIST_H