#include <iostream>
#include <vector>
using namespace std;

vector<int> mangNghichThe(const vector<int>& A) {
	int N = A.size();
	vector<int> B(N, 0);
	for (int i = 0; i < N; i++) {
		int dem = 0;
		for (int j = 0; j < i; j++) {
			if (A[j] > A[i]) {
				dem++;
			}
		}
		B[i] = dem;
	}
	return B;
}

vector<int> timHoanVi(const vector<int>& B) {
	int N = B.size();
	vector<int> A(N);
	vector<bool> used(N + 1, false);
	for (int i = N - 1; i >= 0; i--) {
		int dem = 0;
		for (int j = 1; j <= N; j++) {
			if (!used[j]) {
				if (dem == B[i]) {
					A[i] = j; // Đặt số j vào vị trí A[i]
					used[j] = true;
					break;
				}
				dem++;
			}
		}
	}
	return A;
}

int main()

{
	int n;
	cout << "Nhap so phan tu mang A: ";
	cin >> n;

	vector<int> A(n);
	cout << "Nhap cac phan tu cua mang A: ";
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<int> B = mangNghichThe(A);
	cout << "Mang nghich the: ";
	for (int x : B) {
		cout << x << " ";
	}
	cout << endl;

	vector<int> A2 = timHoanVi(B);
	cout << "Hoan vi mang nghich the: ";
	for (int x : A2) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}



