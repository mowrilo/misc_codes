/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: ELEVADOR - Elevador
Estratégia: Este problema é resolvido primeiro checando se o maior cilindro cabe
no elevador. Se couber, pega-se o ponto de maior distância entre os cilindros,
onde ambos estarão em extremidades opostas do elevador. Caso mesmo na configuração
de maior distância haja superposição, ou seja, a distância entre os centros
for menor que R1+R2, não será possível colocar os dois cilindros
no elevador. Caso não haja, será possível.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
  int l,c,r1,r2;
  cin >> l >> c >> r1 >> r2;
  while (l > 0){
    int maxr = max(r1,r2);
    int resl = l-2*maxr, resc = c-2*maxr;
    if (resl >= 0 && resc >= 0){
      int maxD = sqrt((l-r1-r2)*(l-r1-r2) + (c-r1-r2)*(c-r1-r2));
      if (maxD >= (r1+r2)){
        cout << "S\n";
      }
      else{
        cout << "N\n";
      }
    }
    else{
      cout << "N\n";
    }
    cin >> l >> c >> r1 >> r2;
  }
  return 0;
}
