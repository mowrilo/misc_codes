#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	while (n > 0){
		// vector<int> aux;
		for (int i=0; i<n; i++){
			if (i < (k-1))	cout << (i+1);
			else{
				int asd = n- 1 - (i-k);
				cout << (asd);
			}
			if (i != (n-1))	cout << " ";
		}
		cout << "\n";
		// for (int i =0; i<n; i++)	cout << aux[i] << " ";
		cin >> n >> k;
	}
	return 0;
}
