#include <iostream>
using namespace std;

void bubblesort(int a[],int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n-i-1; j++) {//giảm số lần so sánh mỗi khi tìm được phần tử lớn hơn
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	cout << "mang sau khi sap xep bubble sort: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void selectionsort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min = i;//min là giá trị đầu tiên trong mảng
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {//tìm kiếm phần tử nhỏ nhất 
				min = j;//cập nhật giá trị nhỏ nhất
			}
		}
		swap(a[i], a[min]);
	}
	cout << "mang sau khi sap xep selection sort: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void insertionsort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {//tìm kiềm phần tử nhỏ hơn khoá
			a[j + 1] = a[j];//chèn vị trí đứng trước khoá vào vị trí của khoá
			j--;
		}
		a[j + 1] = key;//chèn khoá vào sau phần tử nhỏ hơn đó
	}
	cout << "mang sau khi sap xep insertion sort: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void interchangesort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j]) {//so sánh 2 phần tử liền kề nhau
				swap(a[i], a[j]);//nếu phần tử trước lớn hơn thì hoán vị
			}
		}
	}
	cout << "mang sau khi sap xep interchange sort: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
int main()
{
	int a[100];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bubblesort(a, n);
	cout << endl;
	selectionsort(a, n);
	cout << endl;
	insertionsort(a, n);
	cout << endl;
	interchangesort(a, n);
	return 0;
}

