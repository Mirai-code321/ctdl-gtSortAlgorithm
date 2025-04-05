#include <iostream>
using namespace std;


struct node {
	int data;
	node* Next;
};
node* Createnode(int x) {
	node* p = new node;
	if (p == NULL) {
		cout << "khong du bo nho de cap phat!" << endl;
		return NULL;
	}
	p->data = x;
	p->Next = NULL;
	return p;
}

struct stack {
	node* top;
};

void CreateStack(stack& s) {
	s.top = NULL;
}

bool isEmpty(stack& s) {
	if (s.top == NULL) {
		return true;
	}
	return false;
}

bool isFull(stack& s) {
	if (s.top != NULL) {
		return true;
	}
}

bool PushStack(stack& s, int x) {
	node* p = Createnode(x);
	if (p == NULL) {
		return false;
	}
	if (isEmpty(s)) {
		s.top = p;
	}
	else {
		p->Next = s.top;
		s.top = p;
	}
	return true;
}

bool PopStack(stack& s, int& x) {
	if (s.top == NULL) return false;
	node* p = s.top;
	x = p->data;
	s.top = s.top->Next;
	delete p;
	return true;
}

bool PeekStack(stack& s, int& x) {
	if (isEmpty(s)) return false;
	x = s.top->data;
	return true;
}

void XuatStack(stack s) {
	while (!isEmpty(s)) {
		int x;
		PopStack(s, x);
		cout << x << " ";
	}
}
int main() {
	stack s;
	CreateStack(s);
	int n; cout << "nhap so luong stack: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cout << "phan tu stack " << i + 1 << ": ";
		cin >> x;
		PushStack(s, x);
	}
	int x;
	if (PeekStack(s, x)) {
		cout << "Phan tu dau tien trong stack: " << x << endl;
	}
	else {
		cout << "stack rong" << endl;
	}
	XuatStack(s);

	return 0;
}