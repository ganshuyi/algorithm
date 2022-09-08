// 2019029089_GAN SHU YI_11802

#include <iostream>
using namespace std;

void insertionSort (int* arr, int n)
{
	int key, i, j;
	
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] < key) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	int n = 0;
	cin >> n;
	
	while (n < 1 && n > 30000) {
		cin >> n;
	}
	
	int arr[n];
	
	for (int i  = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	insertionSort(arr, n);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}		
	
	return 0;
}
