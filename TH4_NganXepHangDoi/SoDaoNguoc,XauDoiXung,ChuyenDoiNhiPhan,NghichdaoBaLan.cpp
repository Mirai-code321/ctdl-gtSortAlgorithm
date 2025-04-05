#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

int do_uu_tien(char c) {
	if (c == '^') return 5;
	if (c == '*' || c == '/') return 4;
	if (c == '+' || c == '-') return 3;
	return 2;
}


string Trung_To_Hau_To(string s) {
	string ket_qua = "";
	stack<char> ngan_xep;
	for (int i = 0; i < s.size(); i++) {
		if (isalnum(s[i])) {
			ket_qua += s[i];
			ket_qua += ' ';
		}
		else if (s[i] == '(') ngan_xep.push(s[i]);
		else if (s[i] == ')') {
			while (!ngan_xep.empty() && ngan_xep.top() != '(') {
				ket_qua += ngan_xep.top();
				ket_qua += ' ';
				ngan_xep.pop();
			}
			ngan_xep.pop();
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^') {
			while (!ngan_xep.empty() && do_uu_tien(ngan_xep.top()) >= do_uu_tien(s[i])) {
				ket_qua += ngan_xep.top();
				ket_qua += ' ';
				ngan_xep.pop();
			}
			ngan_xep.push(s[i]);
		}
	}

	while (!ngan_xep.empty()) {
		ket_qua += ngan_xep.top();
		ket_qua += ' ';
		ngan_xep.pop();
	}
	return ket_qua;
}



int tinh_gia_tri(string hau_to) {
	stack<int> s;
	int so = 0;
	bool doc_so = false;
	for (char c : hau_to) {
		if (isdigit(c)) {
			so = so * 10 + (c - '0');
			doc_so = true;
		}
		else if (c == ' ' && doc_so) {
			s.push(so);
			so = 0;
			doc_so = false;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			if (s.size() < 2) {
				cout << "Bieu thuc khong hop le!" << endl;
				return -1;
			}
			int b = s.top(); s.pop();
			int a = s.top(); s.pop();
			if (c == '+') s.push(a + b);
			else if (c == '-') s.push(a - b);
			else if (c == '*') s.push(a * b);
			else if (c == '/') s.push(a / b);
			else if (c == '^') s.push(pow(a, b));
		}
	}
	return s.top();
}



void Dao_Nguoc_So(int n) {
	string str_n = to_string(n);
	for (int i = str_n.size() - 1; i >= 0; i--) {
		cout << str_n[i];
	}
	cout << endl;
}


bool Kiem_Tra_Doi_Xung(string str) {
	stack<char> s;
	for (char c : str) {
		s.push(c);
	}
	for (char c : str) {
		if (c != s.top()) return false;
		s.pop();
	}
	return true;
}


void Chuyen_Doi_Nhi_Phan(int n) {
	stack<int> s;
	while (n > 0) {
		s.push(n % 2);
		n /= 2;
	}

	cout << "Bieu dien nhi phan: ";
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
}


int main() {
	string trung_to;
	cout << "Nhap bieu thuc trung to: ";
	getline(cin, trung_to);

	string hau_to = Trung_To_Hau_To(trung_to);
	cout << "Bieu thuc hau to: " << hau_to << endl;
	cout << "Ket qua: " << tinh_gia_tri(hau_to) << endl;

	int n;
	cout << "\nNhap so de dao nguoc: ";
	cin >> n;
	Dao_Nguoc_So(n);
	cin.ignore();

	string str;
	cout << "\nNhap xau de kiem tra doi xung: ";
	getline(cin, str);

	if (Kiem_Tra_Doi_Xung(str)) cout << "Xau doi xung!" << endl;
	else cout << "Xau khong doi xung!" << endl;

	cout << "\nNhap so thap phan de chuyen sang nhi phan: ";
	cin >> n;
	Chuyen_Doi_Nhi_Phan(n);

	return 0;

}

