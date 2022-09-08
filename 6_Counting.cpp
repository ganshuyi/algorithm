// 2019029089_GAN SHU YI_11802

#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int inRange (int low, int high, int x)
{
	if (x >= low && x <= high) {
		return 1;
	}
	else
		return 0;
}

int main()
{
	int n = 0; // number of input keys
	int m = 0; // range of input keys
	int k = 0; // number of query range
	
	cin >> n;
	
	while (n < 1 && n > 100000) {
		cin >> n;
	}
	
	cin >> m;
	
	while (m < 1 && m > 100000) {
		cin >> m;
	}
	
	cin >> k;
	
	while (k < 1 && k > 100000) {
		cin >> k;
	}	
	
	int a[k];
	int b[k];
	
	for (int i = 0; i < k; i++) {
		cin >> a[i] >> b[i];
		
		if (a[i] > m || b[i] > m) 
			exit(0);
	}
	
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int cnt[k];
	
	for (int i = 0; i < k; i++) {
		cnt[i] = 0;
	}
	
	for (int i = 0; i < k; i ++) {
		for (int j = 0; j < n; j++) {
			cnt[i] += inRange(a[i], b[i], arr[j]);
		}
	}
	
	for (int i = 0; i < k; i++)
		cout << cnt[i] << '\n';
		
	return 0;
}
