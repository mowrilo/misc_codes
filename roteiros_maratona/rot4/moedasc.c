/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Problema: MOEDAS - Moedas
Estratégia: É resolvido por programação dinâmica. Para se pegar o número de moedas
para um dado valor X, itera-se por todas as moedas. Para cada moeda, pode-se pegar ou não.
Pegando-se a moeda de valor A, o número de moedas é 1 mais o número de moedas para o valor X-A.
Não pegando, é o valor da moeda anterior. Assim, itera-se por todo o vetor de moedas de 1 até X, sendo
o valor calculado em X o valor final.
*/

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

int calcula (int n, int m, int* avail, int* bismark)
{
	//if (m == 0)	return 0;
	if (m == 0)
	{
		return 0;
	}

	int k;
	int menor = INF;
	//for (int i=0; i<n; i++)	printf("%d ", avail[i]);
	//printf("\n");
	for (k=0; k<n; k++)
	{
		int a;
		if ((m-avail[k]) < 0)
		{
			a = INF;
		}
		else
		{
			a = bismark[m-avail[k]];//calcula(n,(m-avail[k]),avail);
		}
		if (a < menor)	menor = a;
		//printf("m: %d menor: %d\n",m, menor);
	}
	return menor+1;
}

int main ()
{
	int t,n,m;
	//scanf("%d",&t);
	///int i;
	scanf("%d",&m);
	while (m>0)
	{
		scanf("%d",&n);
		int j;
		int avail[n];

		for (j=0;j<n;j++)
		{
			scanf(" %d",&avail[j]);
		}

		int bismark[m+1];// = malloc(sizeof(int)*(m+1));
		//bismark[0] = 0;
		//int bismark;

		for (j=0;j<=m;j++)
		{
			bismark[j] = calcula(n,j,avail,bismark);
			//printf("j:%d bmrk:%d\n",j, bismark[j]);
		}

		//int nbl = calcula(n,m,avail,bismark);
		if (bismark[m] >= INF)	printf("Impossivel\n");
		else	printf("%d\n", bismark[m]);

		scanf("%d",&m);
	}
	return 0;
}
