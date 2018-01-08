#include <bits/stdc++.h>

using namespace std;

int findpos(int el, vector<int> vec){
	int curr = (vec.size()-1)/2;
	int frac = 1 + curr/2;
//	int a = 0;
	while (vec[curr] != el){
//		a ++;
//		if (a < 10)	cout << vec[curr] << " " << el << "\n";
		if (vec[curr] < el){
			curr += frac;
		}
		else{
			curr -= frac;
		}
		frac /= 2;
		if (frac == 0){	
			if (vec[curr] < el)	return curr+1;
			else	return curr;
		}
	}
	return curr;
}

int main(){
	int n,l;
	cin >> n >> l;
	while (n != 0 && l != 0){
		vector<int> empty;
		int a;
		for (int i=0; i<l; i++){
			cin >> a;
			empty.push_back(a);
		}
//		vector<int> diff(l-n+1);
//		cout << diff.size() << "\n";
		int min = 9999999;
		for (int i=0; i<(l-n+1); i++){
			int lim = empty[i] + n - 1;
			a = findpos(lim, empty);
			cout << a  << "  " << lim << "\n";
			int asd = (empty[a] - empty[i]) - (a-i);
			cout << asd << "\n";
			if (asd < min)	min = asd;
		}
		//for (int i=0; i<l; i++)		if (diff[i] < min)	min = diff[i];
		cout << min << "\n";
		cin >> n >> l;
	}
	return 0;
}

