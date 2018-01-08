#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> a, int q){
	int pos = a.size()/2;
	int div = pos/2;
	while (a[pos] != q){
		if (div < 1)	return -1;
		if (q > a[pos]){
			pos += div;
			div/=2;
		}
		else{
			pos -= div;
			div/=2;
		}
	}
	return pos;
}


int main(){
	vector<int> a;
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		int b;
		cin >> b;
		a.push_back(b);
	}
	int q;
	cin >> q;
	int pos = find(a,q);
	cout << "posicao " << pos << "\n";
	return 0;
}
