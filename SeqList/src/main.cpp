#include <iostream>
#include <string>
#include "../include/Seqlist.h"
#include "Seqlist.cpp"
using namespace std;
int main(){
    SeqList L;
    cout << "请输入表的最大规模: ";
    int size;
    cin >> size;
    
    if(size <= 0){
        cout << "错误：表的大小必须大于0" << endl;
        return -1;
    }
    
    bool C=false;
    while(!C){
        ListInit(L,size);
        C=ListCheck(L);
        if(!C){
            cout << "列表为空，请重新输入元素！" << endl;
            DestroyList(L);
        }
    }
    
    cout << "\n=== 初始列表 ===" << endl;
    ListPrint(L);
    
    cout << "\n=== 删除最小元素 ===" << endl;
    bool S;
    int r=DelMin(L,S);
    if(S){
        cout << "被删除元素的值为" << r << "." << endl;
        ListPrint(L);
    }else{
        DestroyList(L);
        return 0;
    }
    
    cout << "\n=== 反转列表 ===" << endl;
    ListRev(L);
    ListPrint(L);
    
    cout << "\n=== 删除指定值的元素 ===" << endl;
    DelX(L);
    ListPrint(L);
    
    cout << "\n=== 删除指定范围内的元素 ===" << endl;
    if(!DelBet(L)){
        DestroyList(L);
        return -1;
    }
    ListPrint(L);
    DestroyList(L);
    cout << "\n程序执行完成" << endl;
    return 0;
}