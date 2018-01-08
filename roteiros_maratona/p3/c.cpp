#include <bits/stdc++.h>
using namespace std;

typedef struct node{
  vector<int> adj;
} node;

void dfs(int init, int nv, int* visited, node g[], int *cycle, int parent){
    // cout << "vertice " << init << "\n";
    if((visited[init] != 0)){// || (*cycle == 1)
        *cycle = 1;
        // visited[init]++;
        return;
    }

    visited[init] = 1;
    for (int i=0; i<g[init].adj.size(); i++){
        // if (g[init].adj[i] != 0){
            // g[init][i]--;
            // g[i][init]--;
            int nNode = g[init].adj[i];
            if ((nNode != parent) || (nNode == init)) dfs(nNode,nv,visited,g,cycle, init);
        // }
    }
}

// void dfs(int orig, int n, int* visited, vector<vector<int> > gra,  int *cycle){
//     stack<int> pilha;
//     pilha.push(orig);
//     while (!pilha.empty()){
//       int qual = pilha.top();
//       pilha.pop();
//       if (visited[qual] == 1) *cycle=1;
//       else{
//       for (int i=0; i<n; i++){
//         // if (visited[i] == 1)  *cycle=1;
//         if ((gra[qual][i] != 0)){// && (visited[i] == 0)
//           visited[i] = 1;
//           gra[qual][i]--;
//           //if (idades[i] < *minim) *minim = idades[i];
//           pilha.push(i);
//         }
//       }}
//     }
// }


int main(){
    int nv, na;
    cin >> nv >> na;
    while(!cin.eof()){
         node g[nv];//vector<vector<int> >
        // for (int i=0; i<nv; i++){
        //     vector<int> asd(nv);
        //     g.push_back(asd);
        // }
        for (int i=0; i<na; i++){
            int from, to;
            cin >> from >> to;
            g[from-1].adj.push_back(to-1);
            g[to-1].adj.push_back(from-1);
        }
        int cycle;
        cycle = 0;
        int *visited;
        visited = new int[nv];
        for (int k=0; k<nv; k++)    visited[k] = 0;
        for (int i=0; i<nv; i++){
            if (visited[i] == 0){
                dfs(i,nv,visited,g,&cycle,i);
            }
        }
        if (cycle == 1)    cout << "Inseguro\n";
        else        cout << "Seguro\n";
        delete[] visited;
        cin >> nv >> na;
    }
    return 0;
}
