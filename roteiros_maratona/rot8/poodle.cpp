/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: POODLEMG - Poodle
Estratégia: Este problema é resolvido apenas concatenando um caracter 'o' na primeira metade
da palavra 'Poodle' para cada página adicional entre 7 e 20. Mais de 20 páginas não concatenam
mais caracteres.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	while (a>0){
		int npag=a/b;
		if (a%b)	npag++;
		string poo="Poo";
		string dle = "dle";
		int aux = npag-6;
		if (aux > 14)	aux=14;
		for (int i=0; i<aux; i++)	poo+='o';
		cout << (poo + dle) << "\n";
		cin >> a >> b;
	}
	return 0;
}
