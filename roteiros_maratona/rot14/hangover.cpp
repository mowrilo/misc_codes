/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: HANGOVER - Hangover
Estratégia: Este problema é resolvido simplesmente fazendo, dentro de um while,
a soma das frações, até se atingir o valor desejado.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	float c;
	cin >> c;
	while (c != 0.00){
		float custo=0;
		int i=0;
		while (custo <= c){
			i++;
			custo+=1/((float) i+1);
		}
		cout << i<< " card(s)\n";
		cin >> c;
	}
	return 0;
}
