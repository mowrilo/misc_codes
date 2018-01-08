import math

n = 10000000 #int(raw_input('Number:'))

divisors = [1] * n #Inicializa cada numero de 1 a n com 1 divisor: ele mesmo

for i in xrange(1,(n/2 + 1)): #Para cada numero, adiciona-se 1 a todos os seus multiplos
	for j in xrange(i+i,n+1,i): #O range e ate n/2 pois a partir dai seus multiplos fogem ao escopo
		divisors[j-1] += 1

final = 0

for i in xrange(0,n): #Percorre-se a lista, procurando dois numeros iguais consecutivos
	if (divisors[i] == divisors[i-1]):
		final += 1

print final
