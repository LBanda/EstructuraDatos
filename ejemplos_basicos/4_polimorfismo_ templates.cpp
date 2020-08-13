// class templates
#include <iostream>
using namespace std;

template <class T>  // nombreObjetoGenerico T se refiere a Template 
class Par {
    T a, b; // objetos T seran  a y b
  public:
    Par (T generico1, T generico2) {a=generico1; b=generico2;}  //constructor 
    T getmax ();    // method 
};

/*La sintaxis para nombre funciones template es: 

template <class nombreObjetoGenerico> 
(dato a retornar) nombreClase <nombreObjetoGenerico> :: nombreFuncion(parametros)

*/
template <class T>
T Par<T>::getmax ()   
{
  T retval;
  if (a > b) 
	retval = a;
  else 
	retval = b;
  return retval;
}

/*

En el main se crean objetos de clase par, pero en cada una el genérico se
sustituye por un tipo de dato concreto. De esta forma la misma clase se adapta a diferentes
tipos de dato, este es un aspecto de polimorfismo.

*/

int main () {
  Par <int> objectConInts (100, 75);   // con ints
  cout << objectConInts .getmax() << "\n";
  
  Par <string> objectConStrings("rio", "lloro");  // con strings
  cout << objectConStrings .getmax() << "\n";
  
  Par <float> objectConFloats(10.39, 10.04);  // con floats
  cout << objectConFloats .getmax() << "\n";
  return 0;
}