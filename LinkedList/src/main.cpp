#include "../include/LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    // 1. 头插法建立链表
    LinkList L = ListCreateH();
    cout << "初始链表（头插法）:" << endl;
    ListPrint(L);

    // 2. 求长度
    cout << "链表长度: " << ListLength(L) << endl;

    // 3. 插入元素
    int pos, val;
    cout << "测试插入: 请输入插入位置和值: ";
    cin >> pos >> val;
    if (ListInsert(L, pos, val)) {
        cout << "插入后链表: ";
        ListPrint(L);
    } else {
        cout << "插入失败！" << endl;
    }

    // 4. 删除元素
    cout << "测试删除: 请输入删除位置: ";
    cin >> pos;
    ElemType delVal;
    if (NodeDel(L, pos, delVal)) {
        cout << "删除值为" << delVal << "，删除后链表: ";
        ListPrint(L);
    } else {
        cout << "删除失败！" << endl;
    }

    // 5. 查找元素
    cout << "测试按位置查找: 请输入位置: ";
    cin >> pos;
    if (GetElem(L, pos, val)) {
        cout << "第" << pos << "个元素为: " << val << endl;
    } else {
        cout << "查找失败！" << endl;
    }

    // 6. 查找结点地址
    cout << "测试按值查找: 请输入值: ";
    cin >> val;
    LNode *node = LocateElem(L, val);
    if (node) {
        cout << "找到值为" << val << "的结点，地址: " << node << endl;
    } else {
        cout << "未找到该值" << endl;
    }

    // 7. 删除所有某值
    cout << "测试删除所有指定值: 请输入要删除的值: ";
    cin >> val;
    DelX(L, val);
    cout << "删除后链表: ";
    ListPrint(L);

    // 8. 逆置链表
    ListRevert(L);
    cout << "逆置后链表: ";
    ListPrint(L);

    // 9. 删除最小值结点
    if (DelMin(L, delVal)) {
        cout << "删除最小值" << delVal << "后链表: ";
        ListPrint(L);
    }

    // 10. 删除区间
    cout << "测试删除区间(a, b): 请输入a和b: ";
    int a, b;
    cin >> a >> b;
    DelBet(L, a, b);
    cout << "删除后链表: ";
    ListPrint(L);

    // 11. 删除重复元素
    DelRep(L);
    cout << "去重后链表: ";
    ListPrint(L);

    // 12. 尾插法建表测试
    LinkList LT = ListCreateT();
    cout << "尾插法建立链表: ";
    ListPrint(LT);

    // 13. 拆分偶数、奇数
    LinkList odd, even;
    SplitList(LT, odd, even);
    cout << "奇数项链表: ";
    ListPrint(odd);
    cout << "偶数项链表（逆序）: ";
    ListPrint(even);

    return 0;
}