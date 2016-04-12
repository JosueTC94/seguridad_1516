#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funciones.cpp"

using namespace std;

int main()
{
  string opcion;
  bool control = false;
  do {
      cout << endl;
      escoger_secreto();
      cout << "---------------------------------------" << endl;
      informacion_inicial();
      cout << "---------------------------------------" << endl;
      cout << "Intercambio de claves..." << endl;
      cout << "Paso1.- Calcular y." << endl;
      calcular_y();
      cout << "Paso2.- Calcular k." << endl;
      generar_k();
      mostrar_resultados();
      cout << "¿Desea ejecutar de nuevo?[S/N]" << endl;
      cin >> opcion;

      if(opcion == "S" || opcion == "s")
      {
        control = false;
      }
      else
      {
        control = true;
      }
  } while(control == false);
  return 0;
}
