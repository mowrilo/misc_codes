/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: BICHO - Jogo do bicho
Estratégia: Este problema é resolvido de maneira bem direta de acordo com a descrição,
fazendo-se uma série de if-elses tendo como condições os restos dos valores por
potências de 10, para se pegar os últimos dígitos. Para checar se os números são do
mesmo bicho, é conferido se as divisões por 4 são iguais.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	float v;
	cin >> v >> n >>m;
	while (v != 0 and n >= 0 and m >= 0){
		float max = 0;
		if (m%10000 == n%10000){
			max=v*3000;
		}
		else if (m%1000 == n%1000){
			max=v*500;
		}
		else if (m%100 == n%100){
			max=v*50;
		}
		else{
			int aux1=n%100;
			int aux2=m%100;
			if (aux1 == 0)	aux1=100;
			if (aux2 == 0)	aux2=100;
			if ((aux1-1)/4 == (aux2-1)/4)	max=v*16;
		}
		printf("%.2f\n",max);
		cin >> v >> n >> m;
	}
	return 0;
}
