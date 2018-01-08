/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: MIOJO - Miojo
Estratégia: Neste problema, só podemos saber ao certo o tempo que a ampulheta começa
e termina. Resolve-se virando seguidamente as ampulhetas, até que a diferença entre
os tempos de término seja igual ao tempo de preparo do miojo, podendo então ser medido.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,a,b;
	cin >> t >> a >> b;
	int n1=1,n2=1;
	while(abs(a*n1 - b*n2) != t){
		if (a*n1 > b*n2)	n2++;
		else			n1++;
	}
	cout << max(a*n1,b*n2) << "\n";
	return 0;
}
