/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Problema: BIT - Bits Trocados
Estratégia: Este problema é resolvido com uma abordagem gulosa. Partindo-se da
moeda de maior valor, calcula-se quantas destas moedas serão necessárias, calculando-se
da moeda de valor inferior, e assim fazendo até se pegar todas as moedas.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int notas[4] = {50,10,5,1};
	int val;
	scanf("%d",&val);
	int ntst = 0;
	while (val > 0){
		ntst++;
		int n = val;
		vector<int> nums(4);
		for (int i=0;i<4;i++){
			if (n >= notas[i]){
				nums[i] = n/notas[i];
				n = n%notas[i];
			}
		}
		printf("Teste %d\n%d %d %d %d\n\n",ntst,nums[0],nums[1],nums[2],nums[3]);
		scanf("%d",&val);
	}
	return 0;
}
