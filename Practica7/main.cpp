#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>

#include "funciones.cpp"

using namespace std;

int main()
{
  double numero_primo = 0;
  double alfa = 0;
  int numero_users = 2;
  vector<Usuario> users;
  vector<double> users_y_mod; // vector para la modificación
  int contador = 0;
  string opcion;
  bool control = false;
  do {

      informacion_inicial(numero_primo,alfa);

      cout << "Introduzca el numero de usuarios:" << endl;
      cin >> numero_users;
      while(contador < numero_users)
      {
        Usuario aux;
        int x_;
        aux.numero_primo = numero_primo;
        aux.alfa = alfa;
        users.resize(users.size()+1);
        users_y_mod.resize(users_y_mod.size()+1);
        cout << "Para usuario " << contador+1 << " => Introduzca x:";
        cin >> x_;
        aux.x = x_;
        users[contador] = aux;
        contador++;
      }
      cout << "---------------------------------------" << endl;

      cout << "Intercambio de claves..." << endl;
      cout << "Paso1.- Calcular y." << endl;
      calcular_y(users);
      cout << "Paso2.- Calcular k." << endl;
      generar_k(users);
      cout << "Paso3.- Modificacion." << endl;
      modificacion(users,users_y_mod);
      cout << "---------------------------------------" << endl;

      mostrar_resultados(numero_primo,alfa,users,users_y_mod);

      cout << "¿Desea ejecutar de nuevo?[S/N]" << endl;
      cin >> opcion;

      if(opcion == "S" || opcion == "s")
      {
        control = false;
        while(!users.empty())
        {
            users.pop_back();
        }
        numero_primo = 0;
        alfa = 0;
        numero_users = 0;
        contador = 0;
      }
      else
      {
        control = true;
      }
  } while(control == false);
  return 0;
}
