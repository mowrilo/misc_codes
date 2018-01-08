/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: UVa 10079 - Pizza cutting
Estratégia: Pela análise da entrada, percebe-se que um corte de número N corta
ao meio N regiões, ou seja, aumenta em N o número de pedaços. Assim, começando com
1 pedaço (pizza inteira), o número de pedaços depois de N cortes é 1 mais a soma
de uma progressão aritmética de inteiros, começando de 1 até N e razão 1, ou seja,
1 + (N^2 + N)/2.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n;
//	cin >> n;
	unsigned long long int prev=1;
	//int max=atoi(argv[0]);
	for (int n=1; n<=210000000; n++){
	//while (n >= 0){
		unsigned long long int asd= 1+ (n*n + n)/2;
		if (asd != (prev+n)){
			cout <<n << "  " << prev << "  " << asd << "\n";
			break;
		}
		//cin >> n;
		prev = asd;
	}
	return 0;
}
