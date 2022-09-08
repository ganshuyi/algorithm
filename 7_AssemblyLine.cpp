// 2019029089_GAN SHU YI_11802

#include <iostream>
#include<vector>
using namespace std;

void assemblyLine (vector<vector<int> > a, vector<vector<int> > t, vector<int> e, vector<int> x, int n) 
{
	int f[2][n], l[2][n];
	f[0][0] = e[0] + a[0][0];
	f[1][0] = e[1] + a[1][0];
	
	for (int j = 1; j < n; j++)
	{
		if (f[0][j - 1] + a[0][j] <= f[1][j - 1] + t[1][j - 1] + a[0][j]) {
			f[0][j] = f[0][j - 1] + a[0][j];
			l[0][j] = 1;
		}
		else {
			f[0][j] = f[1][j - 1] + t[1][j - 1] + a[0][j];
			l[0][j] = 2;
		}
		
		if (f[1][j - 1] + a[1][j] <= f[0][j - 1] + t[0][j - 1] + a[1][j]) {
			f[1][j] = f[1][j - 1] + a[1][j];
			l[1][j] = 2;
		}
		else {
			f[1][j] = f[0][j - 1] + t[0][j - 1] + a[1][j];
			l[1][j] = 1;
		}
	}
	int F, L;
	
	if (f[0][n-1] + x[0] <= f[1][n-1] + x[1])
	{
		F = f[0][n - 1] + x[0];
		L = 1;
	} 
	else {
		F = f[1][n - 1] + x[1];
		L = 2;
	}
	cout << F << endl;
	
	int i = L;
	int temp[n];
	temp[n - 1] = i;
	
	for (int j = (n - 1); j > 0; j--) {
		i--;
		i = l[i][j];
		temp[j - 1] = i;
	}
	
	for (int i = 0; i < n; i++) {
		cout << temp[i] << ' ' << i + 1 << endl;
	}
}

int main (void)
{
    int n;
    vector<int> e(2), x(2);
	
	cin >> n;
    while (n < 1 && n > 100)
    {
    	cin >> n;
	}
	
	cin >> e[0] >> e[1];
	while (e[0] < 1 && e[0] > 100 && e[1] < 1 && e[1] > 100)
	{
		cin >> e[0] >> e[1];
	}
	
    cin >> x[0] >> x[1];
    
    vector<vector<int> > a(2, vector<int> (n));
    vector<vector<int> > t(2, vector<int> (n-1));
    
    for (int i = 0; i < n; ++i) {
        cin >> a[0][i];
         while (a[0][i] < 1 && a[0][i] > 100) {
         	cin >> a[0][i];
		 }
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> a[1][i];
         while (a[1][i] < 1 && a[1][i] > 100) {
         	cin >> a[1][i];
		 }
    }
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> t[0][i];
         while (t[0][i] < 1 && t[0][i] > 100) {
         	cin >> t[0][i];
		 }
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> t[1][i];
         while (t[1][i] < 1 && t[1][i] > 100) {
         	cin >> t[1][i];
		 }
    }
    
    assemblyLine(a, t, e, x, n);
	
    return 0;
}
