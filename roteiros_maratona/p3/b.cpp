#include <bits/stdc++.h>
using namespace std;

int main(){
	string t,p;
	cin >> t;
	while (!cin.eof()){
		cin >> p;
		int pos = t.find(p);
		if (pos != string::npos)	cout << "Resistente\n";
		else				cout << "Nao resistente\n";
		cin >> t;
	}
	return 0;
}
