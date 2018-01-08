/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: UVa 10221 - Satellites
Estratégia: Este problema é resolvido, primeiramente, convertendo o ângulo, seja
em minutos ou graus, em radianos. Em seguida, a distância em linha reta e o arco
entre os satélites são calculados: o arco é simplesmente uma regra de 3 com o ângulo,
sendo o comprimento da circunferência toda referente a 2*pi radianos. A distância em
linha reta é a base de um triângulo isósceles, com os outros dois lados
iguais a S + 6440.
*/
#include <bits/stdc++.h>
using namespace std;

#define EARTH 6440

int main(){
  int s,a;
  string ang;
  cin >> s >> a >> ang;
  while (!cin.eof()){
    double angle;
    if (ang.compare("deg") == 0){
      angle = ((double) a) * M_PI/180;
    }
    else{
      angle = ((double) a)/60 * M_PI/180;
    }
    if (angle > M_PI) angle = 2*M_PI-angle;
    double alt = ((double) s) + EARTH;
    double arch = alt * angle;
    double dist = 2*(alt*sin(angle/2));
    printf("%.6f %.6f\n",arch,dist);
    cin >> s >> a >> ang;
  }
  return 0;
}
