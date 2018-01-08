/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Problema: JDENTIST - Dentista
Estratégia: Este problema é resolvido com uma abordagem gulosa. A lista de compromissos
é ordenada por tempo de término. Assim, começando pelo primero, quando se pega um evento,
todos os eventos seguintes que começam antes são descartados e incrementa-se de 1 o valor
máximo de eventos até o momento. E assim é feito até pegar todos os eventos.
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct ev{
	int com,ter;
} ev;

bool foo(ev a, ev b) {return (a.ter < b.ter);}

int main(){
	int n;
	cin >> n;
	vector<ev> evs(n);
	for (int i=0; i<n; i++){
		ev aux;
		int a,b;
		cin >> a >> b;
		aux.com=a; aux.ter=b;
		evs[i] = aux;
	}
	sort(evs.begin(), evs.end(), foo);
	int tot = 0;
	int i=0;
	while (i<n){
		int tempo = evs[i].ter;
		tot++;
		i++;
		while ((evs[i].com < tempo) && (i<n))	i++;
	}
	printf("%d\n",tot);
	return 0;
}
