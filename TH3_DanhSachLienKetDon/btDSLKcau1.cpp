#include <iostream>
using namespace std;

//định nghĩa cấu trúc node
struct node {
	int info;
	struct node* next;
};

//tạo node mới
node* CreatNode(int x){
	node* p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}
//khởi tạo node rỗng
void init(node*& pHead) {
	pHead = NULL;
}

//kiểm tra danh sách rỗng
bool isEmpty(node*& pHead) {
	return pHead == NULL;
}

//duyệt danh sách
void traverse(node* pHead) {
	if (pHead == NULL) {
		cout << "Danh sach rong!";
	}
	else {
		while (pHead != NULL) {
			cout << pHead->info << " ";
			pHead = pHead->next;
		}
	}
}

//thêm vào cuối danh sách
void insertAfter(node*& pHead, int x) {
	node* temp = pHead;
	node* p = CreatNode(x);
	if (pHead == NULL) {
		pHead = p;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = p;
}

//xoá 1 số k trong danh sách
void remove(node*& pHead, int k) {
	if (pHead == NULL) return;
	if (pHead->info == k) {
		node* temp = pHead;
		pHead = temp->next;
		delete temp;
	}
	//node đứng trước phần tử cần xoá
	node* temp = pHead;
	while (temp->next != NULL && temp->next->info != k) {
		temp = temp->next;
	}
	if (temp->next != NULL) {
		node* kth = temp->next;//node thứ k
		temp->next = kth->next;
		delete kth;
	}
}
//thêm danh sách thứ 2 vào danh sách thứ nhất
void LinkedList(node*& pHead1, node*& pHead2) {
	if (pHead1 == NULL) {
		pHead1 = pHead2;
		pHead2 = NULL;
		return;
	}

	node* temp = pHead1;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = pHead2;
	pHead2 = NULL;
}

int main()
{
	node* pHead;
	init(pHead);
	node* list2;
	init(list2);

	int n; cout << "Kich thuoc danh sach 1: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cout << "Nhap phan tu can them vao cuoi: ";
		cin >> x;
		insertAfter(pHead, x);
	}
	int k; cout << "Nhap so k can xoa: "; cin >> k;
	remove(pHead, k);
	cout << "Danh sach sau khi xoa: ";
	traverse(pHead);
	cout << endl;

	int m; cout << "Kich thuoc danh sach 2: "; cin >> m;
	cout << "Nhap sach 2:" << endl;
	for (int i = 0; i < m; i++) {
		int x;
		cout << "Nhap phan tu: ";
		cin >> x;
		insertAfter(list2, x);
	}
	cout << "Danh sach 2: ";
	traverse(list2);
	cout << endl;

	LinkedList(pHead, list2);
	cout << "Danh sach khi da duoc them vao: ";
	traverse(pHead);
}
