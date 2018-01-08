/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: PARPROX - Pontos
Estratégia: Este problema é resolvido com um algoritmo quadrático. Lendo todos
os pontos, é calculada a distância de todos entre todos, guardando o menor valor
a cada cálculo, sendo este impresso no fim.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int npontos;
	cin >> npontos;
	vector<vector<int> > pts;
	//vector<float> dists((npontos*(npontos-1))/2);
	for (int i=0; i<npontos;i++){
		int aux1, aux2;
		cin >> aux1 >> aux2;
		vector<int> vaux(2);
		vaux[0] = aux1;
		vaux[1] = aux2;
		pts.push_back(vaux);
	}
	//int asd=0;
	double min=10000000;
	for (int i=0; i<npontos;i++){
		for (int j=i+1; j<npontos; j++){
			double dif0 = (double) abs(pts[i][0] - pts[j][0]);
			double dif1 = (double) abs(pts[i][1] - pts[j][1]);
			double dist=sqrt((dif0*dif0)+(dif1*dif1));
			if (dist < min)	min = dist;
			//dists[asd] = dist;
			//asd++;
		}
	}
	//sort(dists.begin(),dists.end());
	printf("%.3f\n",min);
	return 0;
}
