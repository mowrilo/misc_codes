/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: ENCOTEL - Encontre o telefone
Estratégia: Este problema é resolvido apenas fazendo-se uma série de if's, dada
a letra em cada posição no telefone. Até o número 6, pode-se apenas dividir o
numero do caracter por 3 (onde A=0, B=1 e assim por diante). Depois, os valores
máximos de cada letra são levados em consideração.
*/
#include <bits/stdc++.h>
using namespace std;

int subs(char a){
	int a2=a-'A';
	if (a2/3<5)	return (a2/3 + 2);
	if (a2 < 19)	return 7;
	if (a2 < 22)	return 8;
	return 9;
}

int main(){
	string input;
	cin >> input;
	while (!cin.eof()){
		for (int i=0; i<input.size(); i++){
			int aux = input[i];
			if ((aux >= 'A') && (aux <= 'Z')){
				input[i] = '0' + subs(input[i]);
			}
		}
		cout << input << "\n";
		cin >> input;
	}
	return 0;
}
