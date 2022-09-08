// 2019029089_GAN SHU YI_11802

#include <iostream>
#include <limits>
 
using namespace std;

void rodCutting (int* p, int n) {    
	int r[n + 1], s[n + 1];
	int q;
	int inf = numeric_limits<int>::max();
	
	r[0] = 0;
	s[0] = 0;
	for (int j = 1; j <= n; j++) {
		q = -inf;
		for (int i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	
	int i = n;
	cout << r[n] << endl;
	
	while (i > 0) {
		cout << s[i] << ' ';
		i = i - s[i];
	}
}

int main (void)
{
	int n;

	cin >> n;
    while (n < 1 && n > 100) {
    	cin >> n;
	}
	
	int p[n + 1];
	p[0] = 0;
	for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        
		while (p[i] < p[i - 1]) {
         	cin >> p[i];
		}
    }
    
    rodCutting(p, n);
    return 0;
}
