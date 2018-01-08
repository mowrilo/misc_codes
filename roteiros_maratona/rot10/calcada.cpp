/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: CALCADMG - Caminhando pela calçada
Estratégia: Analisando algumas instâncias, percebe-se que o número de coordenadas inteiras
que se passa em um plano, contando com o destino, é o máximo divisor comum entre
as diferenças entre as coordenadas dos pontos, ou seja, abs(x1-x2) e abs(y1-y2).
Assim, o número de pontos é 1+mdc(abs(x1-x2),abs(y1-y2)).
*/
#include <bits/stdc++.h>
using namespace std;

int mdc(int a,int b){
	if (b==0)	return a;
	else		return mdc(b,a%b);
}

int main(){
	int n;
	cin >> n;
	for (int count=0; count<n;count++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
	       	int d1=abs(a-c), d2=abs(b-d);
		int max = 1+mdc(d1,d2);
		cout << max << "\n";
	}
	return 0;
}
