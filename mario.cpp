#include <bits/stdc++.h>

using namespace std;

int findpos(int el, vector<int> &vec){
	int ub = vec.size()-1;
	int lb = 0;
//	int a = 0;
	while (ub >= lb){
		int pos = lb + (ub - lb)/2;
		if (vec[pos] == el)	return pos;
		if (vec[pos] > el)	ub = pos-1;
		else	lb = pos+1;
	}
	if (vec[ub] < el)	return ub;
	return ub-1;
}

int main(){
	ios::sync_with_stdio(false);
	int n,l;
	scanf("%d %d",&n,&l);
	//cin >> n >> l;
	while (n != 0 && l != 0){
		vector<int> empty;
		int a;
		for (int i=0; i<l; i++){
			scanf("%d",&a);
			//cout << "put number\n";
			//cin >> a;
			empty.push_back(a);
		}
//		vector<int> diff(l-n+1);
//		cout << diff.size() << "\n";
		int min = 9999999;
//		cout << "aaaa\n";
		for (int i=0; i<l; i++){
			int lim = empty[i] + n - 1;
		//	cout << lim << "\n";
//			cout << "el: " << lim << "\n";
			a = findpos(lim, empty);
//			cout << "a: " << a << "\n";
			int asd = (i + n - 1) - (a);
			if (asd < min)	min = asd;
		}
		//for (int i=0; i<l; i++)		if (diff[i] < min)	min = diff[i];
		printf("%d\n",min);
		//cin >> n >> l;
		scanf("%d %d",&n,&l);
	}
	return 0;
}


