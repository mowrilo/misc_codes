#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  while (n > 0) {
    int mat[n+2][m+2][2*k+1];
    int vert[] = {0,0,0,1,1,1,-1,-1,-1};
    int horiz[] = {0,1,-1,0,1,-1,0,1,-1};
    for (int i=0; i<=n+1; i++){
      for (int j=0; j<=m+1; j++){
        for (int c=0; c<2*k+1; c++) mat[i][j][c] = 0;
      }
    }
    for (int i=0; i<k; i++) {
      int x, y, t;
      cin >> x >> y >> t;
      mat[x][y][t]=1;
    }
    for (int k2=2*k; k2>=0; k2--){
      for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
          int aux = 0;
          for (int c=0; c<9; c++){
            //if ((i+vert[c] < ))
            // cout <<"k2: " << k2 << " " << i << " " << j << endl;
            // cout << mat[i+vert[c]][j+horiz[c]][k2+1] << " ";
            aux = max(aux, mat[i+vert[c]][j+horiz[c]][k2+1]);
          }
          // cout << aux << endl;
          mat[i][j][k2] += aux;
        }
      }
    }
    int xx,yy;
    cin >> xx >> yy;
    cout << mat[xx][yy][0] << "\n";
    cin >> n >> m >> k;
  }
  return 0;
}
