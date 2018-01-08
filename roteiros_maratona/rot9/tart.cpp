/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: UVa 11505 - Logo
Estratégia: Este problema é resolvido guardando-se os valores atuais de X e Y,
bem como atualizando o valor do ãngulo no qual a tartaruga se encontra virada. Cada
vez que a tartaruga anda, o valor de X e Y é atualizado de acordo com o ângulo, sendo
X atualizado de dist*cos(angulo) e Y de dist*sin(angulo), sendo dist a distancia percorrida.
Se a tartaruga andar para frente, estes valores são somados, e subtraídos caso andar
para trás. Ao fim, é calculada a distância de X e Y do ponto inicial da tartaruga, (0,0),
e arredondando-se para inteiro.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int ntest;
	cin >> ntest;
	for (int count=0; count<ntest; count++){
		int ncom;
		cin >> ncom;
		double ang=0;
		int angDeg=0;
		double x=0,y=0;
		for (int i=0; i<ncom; i++){
			string com;
			double num;
			cin >> com >> num;
			if (com.compare("fd") == 0){
				y += num*sin(ang);
				x += num*cos(ang);
				//cout << "andou! novo x: " << x << " novo y: " << y << "\n";
			}
			else if (com.compare("bk") == 0){
				y -= num*sin(ang);
				x -= num*cos(ang);
				//cout << "andou! novo x: " << x << " novo y: " << y << "\n";
			}
			else{
				//num *= M_PI/180;
				if (com.compare("rt") == 0)	angDeg -= num;
				else	angDeg += num;
				angDeg = angDeg%360;
				//if (ang >= (2*M_PI))	ang-=2*M_PI;
				//if (ang <= (-2*M_PI))	ang+=2*M_PI;
				ang = (double) angDeg*M_PI/180;
				//cout << "novo angulo: " << ang << "\n";
			}

		}
		double dist = sqrt((abs(x)*abs(x))+(abs(y)*abs(y)));
		cout << round(dist) << "\n";
	}
	return 0;
}
