// 2019029089_GAN SHU YI_11802

#include <iostream>
using namespace std;

void merge (int* arr, int lstart, int lend, int rstart, int rend)
{
	int pa = lstart, pb = rstart, pt = lstart;
	int tmp[rend];
	
	while (pa <= lend && pb <= rend) {
		if (arr[pa] > arr[pb]) {
			tmp[pt++] = arr[pa++];
		}
		else {
			tmp[pt++] = arr[pb++];
		}
	}
	
	if (pa > lend) {
		while (pb <= rend) {
			tmp[pt++] = arr[pb++];
		}
	}
	else {
		while (pa <= lend) {
			tmp[pt++] = arr[pa++];
		}
	}
	
	for (pt = lstart; pt <= rend; pt++) {
		arr[pt] = tmp[pt];
	}
}

void mergeSort (int* arr, int start, int end) 
{
	int mid;
	
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, mid + 1, end);
	}
}

int main() 
{
	int n = 0;
	cin >> n;
	
	while (n < 1 && n > 100000) {
		cin >> n;
	}
	
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	mergeSort(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	
	return 0;
}
