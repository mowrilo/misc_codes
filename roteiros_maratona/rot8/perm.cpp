#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		string a;
		cin >> a;
		int num;
		cin >> num;
		for (int j=0; j<num; j++)	next_permutation(a.begin(),a.end());
		cout << a << "\n";
	}
	return 0;
}
