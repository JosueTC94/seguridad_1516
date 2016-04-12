#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <string.h>
#include <cstdio>

using namespace std;

void imprimir(unsigned char v[4][4], string nombre_v)
{
  cout << nombre_v << ": " << endl;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      unsigned int aux = (int)v[i][j];
      cout << hex << aux << " ";
    }
    cout << endl;
  }
}

void rellenar_matriz(unsigned char* v, unsigned char v_m[4][4])
{
  int contador = 0;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      v_m[j][i] = v[contador];
      contador++;
    }
  }
}

/*unsigned int** AddRoundKey(unsigned char c[4][4],unsigned char t[4][4])
{
  unsigned int ** aux = new unsigned int*[4];
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      unsigned int aux1 = (int)c[i][j];
      unsigned int aux2 = (int)t[i][j];
      cout << "aux1: " << aux1 << ",aux2: " << aux2 << "=>" << (aux1 ^ aux2) << endl;
      //aux[i][j] = (aux1 ^ aux2);
      cout << "entrando" << endl;
    }
  }
  return aux;
}*/

int main()
{
	unsigned int* iter;
	unsigned char mClaveExp[176]; // contendra la expansion de clave
	unsigned char clave[16] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f}; //clave
  unsigned char arrTexto[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff}; // texto a cifrar
	char resp;
	unsigned char texto[4][4]; // matriz 4x4 texto a cifrar
	unsigned char mClave[4][4]; //matriz 4x4 clave
  unsigned int estado_intermedio[4][4];

  /*for (int i = 0; i < 16; i++){
  //printf(" %02x ",clave[i]);
    unsigned int aux = (unsigned int)arrTexto[i];
    cout << std::hex << aux << ",";
  }
  cout << endl;
  for (int i = 0; i < 16; i++){
  //printf(" %02x ",clave[i]);
    unsigned int aux = (unsigned int)arrTexto[i];
    cout << std::dec << aux << ",";
  }*/
  cout << "AddRoundKey: " << endl;
  rellenar_matriz(clave,*&mClave);
  imprimir(mClave, "Clave");
  rellenar_matriz(arrTexto,*&texto);
  imprimir(texto,"Texto");
  //estado_intermedio = AddRoundKey(mClave,texto);
  //---------------ESTADO INTERMEDIO --------------------------//
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      unsigned int aux1 = (int)mClave[i][j];
      unsigned int aux2 = (int)texto[i][j];
      cout << "aux1: " << aux1 << ",aux2: " << aux2 << "=>" << (aux1 ^ aux2) << endl;
      estado_intermedio[i][j] = (aux1 ^ aux2);
    }
  }

  cout << "Estado intermedio:" << endl;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      unsigned int aux = (int)estado_intermedio[i][j];
      cout << hex << aux << " ";
    }
    cout << endl;
  }

  cout << endl;
  return 0;
}
