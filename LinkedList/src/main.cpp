#include "../include/LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    LinkList L = nullptr;
    
    cout << "=== 链表功能测试程序 ===" << endl << endl;
    
    // 1. 测试初始化
    cout << "1. 测试初始化功能" << endl;
    if (ListInit(L)) {
        cout << "链表初始化成功！" << endl;
    } else {
        cout << "链表初始化失败！" << endl;
    }
    cout << "初始化后链表长度: " << ListLength(L) << endl;
    cout << "初始化后链表内容: ";
    ListPrint(L);
    cout << endl << endl;
    
    // 2. 测试头插法创建链表
    cout << "2. 测试头插法创建链表" << endl;
    cout << "即将使用头插法创建链表..." << endl;
    try {
        ListCreateH(L);
        cout << "头插法创建完成！" << endl;
        cout << "创建后链表长度: " << ListLength(L) << endl;
        cout << "创建后链表内容: ";
        ListPrint(L);
        cout << endl;
    } catch (const char* e) {
        cout << "创建过程中出现异常: " << e << endl;
    }
    cout << endl;
    
    // 3. 测试按位置查找元素
    cout << "3. 测试按位置查找元素功能" << endl;
    if (ListLength(L) > 0) {
        try {
            cout << "查找第1位的元素:" << endl;
            ElemType elem = GetElem(L, 1);
            cout << "查找成功！返回值: " << elem << endl;
        } catch (const char* e) {
            cout << "异常: " << e << endl;
        }
        
        if (ListLength(L) > 2) {
            try {
                cout << "查找第3位的元素:" << endl;
                ElemType elem = GetElem(L, 3);
                cout << "查找成功！返回值: " << elem << endl;
            } catch (const char* e) {
                cout << "异常: " << e << endl;
            }
        }
        
        try {
            cout << "查找第99位的元素（超出范围）:" << endl;
            ElemType elem = GetElem(L, 99);
        } catch (const char* e) {
            cout << "异常: " << e << endl;
        }
    } else {
        cout << "链表为空，跳过查找测试" << endl;
    }
    cout << endl;
    
    // 4. 测试按值查找元素
    cout << "4. 测试按值查找元素功能" << endl;
    if (ListLength(L) > 0) {
        try {
            // 先获取第一个元素的值进行查找测试
            ElemType firstElem = GetElem(L, 1);
            cout << "查找值为 " << firstElem << " 的元素:" << endl;
            LNode* node = LocateElem(L, firstElem);
            cout << "查找成功！" << endl;
        } catch (const char* e) {
            cout << "异常: " << e << endl;
        }
        
        try {
            cout << "查找值为 999 的元素（不存在）:" << endl;
            LNode* node = LocateElem(L, 999);
        } catch (const char* e) {
            cout << "异常: " << e << endl;
        }
    } else {
        cout << "链表为空，跳过查找测试" << endl;
    }
    cout << endl;
    
    // 5. 测试获取指定位置的结点
    cout << "5. 测试获取指定位置的结点功能" << endl;
    if (ListLength(L) > 0) {
        try {
            cout << "获取第1位的结点:" << endl;
            LNode* node = GetNode(L, 1);
            cout << "获取成功，结点数据为: " << node->data << endl;
        } catch (const char* e) {
            cout << "异常: " << e << endl;
        }
        
        try {
            cout << "获取第0位的结点（位置不合法）:" << endl;
            LNode* node = GetNode(L, 0);
        } catch (const char* e) {
            cout << "异常: " << e << endl;
        }
    } else {
        cout << "链表为空，跳过获取结点测试" << endl;
    }
    cout << endl;
    
    // 6. 测试后插法插入功能
    cout << "6. 测试后插法插入功能" << endl;
    cout << "插入前链表内容: ";
    ListPrint(L);
    cout << endl;
    cout << "插入前链表长度: " << ListLength(L) << endl;
    
    try {
        cout << "即将进行后插法插入..." << endl;
        if (ListInsert(L)) {
            cout << "后插法插入成功！" << endl;
            cout << "插入后链表内容: ";
            ListPrint(L);
            cout << endl;
            cout << "插入后链表长度: " << ListLength(L) << endl;
        }
    } catch (const char* e) {
        cout << "插入过程中出现异常: " << e << endl;
    }
    cout << endl;
    
    // 7. 测试前插法插入功能
    cout << "7. 测试前插法插入功能" << endl;
    cout << "插入前链表内容: ";
    ListPrint(L);
    cout << endl;
    cout << "插入前链表长度: " << ListLength(L) << endl;
    
    try {
        cout << "即将进行前插法插入..." << endl;
        if (ListInsertH(L)) {
            cout << "前插法插入成功！" << endl;
            cout << "插入后链表内容: ";
            ListPrint(L);
            cout << endl;
            cout << "插入后链表长度: " << ListLength(L) << endl;
        }
    } catch (const char* e) {
        cout << "插入过程中出现异常: " << e << endl;
    }
    cout << endl;
    
    // 8. 测试删除功能
    cout << "8. 测试删除功能" << endl;
    if (ListLength(L) > 0) {
        cout << "删除前链表内容: ";
        ListPrint(L);
        cout << endl;
        cout << "删除前链表长度: " << ListLength(L) << endl;
        
        try {
            cout << "即将进行删除操作..." << endl;
            if (NodeDelete(L)) {
                cout << "删除成功！" << endl;
                cout << "删除后链表内容: ";
                ListPrint(L);
                cout << endl;
                cout << "删除后链表长度: " << ListLength(L) << endl;
            }
        } catch (const char* e) {
            cout << "删除过程中出现异常: " << e << endl;
        }
    } else {
        cout << "链表为空，无法进行删除测试" << endl;
    }
    cout << endl;
    
    // 9. 测试尾插法创建新链表
    cout << "9. 测试尾插法创建新链表" << endl;
    LinkList L2 = nullptr;
    if (ListInit(L2)) {
        cout << "新链表L2初始化成功！" << endl;
        try {
            cout << "即将使用尾插法创建链表L2..." << endl;
            ListCreateT(L2);
            cout << "尾插法创建完成！" << endl;
            cout << "L2链表长度: " << ListLength(L2) << endl;
            cout << "L2链表内容: ";
            ListPrint(L2);
            cout << endl;
        } catch (const char* e) {
            cout << "创建过程中出现异常: " << e << endl;
        }
    }
    cout << endl;
    
    // 10. 最终状态展示
    cout << "10. 最终状态展示" << endl;
    cout << "链表L的最终状态:" << endl;
    cout << "  长度: " << ListLength(L) << endl;
    cout << "  内容: ";
    ListPrint(L);
    cout << endl;
    
    cout << "链表L2的最终状态:" << endl;
    cout << "  长度: " << ListLength(L2) << endl;
    cout << "  内容: ";
    ListPrint(L2);
    cout << endl;
    cout << endl;
    
    // 11. 异常情况测试
    cout << "11. 异常情况测试" << endl;
    
    // 测试空链表操作
    LinkList L3 = nullptr;
    ListInit(L3);
    cout << "空链表L3长度: " << ListLength(L3) << endl;
    cout << "空链表L3内容: ";
    ListPrint(L3);
    cout << endl;
    
    try {
        cout << "在空链表中查找第1位元素:" << endl;
        GetElem(L3, 1);
    } catch (const char* e) {
        cout << "异常: " << e << endl;
    }
    
    try {
        cout << "在空链表中查找值为10的元素:" << endl;
        LocateElem(L3, 10);
    } catch (const char* e) {
        cout << "异常: " << e << endl;
    }
    cout << endl;
    
    cout << "=== 链表功能测试程序结束 ===" << endl;
    cout << "注意: 程序结束后请手动清理内存以避免内存泄漏" << endl;
    
    return 0;
}