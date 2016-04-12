#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <bitset>
#define TAM 256

using namespace std;

vector<int> filtrando(char* cadena)
{
  int i=0;
  int contador = 0;
  vector<int> auxiliar;
  char* pch;
  pch = strtok (cadena," ,");
  while (pch != NULL)
  {
    auxiliar.resize(auxiliar.size()+1);
    auxiliar[i] = atoi(pch);
    pch = strtok (NULL, " ,");
    i++;
  }
  return auxiliar;
}

void imprimir(vector<int> v, string nombre_v)
{
  cout << endl;
  cout << nombre_v << ":" << endl;
  for(int i=0;i<v.size();i++)
  {
    cout << v[i];
    if(i<v.size()-1)
    {
      cout << ",";
    }
  }
  cout << endl;
}

void inicializar_s(vector<int> &v)
{
  for(int i=0;i<TAM;i++)
  {
        v[i] = i;
  }
}
void rellenar_k(vector<int> &v, vector<int> mensaje)
{
  int i = 0;
  int j = 0;
  while(i < TAM)
  {
    while(j < mensaje.size())
    {
          v[i] = mensaje[j];
          i++;
          j++;
    }
    j = 0;
  }
}

void swap(vector<int> &v_s,vector<int> v_k)
{
  int f = 0;
  int aux = 0;
  int i = 0;
  for(i=0;i<TAM;i++)
  {
    f = (f + v_s[i] + v_k[i]) % TAM;
    aux = v_s[i];
    v_s[i] = v_s[f];
    v_s[f] = aux;
  }
}

vector<int> prga(vector<int> v_s, int tam)
{
   int i = 0;
   int f = 0;
   int contador = 0;
   int secuencia = 0;
   vector<int> provisional;
   provisional.resize(tam);

   for(contador = 0;contador<tam;contador++)
   {
     i = (i+1)%256;
     f = (f+v_s[i])%256;
     int auxiliar = 0;
     auxiliar = v_s[i];
     v_s[i] = v_s[f];
     v_s[f] = auxiliar;
     secuencia = (v_s[i]+v_s[f])%256;
     provisional[contador] = v_s[secuencia];
     cout << "Inserto en la posicion " << contador << " el valor " << provisional[contador] << endl;
   }
   return provisional;
}

vector<int> spritz(vector<int> v_s,int tam)
{
  int i=0;
  int j=0;
  int w=5;
  int k=0;
  int z=0;
  vector<int> provisional;
  cout << endl;
  for(int contador=0;contador<tam;contador++)
  {
    i = (i + w)%256;
    j = (k + v_s[j+v_s[i]])%256;
    k = (i+k+v_s[j])%256;
    int auxiliar = 0;
    auxiliar = v_s[i];
    v_s[i] = v_s[j];
    v_s[j] = auxiliar;
    z = (v_s[j+v_s[i+v_s[z+k]]])%256;
    provisional.resize(provisional.size()+1);
    provisional[contador] = v_s[z];
    cout << "Byte de secuencia cifrante " << contador << ": " << dec << provisional[contador] << endl;
  }
  return provisional;
}

int main()
{
  //Para el algoritmo RC4
  vector<int> S; //Caja S
  vector<int> K; //Clave
  vector<int> C; //Secuencia Cifrante
  vector<int> mensaje_f;
  vector<int> clave_f;
  char* mensaje_original;
  char* clave;

  vector<int> cifrado;

  S.resize(TAM);
  K.resize(TAM);
  mensaje_original = new char[150];
  clave = new char[150];

  cout << "Introduzca mensaje original: ";
  cin.getline(mensaje_original,150);
  cout << endl;
  cout << "Introduzca la clave: ";
  cin.getline(clave,150);
  cout << endl;

  mensaje_f = filtrando(mensaje_original);
  clave_f = filtrando(clave);

  cout << "---------------------------------" << endl;
  cout << "Informacion introducida:" << endl;
  imprimir(mensaje_f,"Mensaje original");
  cout << "Dimension: " << mensaje_f.size() << endl;
  imprimir(clave_f,"Clave");
  imprimir(clave_f,"Clave");
  cout << "Dimension: " << clave_f.size() << endl;
  cout << "---------------------------------" << endl;

  cout << "Proceso KSA:" << endl;
  cout << "1.- Inicializando vector S." << endl;
  S.resize(TAM);
  inicializar_s(S);
  imprimir(S,"Vector S");
  cout << endl;
  cout << "2.- Rellenar vector K." << endl;
  rellenar_k(K,clave_f);
  imprimir(K, "Vector K");
  cout << endl;
  cout << "3.- Intercambiando en KSA." << endl;
  swap(S,K);
  imprimir(S,"Vector S con swap");
  cout << "---------------------------------" << endl;
  cout << "Proceso PRGA." << endl;
  cout << "Pasos:" << endl;
  C = prga(S,mensaje_f.size());
  imprimir(C,"Secuencia cifrante");
  cout << "Dimension de la secuencia cifrante: " << C.size() << endl;
  cout << "---------------------------------" << endl;

  cifrado.resize(mensaje_f.size());
  for(int i=0;i<cifrado.size();i++)
  {
      cifrado[i] = (mensaje_f[i] ^ C[i]);
  }
  imprimir(cifrado,"Vector cifrado en decimal");
  cout << "Texto cifrado: " << endl;
  cout << "Cadena de texto: ";
  for(int i=0;i<cifrado.size();i++)
  {
    cout << (char)cifrado[i];
  }
  cout << endl;
  cout << "Hexadecimal:"<< "\t";
  for(int i=0;i<cifrado.size();i++)
  {
    cout << hex << cifrado[i];
    if(i<cifrado.size()-1)
    {
      cout << ",";
    }
  }
  cout << endl;

  cout << "---------------------------------" << endl;
  cout << "Modificacion: Spritz" << endl;
  vector<int> C_spritz;
  C_spritz = spritz(S,mensaje_f.size());
  imprimir(C_spritz,"Secuencia cifrante con Spritz(DEC)");
  cout << "Secuencia cifrante con Spritz(HEX):" << endl;
  for(int i=0;i<mensaje_f.size();i++)
  {
    cout << hex << C_spritz[i];
    if(i<C_spritz.size()-1)
    {
      cout << ",";
    }
  }
  cout << endl;
  cout << "Secuencia cifrante con Spritz(Texto):" << endl;
  for(int i=0;i<mensaje_f.size();i++)
  {
    cout << (char)C_spritz[i];
    if(i<C_spritz.size()-1)
    {
      cout << ",";
    }
  }
  cout << endl;
  return 0;
}
