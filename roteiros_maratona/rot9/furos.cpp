/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: FUROS - Furos
Estratégia: Este problema é resolvido com um algoritmo quadrático. É calculada a
distância de todos os pontos para todos os outros, salvando qual a maior distância
para cada um, que deve ser o raio do círculo. Em seguida, pega-se a menor destas
maiores, pois é esta a menor que cobrirá todos os pontos. Como a distância é entre
os centros, adiciona-se 2,5mm de cada lado, ou seja, 5mm, pois cada furo possui
5mm de diâmetro. E, como se quer um inteiro, arredonda-se o resultado para cima.
*/
#include <bits/stdc++.h>
using namespace std;

double dist(pair<int,int> a, pair<int,int> b){
	double dif1 = (double) abs(a.first-b.first);
	double dif2 = (double) abs(a.second-b.second);
	double dist = sqrt((dif1*dif1)+(dif2*dif2));
	return dist;
}

int main(){
	int n;
	cin >> n;
	int nteste=1;
	while (n){
		vector<pair<int,int> >	pts;
		for (int i=0;i<n;i++){
			int aux1,aux2;
			cin >> aux1 >> aux2;
			pair<int,int> aux(aux1,aux2);
			pts.push_back(aux);
		}
		vector<double> maiores(n);
		for (int i=0;i<n;i++){
			for (int j=i+1; j<n; j++){
				double dis = dist(pts[i],pts[j]);
				if (dis > maiores[i])		maiores[i] = dis;
				if (dis > maiores[j]) 	maiores[j] = dis;
			}
		}
		double men=1000000000;
		for (int i=0; i<n; i++){
			if (maiores[i] < men)	men = maiores[i];
		}
		cout << "Teste " << nteste << "\n" << (int) ceil(2*men + 5) << "\n\n";
		nteste++;
		cin >> n;
	}
	return 0;
}
