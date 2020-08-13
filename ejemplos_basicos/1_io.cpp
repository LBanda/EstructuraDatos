/**
 *  @author: Eduardo Juarez
 *  @date: 22/07/20
 *  Ejemplos básicos de input/output
 **/

#include <iostream> //Librería para manejar inputs y outputs 

using namespace std; //Declararla consola estándar como espacio de trabajo default. Sin esta declaración cada vez que quisiéramos usar cout, lo tendrías que hacer con std::cout

int main() {
  //Para imprimir en pantalla
  cout << "¡Hola mundo!";
  
  //Para terminar una línea  
  cout << endl;

  //Para imprimir en pantalla y terminar una línea
  cout << "Bienvenido al curso Estructura de datos" << endl;

  cout << "ola k ase? ";
  string actividad;

  //Para leer una variable
  cin >> actividad;

  //Para concatenar
  cout << actividad << "o k ase?" << endl;

  //Para imprimir en los logs de información
  clog << "INFO: Ejecución de io finalizada" << endl;

  //Para imprimir en los logs de errores
  cerr << "ERROR: 0" << endl;
}