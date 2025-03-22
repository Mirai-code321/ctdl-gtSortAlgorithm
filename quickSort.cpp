#include <iostream>
using namespace std;

void HoanVi(int a[], int x, int y) {
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int partition(int a[], int left, int right) {
	int pivot = a[left];//cho pivot bang phan tu dau tien
	int dem = 0;
	for (int i = left + 1; i <= right; i++) {//dem so luong phan tu nam ben trai pivot
		if (a[i] <= pivot) dem++;
	}
	int Indexpivot = left + dem;//tim vi tri cua pivot
	HoanVi(a, left, Indexpivot);//dua pivot ve dung vi tri
	int i = left, j = right;
	while (i<Indexpivot && j>Indexpivot) {
		while (a[i] <= pivot) i++;
		while (a[j] > pivot) j--;
		if (i<Indexpivot && j>Indexpivot) {
			HoanVi(a, i, j);
		}
	}
	return Indexpivot;
}

void quickSort(int a[], int left, int right) {
	if (left >= right) return;
	int pivot = partition(a, left, right);
	quickSort(a, left, pivot - 1);
	quickSort(a, pivot + 1, right);
}
int main()
{
	int a[100]; int n; cin >> n;
	for (int i = 0;i< n; i++) {
		cin >> a[i];
	}
	quickSort(a, 0, n - 1);
	cout << "Mang sau khi sap xep: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
