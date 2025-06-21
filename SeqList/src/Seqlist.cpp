#include "../include/Seqlist.h"
using namespace std;
int SearchElem(SeqList L,ElemType a){
    for(int p=0;p<L.length;p++){
        if(L.data[p]==a){
            cout << "已找到值为" << a << "的元素，位于第" << p+1 << "位." << endl; 
            return p+1;
        }
    }
    cout << "此表中不存在该值" << endl;
    return -1;
}

int SearchMin(SeqList L){
    if(L.length == 0){
        cout << "表为空！" << endl;
        return -1;
    }
    
    int m=0;
    int min=L.data[0];
    for(int p=0;p<L.length;p++){
        if(L.data[p]<min){
            min = L.data[p];
            m=p;
        }
    }
    cout << "最小元素是" << min << ",位于第" << m+1 << "位." <<endl;
    return min;
}

int DelMin(SeqList &L,bool &S){
    if(L.length==0){
        cout << "表为空！" << endl;
        S=false;
        return -1;
    }
    int m=0;
    int min=L.data[0];
    for(int p=0;p<L.length;p++){
        if(L.data[p]<min){
            min = L.data[p];
            m=p;
        }
    }
    L.data[m]=L.data[L.length-1];
    L.length--;
    S=true;
    return min;
}

bool ListInit(SeqList &L,int size){
    L.data=new ElemType[size];
    if(L.data == nullptr){
        cout << "内存分配失败！" << endl;
        return false;
    }
    
    L.MaxSize=size;
    L.length=0;
    ElemType x;
    string input;
    string ExitCommand="quit";
    
    for(int j=0;j<L.MaxSize;j++){
        cout << "请输入第" << j+1 <<"个元素的值: ";
        cin >>x;
        L.data[j]=x;
        L.length++;
        cout << "输入'" << ExitCommand << "'以退出(区分大小写)，直接回车继续: ";
		cin.ignore();
        getline(cin,input);

        if(input==ExitCommand){
            cout << "退出循环" << endl;
            break;
        }
    }
    return true;
}

bool ListCheck(SeqList L){
    if(L.length==0){
        return false;
    }
    return true;
}

void ListPrint(SeqList L){
    if(L.length == 0){
        cout << "列表为空" << endl;
        return;
    }
    
    cout << "当前列表内容 (长度=" << L.length << "): ";
    int i=0;
    for(int j=0;j<L.length;j++){
        cout << L.data[j] << " ";
        i++;
        if(i%5==0){
            cout << endl << "                    ";  // 对齐
        }
    }
    cout << endl;
}

void ListRev(SeqList &L){
    ElemType temp;
    for(int j=0;j<(L.length/2);j++){
        temp=L.data[j];
        L.data[j]=L.data[L.length-1-j];
        L.data[L.length-1-j]=temp;
    }
    cout << "列表已反转" << endl;
}

void DelX(SeqList &L){
    int x;
    cout << "请输入你想要删除的值: ";
    cin >> x;
    int k=0;
    for(int j=0;j<L.length;j++){
        if(L.data[j]==x){
            k++;
        }else{
            L.data[j-k]=L.data[j];
        }
    }
    L.length -= k;
    cout << "删除了 " << k << " 个值为 " << x << " 的元素" << endl;
}

bool DelBet(SeqList &L){
    if(L.length==0){
        cout << "表为空！"<<endl;
        return false;
    }
    int s,t;
    cout << "请输入s的值: ";
    cin>>s;
    cout << "请输入t的值: ";
    cin>>t;
    if(s>=t){
        cout << "s的值需要小于t！" << endl;
        return false;
    }
    int k=0;
    for(int j=0;j<L.length;j++){
        if(L.data[j]<=t && L.data[j]>=s){
            k++;
        }else{
            L.data[j-k]=L.data[j];
        }
    }
    L.length -= k;
    cout << "删除了 " << k << " 个在范围 [" << s << ", " << t << "] 内的元素" << endl;
    return true;
}
SeqList ListMerge(SeqList L,SeqList K){
    int l=0,k=0,m=0;
    SeqList M;
    M.length=0;
    M.data=new ElemType[L.length+K.length];
    M.MaxSize=L.length+K.length;
    while(l<L.length && k<K.length){
        if(L.data[l]<=K.data[k]){
			M.data[m++]=L.data[l++];
        }else{
            M.data[m++]=K.data[k++];
        }
    }
    while (l < L.length) {
        M.data[m++] = L.data[l++];
    }
    while (k < K.length) {
        M.data[m++] = K.data[k++];
    }
    M.length=m;
    return M;
}
void DestroyList(SeqList &L){
    if(L.data != nullptr){
        delete[] L.data;
        L.data = nullptr;
        L.length = 0;
        L.MaxSize = 0;
    }
}