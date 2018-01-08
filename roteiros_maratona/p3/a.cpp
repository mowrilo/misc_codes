#include <bits/stdc++.h>
using namespace std;

//#define mpgAl 90/7
//#define mpgBr 90/1

int main(){
	long long int n;
	cin >> n;
	double mpgAl = (double) 90/7;
	double mpgBr = (double) 90/1;
	while (n){
//		cout << mpgAl <<"  "<<mpgBr << endl;
		long long int golAl = floor(((double) n)/mpgAl);
		long long int golBr = ceil(((double) n)/mpgBr);
		cout << "Brasil " << golBr << " x " << "Alemanha " << golAl << "\n";
		cin >> n;
	}
	return 0;
}
