/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: LINESEG - Intersection
Estratégia: Este problema tem uma solução bem direta. Para cada caso (ambas verticais,
ambas horizontais ou uma vertical e uma horizontal), checa-se os limites de cada segmento.
Caso ambos sejam horizontais ou verticais, é possivel haver uma interseção em segmento. caso
a configuração seja horizontal-vertical, a interseção será em ponto, caso exista. Caso as posiões
sejam iguais, as interseções são checadas de acordo com os limites dos segmentos
(máximos e mínimos) de X ou Y. Caso não, checa-se se os segmentos se cruzam.
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct asd{
  int x1;
  int y1;
  int x2;
  int y2;
} seg;

bool vert (seg a){
  if (a.x1 == a.x2) return true;
  return false;
}

int main(){
  int n;
  cin >> n;
  for (int count=0; count < n; count++){
    seg a,b;
    int x1,x2,y1,y2;
    // for (int i=0; i<2; i++){
    cin >> x1 >> y1 >> x2 >> y2;
    a.x1 = x1;
    a.x2 = x2;
    a.y1 = y1;
    a.y2 = y2;
    cin >> x1 >> y1 >> x2 >> y2;
    b.x1 = x1;
    b.x2 = x2;
    b.y1 = y1;
    b.y2 = y2;
    if (vert(a) && vert(b)){
      int maxmin = max(min(a.y1,a.y2),min(b.y1,b.y2));
      int minmin = min(min(a.y1,a.y2),min(b.y1,b.y2));
      int maxmax = max(max(a.y1,a.y2),max(b.y1,b.y2));
      int minmax = min(max(a.y1,a.y2),max(b.y1,b.y2));
      if (a.x1 == b.x1){
        if (minmax >= maxmin){
          if ((maxmin < minmax) && (minmin < minmax)){
            cout << "SEGMENT\n";
          }
          else{
            cout << "POINT\n";
          }
        }
        else{
          cout << "NO\n";
        }
      }
      else{
        cout << "NO\n";
      }
    }
    else if (!vert(a) && !vert(b)){
      int maxmin = max(min(a.x1,a.x2),min(b.x1,b.x2));
      int minmin = min(min(a.x1,a.x2),min(b.x1,b.x2));
      int maxmax = max(max(a.x1,a.x2),max(b.x1,b.x2));
      int minmax = min(max(a.x1,a.x2),max(b.x1,b.x2));
      if (a.y1 == b.y1){
        if (minmax >= maxmin){
          if ((maxmin < minmax) && (minmin < minmax)){
            cout << "SEGMENT\n";
          }
          else{
            cout << "POINT\n";
          }
        }
        else{
          cout << "NO\n";
        }
      }
      else{
        cout << "NO\n";
      }
    }
    else if (!vert(a) && vert(b)){
      if ((b.x1 <= max(a.x1,a.x2)) && (b.x1 >= min(a.x1,a.x2))){
        if ((max(b.y1,b.y2) >= a.y1) && (min(b.y1,b.y2) <= a.y1)){
          cout << "POINT\n";
        }
        else{
          cout << "NO\n";
        }
      }
      else{
        cout << "NO\n";
      }
    }
    else{
      if ((a.x1 <= max(b.x1,b.x2)) && (a.x1 >= min(b.x1,b.x2))){
        if ((max(a.y1,a.y2) >= b.y1) && (min(a.y1,a.y2) <= b.y1)){
          cout << "POINT\n";
        }
        else{
          cout << "NO\n";
        }
      }
      else{
        cout << "NO\n";
      }
    }
    // }
  }
  return 0;
}
