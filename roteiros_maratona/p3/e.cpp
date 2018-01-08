#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

typedef struct asd{
	int nvert;
	int dist;
} vert;

class compara {
   public:
    bool operator() (vert a, vert b) {
        return (a.dist > b.dist);
    }
};

int dijks(int n, int ori, int **gra){
	vector<int> dists;
	int maior=0;
	for (int i=0;i<=n;i++)	dists.push_back(INF);
	dists[ori] = 0;
	vert vv;
	vv.nvert = ori;
	vv.dist = 0;
	priority_queue<vert,vector<vert>,compara> pq;
	pq.push(vv);
	while (!pq.empty()){
		vert toper = pq.top();
		pq.pop();
		int nn = toper.nvert;
		//cout << "pegando aresta " << nn << endl;
		for (int i=0;i<=n;i++){
			if (gra[nn][i] >= 0){
				vert aux;
				aux.nvert = i;
				if ((dists[nn] + gra[nn][i]) < dists[i]){
					dists[i] = dists[nn] + gra[nn][i];
					// if (dists[i] > maior)	maior = dists[i];
					aux.dist = dists[i];
					pq.push(aux);
				}
			}
		}
	}
	for (int i=0; i<=n; i++){
		// cout << dists[i] << " ";
		if (dists[i] > maior)	maior = dists[i];
	}
	// cout << "\n";
	return maior;
}

int main(){
	int n,m,q;
	cin >> n >> m >> q;
	while (!cin.eof()){
		int **gra;
		gra = new int*[n+1];
		for (int i=0;i<=n;i++){
			gra[i] = new int[n+1];
			for (int j=0;j<n;j++)	gra[i][j] = -1;
		}
		for (int i=0;i<m;i++){
			int o,d,p;
			//cout << "insira aresta " << i << endl;
			cin >> o >> d >> p;
			gra[o-1][d-1] = p;
			gra[d-1][o-1] = p;
		}
		for (int i=0; i<q; i++){
			int aux;
			cin >> aux;
			// cout << "aqui	\n";
			gra[aux-1][n] = 0;
			// cout << "aqui2	\n";
			gra[n][aux-1] = 0;
			// cout << "aqui3	\n";
		}
		vector<int> dists;
		int maior=0;
		for (int i=0;i<=n;i++)	dists.push_back(INF);
		int ori=n;
		dists[ori] = 0;
		vert vv;
		vv.nvert = ori;
		vv.dist = 0;
		priority_queue<vert,vector<vert>,compara> pq;
		pq.push(vv);
		while (!pq.empty()){
			vert toper = pq.top();
			pq.pop();
			int nn = toper.nvert;
			//cout << "pegando aresta " << nn << endl;
			for (int i=0;i<=n;i++){
				if (gra[nn][i] >= 0){
					vert aux;
					aux.nvert = i;
					if ((dists[nn] + gra[nn][i]) < dists[i]){
						dists[i] = dists[nn] + gra[nn][i];
						// if (dists[i] > maior)	maior = dists[i];
						aux.dist = dists[i];
						pq.push(aux);
					}
				}
			}
		}
		// int maior = 0;
		for (int i=0; i<=n; i++){
			// cout << dists[i] << " ";
			if (dists[i] > maior)	maior = dists[i];
		}
		// int ori, des;
		// cin >> ori >> des;
		//int maior=0;
		// for (int ori=0; ori<n; ori++){
		// int maior = dijks(n,n,gra);
			// if (aux > maior)	maior = aux;
		// }
		cout << maior << "\n";
		cin >> n >> m >> q;
	}
	return 0;
}
