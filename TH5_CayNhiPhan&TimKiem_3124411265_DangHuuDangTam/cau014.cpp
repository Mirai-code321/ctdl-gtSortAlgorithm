#include <iostream>
using namespace std;

// Định nghĩa cấu trúc cây nhị phân tìm kiếm (BST)
struct nodetree {
    int info;
    struct nodetree* pLeft;
    struct nodetree* pRight;
};
typedef struct nodetree NODETREE;
typedef NODETREE* TREE;

// Định nghĩa cấu trúc danh sách liên kết đơn
struct nodelist {
    int info;
    struct nodelist* pNext;
};
typedef struct nodelist NODELIST;

struct list {
    NODELIST* pHead;
    NODELIST* pTail;
};
typedef struct list LIST;

// Khởi tạo danh sách liên kết rỗng
void Init(LIST& l) {
    l.pHead = l.pTail = NULL;
}

// Tạo một node mới cho danh sách liên kết
NODELIST* GetNode(int x) {
    NODELIST* p = new NODELIST;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

// Thêm node vào cuối danh sách liên kết
void AddTail(LIST& l, NODELIST* p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// Hàm duyệt cây theo thứ tự RNL (giảm dần) và lưu vào danh sách liên kết
void RNL(TREE Root, LIST& l) {
    if (Root == NULL)
        return;
    RNL(Root->pRight, l);
    NODELIST* p = GetNode(Root->info);
    if (p != NULL)
        AddTail(l, p);
    RNL(Root->pLeft, l);
}

// Xây dựng danh sách liên kết từ cây BST theo thứ tự RNL
void BuildList(TREE Root, LIST& l) {
    Init(l);
    RNL(Root, l);
}

// Hiển thị danh sách liên kết
void PrintList(LIST l) {
    NODELIST* p = l.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

// Hàm tạo một node mới cho cây BST
NODETREE* CreateNode(int x) {
    NODETREE* p = new NODETREE;
    if (p != NULL) {
        p->info = x;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}

void Insert(TREE& t, int x) {
    if (t == NULL) {
        t = CreateNode(x);
    }
    else {
        if (x < t->info)
            Insert(t->pLeft, x);
        else
            Insert(t->pRight, x);
    }
}

int main() {
    TREE root = NULL;
    LIST l;

    Insert(root, 10);
    Insert(root, 5);
    Insert(root, 15);
    Insert(root, 3);
    Insert(root, 7);
    Insert(root, 12);
    Insert(root, 18);

    BuildList(root, l);

    cout << "Danh sach lien ket theo thu tu giam dan: ";
    PrintList(l);

    return 0;
}
