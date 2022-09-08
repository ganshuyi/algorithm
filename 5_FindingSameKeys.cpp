// 2019029089_GAN SHU YI_11802

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n = 0; // number of keys in set A
	int m = 0; // number of keys in set B
	cin >> n;
	
	while (n < 1 && n > 100000) {
		cin >> n;
	}
	
	cin >> m;
	
	while (m < 1 && m > 100000) {
		cin >> m;
	}	
	
	int setA[n];
	int setB[m];
	
	for (int i = 0; i < n; i++) {
		cin >> setA[i];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> setB[i];
	}
	
	int count;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (setA[i] == setB[j])
				count++;
		}
	}
	
	cout << count;
	
	return 0;
}
