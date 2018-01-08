/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: NLOGONIA - Divisão da Nlogônia
Estratégia: O problema é resolvido apenas com condicionais IF; primeiramente checa-se
se o ponto está em cima de uma das coordenadas da divisa. Se não estiver, checa-se
de qual lado o ponto está, tanto na coordenada Y quanto na X, definindo N/S e E/O,
respectivamente.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int ntst;
	cin >> ntst;
	while (ntst){
		int xd,yd;
		cin >> xd >> yd;
		for (int i=0; i<ntst; i++){
			int xq,yq;
			cin >> xq >> yq;
			string resp = "";
			if ((xq == xd) || (yq == yd))	resp = "divisa";
			else{
				if (yq > yd)	resp += 'N';
				else		resp += 'S';
				if (xq > xd)	resp += 'E';
				else		resp += 'O';
			}
			cout << resp << "\n";
		}
		cin >> ntst;
	}
	return 0;
}
