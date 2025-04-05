#include <iostream>
using namespace std;
//cài đặt cấu trúc dữ liệu hàng đợi bằng mảng 1 chiều
int a[10000], maxN = 10000;
int n = 0;

int size() {
	return n;
}

bool empty() {
	return n == 0;
}

void push(int x) {
	if (n == maxN) return;
	a[n] = x; n++;
}

void pop() {
	if (n == 0) return;
	for (int i = 0; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n--;
}

int peek() {
	return a[0];
}
//cài đặt queue bằng danh sách liên kết
struct node {
	int data;
	struct node* Next;
};

node* CreateNode(int x) {
	node* p = new node();
	p->data = x;
	p->Next = NULL;
	return p;
}

void push2(node*& queue, int x) {
	node* p = CreateNode(x);
	if (queue == NULL) {
		queue = p; return;
	}
	node* temp = queue;
	while (temp->Next != NULL) {
		temp = temp->Next;
	}
	temp->Next = p;
}

void pop2(node*& queue) {
	if (queue == NULL) return;
	node* temp = queue;
	queue = queue->Next;
	delete temp;
}

int size2(node* queue) {
	int count = 0;
	while (queue != NULL) {
		count++;
		queue = queue->Next;
	}
	return count;
}

bool empty2(node* queue) {
	return queue == NULL;
}

int peek2(node* queue) {
	return queue->data;
}

void duyet(node* queue) {
	while (queue != NULL) {
		cout << queue->data << " ";
		queue = queue->Next;
	}
}
int main(){
	node* queue = NULL;
	while (1) {
		cout << "-------------";
		cout << "\n1.Push";
		cout << "\n2.Pop";
		cout << "\n3.Size";
		cout << "\n4.Peek";
		cout << "\n5.Empty";
		cout << "\n6.Duyet";
		cout << "\n0.Thoat";
		cout << "\n-------------";
		int lc; cout << "\nnhap lua chon: "; cin >> lc;
		if (lc == 1) {
			int x; cout << "nhap phan tu can them: "; cin >> x;
			push2(queue,x);
		}
		else if (lc == 2) {
			pop2(queue);
		}
		else if (lc == 3) {
			cout << size2(queue) << endl;;
		}
		else if (lc == 4) {
			cout << peek2(queue) << endl;;
		}
		else if (lc == 5) {
			if (empty2(queue))
				cout << "rong!" << endl;
			else {
				cout << "hang doi dang co phan tu" << endl;
			}
		}
		else if(lc==6){
			duyet(queue);
			cout << endl;
		}
		else {
			break;
		}
	}
	return 0;
}

