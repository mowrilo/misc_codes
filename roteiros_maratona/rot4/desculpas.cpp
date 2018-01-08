/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Problema: DESCULPA - Pedido de Desculpas
Estratégia: Este é o problema da mochila. Resolve-se por programação dinâmica. Em
cada item, escolhe-se pegá-lo ou não. Caso pega, para um custo máximo X, o valor é
o valor do item + o valor do custo máximo X-Custo do item. Caso o custo máximo seja 0,
o valor máximo é 0, como caso base.
*/

#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){
	if (a>b) return a;
	return b;
}

int main(){
	int pmax, nit;
	cin >> pmax >> nit;
	int ntst = 0;
	while (pmax != 0){
		ntst++;
		int m[nit+1][pmax+1];
		int pesos[nit], valor[nit];
		for (int i=0; i<nit;i++){
			cin >> pesos[i] >> valor[i];
		}
		for (int j=0; j<=pmax; j++){
			for (int i=0; i<=nit; i++){
				if ((i==0) || (j==0))	m[i][j] = 0;
				else{
					if (j < pesos[i-1])	m[i][j] = m[i-1][j];
					else	m[i][j]=max(m[i-1][j],(valor[i-1] + m[i-1][j-pesos[i-1]]));
				}
			}
		}
		printf("Teste %d\n%d\n\n",ntst,m[nit][pmax]);
		cin >> pmax >> nit;
	}
	return 0;
}
