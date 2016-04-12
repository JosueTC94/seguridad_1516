typedef double tdato;
struct Informacion
{
    tdato numero_primo;
    tdato alfa;
    tdato x;
    tdato y;
    tdato k;
}Data_A,Data_B;

using namespace std;

void escoger_secreto(void)
{
    tdato primo;
    tdato alfa;
    cout << "Introduzca numero primo: ";
    cin >> primo;

    cout << "Introduzca alfa:";
    cin >> alfa;
    Data_A.numero_primo = primo;
    Data_A.alfa = alfa;
    Data_B.numero_primo = primo;
    Data_B.alfa = alfa;

    cout << "Introduzca xa: ";
    cin >> Data_A.x;

    cout << "Introduzca xb: ";
    cin >> Data_B.x;
}

void informacion_inicial(void)
{
    cout << "Informacion actual:\tUsu_A\tUsu_B" << endl;
    cout << "Numero primo:\t\t" << Data_A.numero_primo << "\t" << Data_B.numero_primo << endl;
    cout << "Numero alfa:\t\t" << Data_A.alfa << "\t" << Data_B.alfa << endl;
    cout << "X:\t\t\t" << Data_A.x <<"\t" << Data_B.x << endl;
}

double exponenciacion_rapida(double base, double exponente, double modulo)
{
    tdato x = 1;
    tdato y = fmod(base,modulo);
    while(exponente > 0 && y > 1)
    {
      if(fmod(exponente,2) != 0)
      {
        //Impar
        x = fmod((x*y),modulo);
        exponente = exponente-1;
      }
      else
      {
        //Par
        y = fmod((y*y),modulo);
        exponente = exponente / 2;
      }
    }
    return x;
}

void calcular_y(void)
{
    //Data_A.y = fmod(pow(Data_A.alfa,Data_A.x), Data_A.numero_primo);
    //Data_B.y = fmod(pow(Data_B.alfa,Data_B.x), Data_B.numero_primo);
    Data_A.y = exponenciacion_rapida(Data_A.alfa,Data_A.x,Data_A.numero_primo);
    Data_B.y = exponenciacion_rapida(Data_B.alfa,Data_B.x,Data_B.numero_primo);
}

void generar_k(void)
{
    //Data_A.k = fmod(pow(Data_B.y,Data_A.x), Data_A.numero_primo);
    //Data_B.k = fmod(pow(Data_A.y,Data_B.x), Data_B.numero_primo);
    Data_A.k = exponenciacion_rapida(Data_B.y,Data_A.x,Data_A.numero_primo);
    Data_B.k = exponenciacion_rapida(Data_A.y,Data_B.x,Data_B.numero_primo);
}

void mostrar_resultados(void)
{
  informacion_inicial();
  cout << "Y:\t\t\t" << Data_A.y <<"\t" << Data_B.y << endl;
  cout << "k:\t\t\t" << Data_A.k <<"\t" << Data_B.k << endl;
}
