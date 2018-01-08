#include <bits/stdc++.h>

using namespace std;

int findpos(int el, vector<int> &vec){
        int ub = vec.size()-1;
        int lb = 0;

        while (ub >= lb){
                int pos = lb + (ub - lb)/2;
                if (vec[pos] == el)     return pos;
                if (vec[pos] > el)      ub = pos-1;
                else    lb = pos+1;
        }
        return -1;
}


int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	while (!cin.eof()){
		vector<int> sumvec;
		int soma = 0;
		for (int i =0; i<n; i++){
			int a;
			cin >> a;
			soma+=a;
//			cout << soma << " ";
			sumvec.push_back(soma);
		}
		int numt = 0;
		int tot = sumvec[n-1]/3;
		//cout << sumvec[n-1] << tot << "\n";
		for (int i=0; i<n; i++){
			int pos = findpos(sumvec[i]+tot,sumvec);
			if (pos > 0){
				//cout << pos << "\n";
				pos = findpos(sumvec[i]+tot+tot,sumvec);
				//cout << pos << "\n";
				if (pos > 0) numt++;
			}
		}
		cout << numt << "\n";
		cin >> n;
	}
	return 0;
}
