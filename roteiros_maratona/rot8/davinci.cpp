/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: UVa 11385 - The Da Vinci Code
Estratégia: É feita uma função que, dado um número de fibonacci, retorna seu índice na sequência.
Quando os números são lidos, suas posições são calculadas e guardadas. O maior íncide é guardado,
inicializando-se uma string de espaços, do tamanho do íncide máximo. Assim, a string a ser decifrada
é lida, e cada letra maiúscula é relacionada ao próximo índice no vetor de índices, salvando esta
letra no dado índice.
*/
#include <bits/stdc++.h>
using namespace std;

int posFib(int a){
	vector<int> fibs;
	fibs.push_back(0);
	fibs.push_back(1);
	fibs.push_back(2);
	if (a == 1)	return 1;
	if (a == 2)	return 2;
	int nfib = 3;
	while(true){//for (int i=2; i<101; i++){
		int fibo=fibs[nfib-1] + fibs[nfib-2];
		if (fibo == a)	return nfib;
		if (fibo > a) return 0;
		fibs.push_back(fibo);
		nfib++;
	}
}

int main(){
	int n;
	cin >> n;
	for (int count=0; count<n; count++){
		vector<int> nums;
		int nnums;
		cin >> nnums;
		int max=0;
		for (int i=0; i<nnums; i++){
			int aux;
			cin >> aux;
			int asd=posFib(aux);
			nums.push_back(asd);
			if(asd>max)	max=asd;
		}
	//	cout << "pegou tudo\n";
		string str="";
		for (int i=0; i<max; i++)	str+= ' ';
		string str2;
		cin.ignore();
		std::getline(std::cin, str2);
		//cout << "max: " << max << " str2: " << str2 << endl;
		int posStr = 0;
		for (int i=0;  i<nums.size(); i++){
			while ((str2[posStr] < 'A') || (str2[posStr] > 'Z'))	posStr++;
		//	cout << nums[i]-1 << endl;
			str[nums[i]-1] = str2[posStr];
			posStr++;
		}
		cout << str << "\n";
	}
	return 0;
}
