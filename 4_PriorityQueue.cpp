// 2019029089_GAN SHU YI_11802

#include <iostream>
#include <stdlib.h>
#include <exception>
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

void buildHeap (int* arr, int n)
{
	int start = (n / 2) - 1;
	
	for (int i = start; i >= 0; i--) {
		heapify(arr, n, i);
	}
}

void insertNum (int* arr, int& n, int key)
{
	n += 1;
	arr[n - 1] = key;
}

void replaceNum(int* arr, int n, int i, int key)
{
	arr[i - 1] = key;
	buildHeap(arr, n);
}

int extractMax (int* arr, int n)
{
	int temp[n];
	int max;
	
	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
	}
	
	buildHeap(temp, n);
	max = temp[0];
	
	replaceNum(arr, n - 1, 1, arr[n - 1]);
	
	return max;
}

int main()
{
	int cmd, num, num2, index, max;
	int n = 0;
	int maxSize = 0;
	int arr[99999];
	int maxArr[99999];

	cin >> cmd;
	int loop = 1;
	
	while (loop) {
		try {
			switch(cmd) {
			case 0:
				loop = 0;
				// print output
				if (maxSize > 0) {
					for (int i = 0; i < maxSize; i++) {
						cout << maxArr[i] << " ";
					}	 
					cout << '\n';
				}
			
				for (int i = 0; i < n; i++) {
					cout << arr[i] << " ";
				}
				exit(0);
				break;
		
			case 1:
				if (n < 99999)
					cin >> num;
				insertNum(arr, n, num);
				break;
		
			case 2:
				max = extractMax(arr, n);
				insertNum(maxArr, maxSize, max);
				n--;
				break;
		
			case 3:
				cin >> index;		
				cin >> num2;
				replaceNum(arr, n, index, num2);
				break;
			}
			cin >> cmd;
		}
		catch (exception& e) {
			break;
		}
	  }

	return 0;
}
