/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: CF50B - Choosing Symbol Pairs
Estratégia: Este problema é resolvido apenas guardando quantas vezes cada caracter numérico
ou entre 'a' e 'z' aparece na string, adicionando o quadrado deste total no resultado final,
para cada caracter.
*/
#include <bits/stdc++.h>
using namespace std;

int converte (char a){
	if (a >= '0' and a <= '9') return (a - '0');
	else	return (a - 'a' + 10);
}

int main(){
	long long int tot=0;
	string asd;
	vector<long long int> freq(36);
	cin >> asd;
	for (long long int i=0; i<asd.size(); i++){
		freq[converte(asd[i])]++;
	}
	for (int i=0; i<36; i++){
		tot += freq[i]*freq[i];
	}
	cout << tot;
	return 0;
}
