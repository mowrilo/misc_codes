/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfma
Problema: FATORIAL - Fatorial
Estratégia: Neste problema, assim que o programa é iniciado, é calculado um fatorial
iterativo até o limite do programa, guardando em um vetor. Porém, o fatorial é calculado
de modo a se obter o último dígito. Assim, os zeros são retirados da direita assim que
encontrados, pois o primeiro número diferente de zero não muda com a multiplicação.
O número também é pego igualado a seu resto por 100000, para evitar overflow, o que
também não interfere no resultado final. Desta forma, para cada consulta, apenas se
consulta o valor do vetor calculado, pegando o resto por 10.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<unsigned long long int> v(1000001);
	v[0]=1;
	for (int i=1; i<1000001; i++){
		v[i]=v[i-1]*i;
		while (v[i]%10==0)	v[i]/=10;
		v[i] = v[i]%100000;
	}
	int ninst=0;
	while (!cin.eof()){
		ninst++;
		cout << "Instancia " << ninst << "\n" << v[n]%10 << "\n\n";
		cin >> n;
	}
	return 0;
}
