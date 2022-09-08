// 2019029089_GAN SHU YI_11802

#include <iostream>
#include<bits/stdc++.h> 

using namespace std; 

void printParentheses(int i, int j, int n, int *s, int &num) 
{ 
    if (i == j) 
    { 
        cout << num++ << " "; 
        return; 
    } 
  
    cout << "( "; 
  
    printParentheses(i, *((s+i*n)+j), n, s, num); 
  
    printParentheses(*((s+i*n)+j) + 1, j, n, s, num); 
    cout << ") "; 
} 

void matrixChainOrder(int p[], int n) 
{ 
    int m[n][n]; 
    int s[n][n]; 
   
    for (int i = 1; i < n; i++) 
        m[i][i] = 0; 
  
    // L is chain length
    for (int L=2; L<n; L++) 
    { 
        for (int i=1; i<n-L+1; i++) 
        { 
            int j = i+L-1; 
            m[i][j] = INT_MAX; 
            for (int k=i; k<=j-1; k++) 
            { 
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]) 
                { 
                    m[i][j] = q; 
  
                    s[i][j] = k; 
                } 
            } 
        } 
    } 
  
    int num = 1; 
    cout << m[1][n-1] << endl;  
    printParentheses(1, n-1, n, (int *)s, num); 
    
} 
  
int main() 
{ 
	int n;
	
	cin >> n;
    while (n < 1 && n > 100) {
    	cin >> n;
	}
	
	int p[n + 1];
	for (int i = 0; i <= n; ++i) {
        cin >> p[i];
    }
    
	matrixChainOrder(p, n+1);
	
	return 0;
      
} 
