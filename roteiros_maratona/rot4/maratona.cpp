/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Problema: MARAT09 - Maratona
Estratégia: Este problema se resolve apenas iterando sobre o vetor de checkpoints
e calculando as diferenças entre as posições. Se a diferença for maior que G,
o corredor não consegue chegar. É também calculada a diferença entre o último e
a distância final da maratona, 42195.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, dmax;
	cin >> n >> dmax;
	int ultimo = 0;
	bool termina = true;
	for (int i=0; i<n;i++){
		int bla;
		cin >> bla;
		if ((bla-ultimo) > dmax)	termina = false;
		ultimo = bla;
	}
	if ((42195 - ultimo) > dmax)	termina = false;
	if (termina)	cout << "S\n";
	else		cout << "N\n";
	return 0;
}
