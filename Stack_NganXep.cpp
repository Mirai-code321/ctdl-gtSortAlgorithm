#include <iostream>
using namespace std;


struct node {
    int data;
    node* pNext;
};
typedef struct node NODE;

NODE* khoitaonode(int& x) {
    NODE* p = new NODE();
    p->data = x;
    p->pNext = NULL;
    return p;
}

struct stack {
    NODE* pTop;
};
typedef struct stack STACK;

void khoitaostack(STACK& s) {
    s.pTop = NULL;
}

bool isEmpty(STACK s) {
    if (s.pTop == NULL) {
        return true;
    }
    return false;
}

bool Push(STACK& s, NODE* p) {
    if (p == NULL) {
        return false;
    }
    if (isEmpty(s)) {
        s.pTop = p;// node p la node dau tien trong danh sach
    }
    else {//neu stack khong rong
        p->pNext = s.pTop;// phan tu ma con tro p tro den la phan tu dau tien trong stack
        s.pTop = p;//cap nhat node dau tien
    }
    return true;
}

bool Pop(STACK& s, int& x) {
    if (isEmpty(s)) {
        return false;
    }
    else {
        NODE* p = s.pTop;
        x = p->data;
        s.pTop = s.pTop->pNext;
        delete p;
    }
    return true;
}

bool Top(STACK& s, int& x) {
    if (isEmpty(s)) {
        return false;
    }
    else {
        x = s.pTop->data;
        return true;
    }
}

void xuatstack(STACK& s) {
    while (!isEmpty(s)) {
        int x;
        Pop(s, x);
        cout << x << " ";
    }
}

void Menu(STACK& s) {
    while (true) {
        cout << "\n=====MENU=====";
        cout << "\n1.Them phan tu vao stack";
        cout << "\n2.Xuat cac phan tu trong stack";
        cout << "\n3.Lay phan tu dau tien ra de xem ";
        cout << "\n0.Thoat";
        cout << "\n==============";
        int lc; cout << "\nNhap lua chon: "; cin >> lc;
        if (lc < 0 || lc > 3) {
            cout << "lua chon khong hop le";
        }
        else if (lc == 1) {
            int x; cout << "Nhap 1 so nguyen can them vao stack: "; cin >> x;
            NODE* p = khoitaonode(x);
            Push(s, p);
        }
        else if (lc == 2) {
            xuatstack(s);
        }
        else if (lc == 3) {
            int x;
            Top(s, x);
            cout << "phan tu dau tien trong stack la: " << x << endl;
        }
        else {
            break;
        }
    }
}
int main()
{
    STACK s;
    khoitaostack(s);
    Menu(s);
    return 0;
}