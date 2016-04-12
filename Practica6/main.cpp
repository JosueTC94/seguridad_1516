#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

//Hago un XOR entre el vector del mensaje original y la clave
void addRoundKey(int to[16], int c[16])
{
  for(int i=0;i<16;i++)
  {
      to[i] = to[i] ^ c[i];
  }
}

void byteSub(int to[16],const int sbox[256])
{
  for(int i=0;i<16;i++)
  {
    to[i] = sbox[to[i]];
  }
}

//shiftRows => Muevo las posiciones en el vector
void shiftRows(int to[16])
{
  cout << "Entre en la funcion..." << endl;
  int contador = 4;
  int tope = 4;
  while(contador < 16)
  {
    /*
    cout << "Contador: " << contador << endl;
    //Muevo el vector
    int aux = (contador / 4);
    cout << "Aux: " << aux << endl;
    int cont = 0; //Número de cambios que se van a realizar
    while(cont < aux)
    {
      int e1 = to[contador];
      int tope = contador + 4;
      int cambio =to[tope-(cont+1)];
      cout << "Cambio " << e1 << "por " << cambio << endl;
      to[tope-(cont+1)] = e1;
      to[contador] = cambio;
      cont++;
      contador++;
    }*/
    int auxiliar = 0;
    if(contador == 4)
    {
      cout << "Cambio el elemento " << to[contador] << " en la posicion " << contador << " por el "
      auxiliar = to[contador];
      to[contador] = to[contador + tope - 1];
      to[contador + tope - 1] = auxiliar;
    }
    if(contador == 8)
    {
      auxiliar = to[contador];
      to[contador] = to[contador + tope - 2];
      to[contador + tope - 1] = auxiliar;
      auxiliar = to[contador+1];
      to[contador] = to[contador + tope - 1];
      to[contador + tope - 2] = auxiliar;
    }
    if(contador == 12)
    {
      auxiliar = to[contador];
      to[contador] = to[contador + tope - 1];
      to[contador + tope - 1] = auxiliar;
      auxiliar = to[contador+1];
      to[contador] = to[contador + tope - 2];
      to[contador + tope - 2] = auxiliar;
      auxiliar = to[contador+2];
      to[contador] = to[contador + tope - 3];
      to[contador + tope - 3] = auxiliar;
    }
    contador++;
  }
}

//mixColumns =>
void mixColumns(int to[16])
{
  int t[4];
  for(int i=0;i<4;i++) {
    for(int j=0;j<4;j++)
      t[j]=to[i+4*j];

  for(int j=0;j<4;j++)
    to[i+4*j]=mult_2[t[j]]^t[(j+3)%4]^t[(j+2)%4]^mult_3[t[(j+1)%4]];
  }
}

//Imprimo vector
void imprimir(int v[16],string nombre_v)
{
    cout << nombre_v << ":" << endl;
    for(int i=0;i<16;i++)
    {
      cout << v[i] << ",";
    }
    cout << endl;
}

int main()
{
  //Declaración de variables
  int clave[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int texto_original[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  const int s_box[256] = {99,124,119,123,242,107,111,197,48,1,103,43,254,215,171,118,202,130,201,125,250,89,71,240,173,212,162,175,156,164,114,192,183,253,147,38,54,63,247,204,52,165,229,241,113,216,49,21,4,199,35,195,24,150,5,154,7,18,128,226,235,39,178,117,9,131,44,26,27,110,90,160,82,59,214,179,41,227,47,132,83,209,0,237,32,252,177,91,106,203,190,57,74,76,88,207,208,239,170,251,67,77,51,133,69,249,2,127,80,60,159,168,81,163,64,143,146,157,56,245,188,182,218,33,16,255,243,210,205,12,19,236,95,151,68,23,196,167,126,61,100,93,25,115,96,129,79,220,34,42,144,136,70,238,184,20,222,94,11,219,224,50,58,10,73,6,36,92,194,211,172,98,145,149,228,121,231,200,55,109,141,213,78,169,108,86,244,234,101,122,174,8,186,120,37,46,28,166,180,198,232,221,116,31,75,189,139,138,112,62,181,102,72,3,246,14,97,53,87,185,134,193,29,158,225,248,152,17,105,217,142,148,155,30,135,233,206,85,40,223,140,161,137,13,191,230,66,104,65,153,45,15,176,84,187,22};
  cout << "Informacion: " << endl;
  for(int i=0;i<16;i++)
  {
    cout << clave[i];
  }
  cout << endl;
  cout << "Paso 1: addRoundKey" << endl;
  addRoundKey(texto_original,clave);
  imprimir(texto_original,"Estado");
  cout << "Paso 2: byteSub" << endl;

  byteSub(texto_original,s_box);
  imprimir(texto_original,"Estado");
  cin.get();

  cout << "Paso 3: ShiftRows" << endl;
  shiftRows(texto_original);
  imprimir(texto_original, "Estado");

  cout << "Paso 4: mixColumns" << endl;
  mixColumns(texto_original);
  cin.get();

  cout << "Paso 5: "

  return 0;
}
