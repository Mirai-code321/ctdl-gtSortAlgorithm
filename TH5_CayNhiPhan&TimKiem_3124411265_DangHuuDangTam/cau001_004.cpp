#include <iostream>
using namespace std;
struct node
{
	int info;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

NODE* InsertNode(TREE &Root,int x) {
	if (Root == NULL) {
		NODE* p = new NODE;
		p->info = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		Root = p;
	}
	else {
		if (x < Root->info) {
			InsertNode(Root->pLeft, x);
		}
		else if (x > Root->info) {
			InsertNode(Root->pRight, x);
		}
	}
	return Root;
}


int DemNode(TREE Root){
	if (Root == NULL)
		return 0;
	int a = DemNode(Root->pLeft);
	int b = DemNode(Root->pRight);
	return (a + b + 1);
}

int TongNode(TREE Root){
	 if (Root == NULL)
		 return 0;
	 int a = TongNode(Root->pLeft);
	 int b = TongNode(Root->pRight);
	 return (a + b + Root->info);
}

float TrungBinhCong(TREE Root) {
	int s = TongNode(Root);
	int dem = DemNode(Root);
	if (dem == 0) return 0;
	return (float)s / dem;
}

int DemDuong(TREE Root){
	if (Root == NULL)
		 return 0;
	int a = DemDuong(Root->pLeft);
	int b = DemDuong(Root->pRight);
	if (Root->info > 0)
		 return (a + b + 1);
	return (a + b);
}

int TongDuong(TREE Root)
{
	if (Root == NULL)
		 return 0;
	int a = TongDuong(Root->pLeft);
	int b = TongDuong(Root->pRight);
	if (Root->info > 0)
		return (a + b + Root->info);
	return (a + b);
}

float TrungBinhDuong(TREE Root){
	int s = TongDuong(Root);
	int dem = DemDuong(Root);
	if (dem == 0)
		return 0;
	return (float)s / dem;
}

int DemAm(TREE Root) {
	if (Root == NULL) return 0;
	int a = DemAm(Root->pLeft);
	int b = DemAm(Root->pRight);
	if (Root->info < 0)
		return (a + b + 1);
	return (a + b);
}

int TongAm(TREE Root) {
	if (Root == NULL) return 0;
	int a = TongAm(Root->pLeft);
	int b = TongAm(Root->pRight);
	if (Root->info < 0)
		return (a + b + Root->info);
	return (a + b);
}

float TrungBinhAm(TREE Root) {
	int s = TongAm(Root);
	int dem = DemAm(Root);
	if (dem == 0) return 0;
	return (float)s / dem;
}

float TinhTySo(TREE Root) {
	int a = TongDuong(Root);
	int b = TongAm(Root);
	if (b == 0) return 0;
	return (float)a / b;
}

NODE* nhoNhat(TREE Root) {
	if (Root == NULL) return NULL;
	NODE* t = Root;
	while (t->pLeft)
		t = t->pLeft;
	return t;
}

NODE* lonNhat(TREE Root) {
	if (Root == NULL) return NULL;
	NODE* t = Root;
	while (t->pRight)
		t = t->pRight;
	return t;
}
int main()
{
	TREE Root = NULL;
	int x;
	int n; cout << "Nhap so luong node: "; cin >> n;
	cout << "Nhap node: ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		InsertNode(Root, x);
	}
	cout << "-------cau 1---------" << endl;
	cout << "So nut: " << DemNode(Root) << endl;
	cout << "Tong cac nut: " << TongNode(Root) << endl;
	cout << "Trung binh cong cac nut: " << TrungBinhCong(Root) << endl;
	cout << "So nut duong: " << DemDuong(Root) << endl;
	cout << "Tong cac nut duong: " << TongDuong(Root) << endl;
	cout << "Trung binh cong cac nut duong: " << TrungBinhDuong(Root) << endl;
	cout << "So nut am: " << DemAm(Root) << endl;
	cout << "Tong cac nut am: " << TongAm(Root) << endl;
	cout << "Trung binh cong cac nut am: " << TrungBinhAm(Root) << endl;
	cout << "Ty so tong cac nut duong va am: " << TinhTySo(Root) << endl;

	cout << "----------cau 4---------\n";
	NODE* min = nhoNhat(Root);
	NODE* max = lonNhat(Root);
	cout << "phan tu nho nhat: " << min->info << endl;
	cout << "phan tu lon nhat: " << max->info << endl;


	return 0;

}
