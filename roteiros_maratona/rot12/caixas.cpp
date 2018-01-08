/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Problema: CAIXAS - Desempilhando Caixas
Estratégia: Este problema é resolvido pensando no seguinte: para se chegar a uma caixa,
deve-se tirar todas as caixas de cima dela e uma das caixas do lado. Para se tirar as caixas
do lado, deve-se tirar todas as de cima e a caixa do outro lado, e assim por diante. Assim,
para se tirar a caixa 1, deve-se tirar todas as caixas de cima e deve-se pegar o mínimo
entre tirar as caixas da direita ou esquerda. Assim, as caixas que se deve tirar da direita
e da esquerda são resolvidas recursivamente.
*/

#include <bits/stdc++.h>
using namespace std;

int custoDir(vector<vector<int> > pilhas, int npilha, int pos){
	if (npilha > (pilhas.size()-1))		return 0;
	if (pos > (pilhas[npilha].size()-1))	return 0;
	return (pilhas[npilha].size()-pos)+custoDir(pilhas, npilha+1,pos);
	//cout << "asd: " << asd << "\n";
	//return asd;
}

int custoEsq(vector<vector<int> > pilhas, int npilha, int pos){
	if (npilha < 0)		return 0;
	if (pos > (pilhas[npilha].size()-1))	return 0;
	return (pilhas[npilha].size()-pos)+custoEsq(pilhas, npilha-1,pos);
}

int main(){
	int n,p;
	cin >> n >> p;
	while (n!=0 && p!=0){
		vector<vector<int> > pilhas;
		int pos1, pilha1;
		for (int i=0; i<p;i++){
			vector<int> pilha;
			int ncaixas;
			cin >> ncaixas;
			for (int j=0; j<ncaixas; j++){
				int num;
				cin >> num;
				if (num == 1){
					pos1=j;
					pilha1=i;
				}
				pilha.push_back(num);
			}
			pilhas.push_back(pilha);
		}
	//	cout << pos1 << "  " << pilha1 << "\n";
		int maxDir,maxEsq;
		int cima = pilhas[pilha1].size() - 1 - pos1;
		maxDir = cima+custoDir(pilhas, pilha1+1, pos1);
		maxEsq = cima+custoEsq(pilhas, pilha1-1, pos1);
	//	cout << maxDir << "  " << maxEsq <<"\n";
		int maxTot = min(maxDir,maxEsq);
		cout << maxTot << "\n";
		cin >> n >> p;
	}
	return 0;
}
