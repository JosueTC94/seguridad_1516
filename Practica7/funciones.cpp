typedef double tdato;
struct Usuario
{
    tdato numero_primo;
    tdato alfa;
    tdato x;
    tdato y;
    tdato k;
};

using namespace std;


void informacion_inicial(double &primo,double &alfa_)
{
  cout << "Introduzca numero primo: ";
  cin >> primo;
  cout << "Introduzca alfa:";
  cin >> alfa_;
  cout << endl;
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

void calcular_y(vector<Usuario> &u)
{
    double auxiliar = 0;
    for(int i=0;i<u.size();i++)
    {
      auxiliar = exponenciacion_rapida(u[i].alfa,u[i].x,u[i].numero_primo);
      //cout << "exponenciacion_rapida => " << auxiliar << endl;
      u[i].y = auxiliar;
    }
}

void generar_k(vector<Usuario> &u)
{
    double auxiliar = 0;
    for(int i=0;i<u.size();i++)
    {
      if(i % 2 == 0)
      {
        auxiliar = exponenciacion_rapida(u[i+1].y,u[i].x,u[i].numero_primo);
        //cout << "exponenciacion_rapida => " << auxiliar << endl;
        u[i].k = auxiliar;
      }
      else
      {
        auxiliar = exponenciacion_rapida(u[i-1].y,u[i].x,u[i].numero_primo);
        //cout << "exponenciacion_rapida => " << auxiliar << endl;
        u[i].k = auxiliar;
      }
    }
}

void modificacion(vector<Usuario> &u, vector<tdato> &y_mod)
{
    //cout << "Accediendo a la modificacion..." << endl;
    //cout << "Tamanio vector y_mod: " << y_mod.size() << endl;
    int contador = 0;
    y_mod[contador] = u[contador].y;
    for(contador = 1; contador < y_mod.size(); contador++)
    {
      double auxiliar = exponenciacion_rapida(y_mod[contador-1],u[contador].x,u[contador].numero_primo);
      //cout << "exponenciacion_rapida para " << contador << " => " << auxiliar << endl;
      y_mod[contador] = auxiliar;
    }
}

void mostrar_resultados(int primo, int alfa_,vector<Usuario> &u,vector<tdato> y_mod)
{
  cout << "Numero primo: " << primo << endl;
  cout << "Alfa: " << alfa_ << endl;
  for(int i=0;i<u.size();i++)
  {
    cout << "Usuario " << i+1 << ": ";
    cout << " x => " << u[i].x << " , y => " << u[i].y << " , k => " << u[i].k << endl;
  }
  cout << "Modificacion: " << endl;
  for(int i=0;i<y_mod.size();i++)
  {
    if(i == 0)
    {
      cout << "Caso " << i << ": " << y_mod[i] << endl;
    }
    else
    {
      cout << "Caso " << i << ": " << y_mod[i] << " => y anterior = " << y_mod[i-1] << ", nueva x = " << u[i].x << " => " << "(" << y_mod[i-1] << ")^" << u[i].x << endl;
    }
  }
  cout << "K final => " << y_mod[y_mod.size()-1] << endl;
}
