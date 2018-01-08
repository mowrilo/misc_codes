/*
Aluno: Murilo Vale Ferreira Menezes
Matrícula: 2013030996
Login SPOJ: murilovfm
Nome URI: Murilo Vale Ferreira Menezes
Nome Codeforces: moriloow
Nome UVa:	murilovfm
Problema: ENCOTEL - Encontre o telefone
Estratégia: Neste problema, usa-se uma tabela hash com o template unordered_map,
guardando cada ocorrência de cada letra, passada para maiúscula. Caso a letra já
esteja no map, sua frequência é aumentada de 1. Caso não esteja,é adicionada, com
a frequência inicial 1. Depois, o map é transformado em um vector<pair<char,int> >,
para ser ordenado e então printado.
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<char,int> a, pair<char,int> b){
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

int main(){
  int n;
  cin >> n;
  //vector<string> v;
  cin.ignore();
  unordered_map<char,int> um;
  for (int i=0; i<n; i++){
    string aux;
    getline(cin,aux);
    for (int j=0; j<aux.size(); j++){
      char asd = toupper(aux[j]);
      if ((asd >= 'A') && (asd <= 'Z')){
        unordered_map<char,int>::iterator it = um.find(asd);
        if (it == um.end()){
          pair<char,int> auxx = {asd,1};
          um.insert(auxx);
        }
        else{
          it->second ++;
        }
      }
    }
    // cout << aux << endl;
    //v.push_back(aux);
  }
  vector<pair<char,int> > um2(um.begin(),um.end());
  sort(um2.begin(),um2.end(),compare);
  for (vector<pair<char,int> >::iterator it=um2.begin(); it != um2.end(); it++){
    cout << it->first << " " << it->second << "\n";
  }
  return 0;
}
