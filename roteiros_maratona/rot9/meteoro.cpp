/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: METEORO - Meteoro
Estratégia: Este problema é resolvido apenas com condicionais IF. Dadas as coordenadas da fazenda
e de cada meteoro, é checado se o meteoro caiu entre as coordenadas X1 e X2, e Y1 e Y2. Caso
as duas condições forem verdadeiras, o meteoro caiu na fazenda, e incrementa-se a saída.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int nteste=1;
	while ((x1 > 0)&&(x2 > 0)&&(y1 > 0)&&(y2 > 0)){
		int n;
		cin >> n;
		int nmet=0;
		//vector<pair<int,int> > vec;
		for (int i=0; i<n; i++){
			int auxx,auxy;
			cin >> auxx >> auxy;
			//int caiu = 0;
			if ((auxx >= x1) && (auxx <= x2)){
				if ((auxy <= y1) && (auxy >= y2)){
					nmet++;
				}
			}
			//nmet+=caiu;
			//pair<int,int> asd(auxx,auxy);
			//vec.push_back(asd);
		}
		cout << "Teste " << nteste << "\n" << nmet << "\n\n";
		nteste++;
		cin >> x1 >> y1 >> x2 >> y2;
	}
	return 0;
}
