#include <iostream>
using namespace std;

void merge(int a[], int left, int right, int mid) {
	int len_left = mid - left + 1;
	int len_right = right - mid;
	//tao mang tam thoi tu mang goc
	int *a_left = new int[len_left];
	int *a_right = new int[len_right];
	for (int i = 0; i < len_left; i++) {
		a_left[i] = a[left + i];
	}
	for (int i = 0; i < len_right; i++) {
		a_right[i] = a[mid + i+1];
	}
	int i1 = 0, i2 = 0, k=left;
	while (i1 < len_left && i2 < len_right) {//neu left va right con phan tu
		if (a_left[i1] <= a_right[i2]) {//phan tu ben left nho hon right
			a[k] = a_left[i1];
			i1++;
		}
		else {//nguoc lai
			a[k] = a_right[i2];
			i2++;
		}
		k++;
	}
	while (i1 < len_left) {//neu chi con moi left con phan tu
		a[k] = a_left[i1];//lai lai cac phan tu con lai
		i1++; k++;
	}
	while (i2 < len_right) {//neu phan tu con lai la mang right
		a[k] = a_right[i2];
		i2++; k++;
	}
	delete[] a_left;

	delete[] a_right;
}

void mergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);//goi de quy mang left (tu phan tu dau tien -> phan tu mid)
		mergeSort(a, mid + 1, right);//de quy tu phan tu sau phan tu mid -> phan tu cuoi cung
		merge(a, left, right, mid);//ham tron 2 day so
	}
}
int main()
{
	int a[100]; int n; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	mergeSort(a, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

