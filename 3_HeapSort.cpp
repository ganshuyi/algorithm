// 2019029089_GAN SHU YI_11802

#include <iostream>
using namespace std;

// to heapify a subtree with root i
void heapify (int* arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if (l < n && arr[l] > arr[largest])
		largest = l;
		
	if (r < n && arr[r] > arr[largest])
		largest = r;
	
	if (largest != i) {
		swap(arr[i], arr[largest]);
		
		heapify(arr, n, largest);
	}
}

void heapSort (int* arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		
		heapify(arr, i, 0);
	}
}

int main()
{
	int k = 0, n = 0;
	cin >> n;
	
	while (n < 1 && n > 100000) {
		cin >> n;
	}
	
	cin >> k;
	
	while (k < 1 && k > 30) {
		cin >> k;
	}	
	
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	heapSort(arr, n);
	
	
	for (int i = n - 1; i >= n - k; i--) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
	
	for (int i = n - k - 1; i >= 0; i--) {
		cout << arr[i] << ' ';
	}
	return 0;
}
