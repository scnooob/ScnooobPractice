#ifndef CDLL_H
#define CDLL_H

typedef int ElemType;

typedef struct CDLN{
	ElemType data;
    struct CDLN *prior,*next;
}CDLN;

typedef CDLN *CDLL;

bool ListInit(CDLL &L);
//初始化循环双链表
bool ListFill(CDLL &L);
//向表中填充数据
void PrintList(CDLL L);
//打印整个表
bool ListLink(CDLL &h1,CDLL &h2);
//将h2链接到h1之后，并且仍保持循环链表形式
#endif //CDLL_H