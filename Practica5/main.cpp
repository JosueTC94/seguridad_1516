#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <string.h>
#include "funciones.cpp"

using namespace std;

void imprimir(int v[4][4], string nombre_v)
{
  cout << nombre_v << ": " << endl;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

void rellenar_matriz(int v[4][4], vector<int> v1)
{
  int contador = 0;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      v[j][i] = v1[contador];
      contador++;
    }
  }
}

vector<int> token(char* cadena)
{
  int i=0;
  int contador = 0;
  vector<int> auxiliar;
  char* pch;
  pch = strtok (cadena," ,");
  while (pch != NULL)
  {
    auxiliar.resize(auxiliar.size()+1);
    cout << "pch => " << pch << endl;
    auxiliar[i] = atoi(pch);
    pch = strtok (NULL, " ,");
    i++;
  }
  return auxiliar;
}

int main()
{
  char* clave_;
  char* texto_;
  clave_ = new char[128];
  texto_ = new char[128];

  vector<int> clave1;
  vector<int> texto1;

  int clave[4][4];
  int texto[4][4];

  cout << "Clave: ";
  cin.getline(clave_,128);

  cout << "Texto original: ";
  cin.getline(texto_,128);

  int i=0;
  int j=0;
  int contador = 0;

  clave1 = token(clave_);
  texto1 = token(texto_);

  rellenar_matriz(clave,clave1);
  rellenar_matriz(texto,texto1);

  imprimir(clave,"Clave");
  imprimir(texto,"Texto");

  cout << endl;

  return 0;
}
