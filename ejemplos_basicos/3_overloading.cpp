// overloading operators example
#include <iostream>
using namespace std;

class Port{
    private:
        int priv1, priv2;
    
	public:

        int pub1, pub2;		
	   // ejemplos de constructores
	   
	   Port () {};
	   Port (int a, int b, int c, int d): priv1(a), pub1(c){ priv2 = b; pub2=d;}
	   Port operator * (const Port&); // se usa const para encapsular el objeto i.e., que no sea modificable ya que el paso es por referencia y existe el riesgo de cambios al objeto. 
	   
	   int get_priv1() {return priv1;}
	   int get_priv2() {return priv2;}
};

/*
* sobrecarga de * para multipliación entre objetos.
*/

Port Port::operator * (const Port & param){
  Port temp;
  temp.priv1 = priv1 * param.priv1;
  temp.priv2 = priv2 * param.priv2;
  temp.pub1 = pub1 * param.pub1;
  temp.pub2 = pub2 * param.pub2;
  return temp;
}

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector&);
    CVector operator - (const CVector&);
    CVector& operator = (const CVector&);
};

CVector CVector::operator- (const CVector & param){
  CVector temp;
  temp.x = x - param.x;
  temp.y = y - param.y;
  return temp;
}

CVector CVector::operator+ (const CVector & param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

CVector& CVector::operator= (const CVector& param)
{
  x=param.x;
  y=param.y;
  return *this;
}

int main () {
  CVector foo (3,1);
  CVector bar (1,2);
  CVector fei(9,9);
  CVector result;
  result = foo + bar - fei;
  cout << result.x << ',' << result.y << '\n';
  Port hugo(1,2,3,4);
  Port paco(5,6,7,8);
  Port luis;
  //  luis = hugo.operator*(paco);
  luis = hugo * paco;
  cout << hugo.get_priv1() << ',' << hugo.get_priv2() << ',' << hugo.pub1 << ',' << hugo.pub2 << '\n' ;
  cout << paco.get_priv1() << ',' << paco.get_priv2() << ',' << paco.pub1 << ',' << paco.pub2 << '\n' ;
  cout << luis.get_priv1() << ',' << luis.get_priv2() << ',' << luis.pub1 << ',' << luis.pub2 << '\n' ;
  CVector new_one = result;
  result = result - fei;
  cout << "result" << result.x << ',' << result.y << '\n';
  cout << "new_one" << new_one.x << ',' << new_one.y << '\n';
  return 0;
}