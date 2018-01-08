#include <bits/stdc++.h>
using namespace std;

int desDir (vector<vector<int> > a, int npil, int pos){
	int ncaixas = a[npil].size()-pos;
	// if (npil == a.size()-1){
	// 	return a[npil].size()-pos;
	// }
	// if (pos >= a[npil+1].size()){
	// 	return a[npil].size()-pos;
	// }
	if ((npil < a.size()-1) && (pos < a[npil+1].size())){
		ncaixas += desDir(a,npil+1,pos);
	}
	return ncaixas;
}

int desEsq (vector<vector<int> > a, int npil, int pos){
	int ncaixas = a[npil].size()-pos;
	// if (npil == 0){
	// 	return (a[npil].size()-pos);
	// }
	// if (pos >= a[npil-1].size()){
	// 	return (a[npil].size()-pos);
	// }
	if ((npil > 0) && (pos < a[npil-1].size())){
		ncaixas += desEsq(a,npil-1,pos);
	}
	return ncaixas;
}

int main(){
	int n,p;
	scanf("%d %d",&n, &p);// n >> p;
	while ((n > 0) && (p > 0)){
		vector<vector<int> > tudo;
		int p1,pos1;
		for (int i=0;i<p;i++){
			int nl;
			scanf("%d",&nl);
			vector<int> pilha;
			for (int j=0;j<nl;j++){
				int lid;
				scanf("%d",&lid);
				pilha.push_back(lid);
				if (lid == 1){
					p1 = i;
					pos1 = j;
				}
			}
			tudo.push_back(pilha);
		}
		//int max;
		int max = tudo[p1].size()-1-pos1;
		//if ((p1 == 0) || (p1 == (tudo.size() - 1))){
		//	max = nbox; 
		//}
		if((p1 > 0) && (p1 < tudo.size())){
			max += std::min(desDir(tudo,p1+1,pos1),desEsq(tudo,p1-1,pos1));
		}
		printf("%d",max);
		scanf("%d %d",&n,&p);
		if (n != 0)	printf("\n");
	}
	return 0;
}

