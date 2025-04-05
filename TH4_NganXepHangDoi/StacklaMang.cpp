#include <iostream>
using namespace std;

//Stack là một mảng
struct StackInt {
	int top;
	int count;
	int size;
	int* arr;
};
typedef struct StackInt stack;
void Intit(stack& s, int size) {
	s.top = -1;
	s.count = 0;
	s.size = size;
	s.arr = new int[s.size];
}

bool isEmpty(stack& s) {
	return s.top == -1;
}

bool isFull(stack& s) {
	return s.top == s.size - 1;
}

void PushStack(stack& s, int x) {
	if (isFull(s)) {
		cout << "Stack bi day, khong the them phan tu!" << endl;
		return;
	}
	s.top++;
	s.arr[s.top] = x;
	s.count++;
	return;
}

int PopStack(stack& s) {
	if (isEmpty(s)) {
		cout << "Stack dang rong, khong the lay phan tu!" << endl;
		return -1;
	}
	int x = s.arr[s.top];
	s.top--;
	s.count--;
	return x;
}

int PeekStack(stack& s) {
	if (isFull(s)) {
		cout << "Stack bi day, khong the xem phan tu!" << endl;
	}
	return s.arr[s.top];
}

void Clear(stack& s) {
	s.top = -1;
	s.count = 0;
}

void DeleteStack(stack& s) {
	s.top = -1;
	s.count = 0;
	s.size = 0;
	delete[] s.arr;
}
int main()
{
	stack s;
	Intit(s,1000000000);
	PushStack(s, 10);
	PushStack(s, 20);
	PushStack(s, 30);
	PushStack(s, 40);
	int x; cout << "Nhap x: "; cin >> x;
	PushStack(s, x);

	cout << "Peek sau khi Push: " << PeekStack(s) << endl;

	cout << "Cac phan tu trong danh sach: ";
	while (!isEmpty(s)) {
		cout << PopStack(s) << " ";
	}
	DeleteStack(s);
	return 0;
}

