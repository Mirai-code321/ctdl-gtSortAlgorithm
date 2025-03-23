#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* pLeft;
	struct node* pRight;
};
typedef node NODE;
typedef NODE* TREE;

void KhoiTao(TREE& t) {
	t = NULL;
}

void ThemNodeCay(TREE& t, int x) {
	if (t == NULL) {
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if (t->data > x) {
			ThemNodeCay(t->pLeft, x);//duyet qua trai cay
		}
		else if (t->data < x) {
			ThemNodeCay(t->pRight, x);//duyet qua phai cay
		}
	}
}

void DuyetNLR(TREE t) {
	if (t != NULL) {
		cout << t->data << " ";
		DuyetNLR(t->pLeft);
		DuyetNLR(t->pRight);
	}
}

void duyetNRL(TREE t) {
	if (t != NULL) {
		cout << t->data << " ";
		duyetNRL(t->pRight);
		duyetNRL(t->pLeft);
	}
}

void duyetLNR(TREE t) {
	if (t != NULL) {
		duyetLNR(t->pLeft);
		cout << t->data << " ";
		duyetLNR(t->pRight);
	}
}

void duyetRNL(TREE t) {
	if (t != NULL) {
		duyetRNL(t->pRight);
		cout << t->data << " ";
		duyetRNL(t->pLeft);
	}
}

void duyetLRN(TREE t) {
	if (t != NULL) {
		duyetLRN(t->pLeft);
		duyetLRN(t->pRight);
		cout << t->data << " ";
	}
}

void duyetRLN(TREE t) {
	if (t != NULL) {
		duyetRLN(t->pRight);
		duyetRLN(t->pLeft);
		cout << t->data << " ";
	}
}

void Menu(TREE& t) {
	while (true) {
		cout << "\n========MENU=========";
		cout << "\n1.Nhap du lieu ";
		cout << "\n2.Xuat du lieu theo NLR";
		cout << "\n3.Xuat du lieu theo NRL";
		cout << "\n4.Xuat du lieu theo LNR";
		cout << "\n5.Xuat du lieu theo RNL";
		cout << "\n6.Xuat du lieu theo LRN";
		cout << "\n7.Xuat du lieu theo RLN";
		cout << "\n0.End";
		cout << "\n====================" << endl;
		int lc; cout << "Nhap lua chon "; cin >> lc;
		if (lc < 0 || lc>7) {
			cout << "Lua chon khong hop le!" << endl;
		}

		else if (lc == 1) {
			int x; cout << "Nhap vao so nguyen: "; cin >> x;
			ThemNodeCay(t, x);
		}
		else if (lc == 2) {
			cout << "Duyet cay theo NLR ";
			DuyetNLR(t);
		}
		else if (lc == 3) {
			cout << "Duyet theo NRL: ";
			duyetNRL(t);
		}
		else if (lc == 4) {
			cout << "Duyet theo LNR: ";
			duyetLNR(t);
		}
		else if (lc == 5) {
			cout << "Duyet theo RNL: ";
			duyetRNL(t);
		}
		else if (lc == 6) {
			cout << "Duyet theo LRN: ";
			duyetLRN(t);
		}
		else if (lc == 7) {
			cout << "Duyet theo RLN: ";
			duyetRLN(t);
		}
		else {
			break;
		}
	}
}
int main()
{
	TREE  t;
	KhoiTao(t);
	Menu(t);

	return 0;
}

