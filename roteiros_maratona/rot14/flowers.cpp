/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: UVa 11152 - Colorful Flowers
Estratégia: Este problema começa a ser resolvido calculando-se a área do triângulo
pelo semiperímetro, sqrt(semip*(semip - a)*(semip - b)*(semip - c)), que nos dá a
área de um triângulo qualquer. Com esta informação, se obtêm os raios dos triângulos
inscrito e circunscrito ao triângulo, obtendo-se as áreas destes. Assim, a área da
plantação de rosas é a área do círculo inscrito; a área da plantação de violetas é
a área do triângulo menos a área do círculo inscrito; e a área da plantação de
girassóis é a área do círculo circunscrito menos a área do triãngulo.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  while (!cin.eof()){
    double semip = ((double) (a+b+c))/2;
    double triArea = sqrt(semip*(semip - a)*(semip - b)*(semip - c));
    double raio1 = triArea/semip;
    double circIn = M_PI*(raio1*raio1);
    double raio2 = ((double) a*b*c)/(4*triArea);
    double circOut = M_PI*(raio2*raio2);
    double roses = circIn;
    double violets = triArea - roses;
    double sunflowers = circOut - triArea;
    printf("%.4f %.4f %.4f\n",sunflowers,violets,roses);
    cin >> a >> b >> c;
  }
  return 0;
}
