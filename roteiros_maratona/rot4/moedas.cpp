#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

int foo(int din, vector<int> reais, vector<int> moed){
	if (din==0)	return 0;
	int menor = INF;
	for (vector<int>::iterator it=moed.begin(); it != moed.end(); ++it){
		int aux;
		if ((din - *it) < 0)	aux = INF;
		else	aux = reais[din- *it];
		if (aux < menor)	menor = aux;
	}
	return menor+1;
}
	

int main(){
	int ndin,nmoed;
	cin >> ndin;
	while(ndin > 0){
		cin >> nmoed;
		vector<int> moed;
		for (int i=0; i<nmoed;i++){
			int a;
			cin >> a;
			moed.push_back(a);
		}
		//for (vector<int>::iterator it=moed.begin(); it != moed.end();it++)	cout << *it << endl;
		vector<int> reais(ndin+1);
		int bismark = 0;
		for (vector<int>::iterator it = reais.begin(); it != reais.end(); ++it){
			*it = foo(bismark, reais, moed);
			bismark++;
		}
		if (reais.back() >= INF)	cout << "Impossivel\n";
		else				cout << reais.back() << "\n";
		cin >> ndin;
	}
	return 0;
}
