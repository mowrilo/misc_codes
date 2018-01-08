#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	while (a!=0 && b!=0){
		unordered_set<int> sa,sb;
		for (int i=0; i<a; i++){
			int aux;
			cin >> aux;
			unordered_set<int>::iterator it = sa.find(aux);
			if (it == sa.end())	sa.insert(aux);
		}
		for (int i=0; i<b; i++){
			int aux;
			cin >> aux;
			unordered_set<int>::iterator it = sb.find(aux);
			if (it == sb.end())	sb.insert(aux);
		}

		int nab = 0,nba=0;
		for (unordered_set<int>::iterator i=sa.begin(); i!=sa.end(); i++){
			unordered_set<int>::iterator it = sb.find(*i);
			if (it == sb.end())	nab++;
		}
		for (unordered_set<int>::iterator i=sb.begin(); i!=sb.end(); i++){
			unordered_set<int>::iterator it = sa.find(*i);
			if (it == sa.end())	nba++;
		}
		
		cout << min(nab,nba) << "\n";
		cin >> a >> b;
	}
	return 0;
}
