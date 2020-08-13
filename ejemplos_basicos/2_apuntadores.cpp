//example ptr c++

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int suma_var(int, int);
int suma_ptr(int*, int*);

int main(){

/*
Ejemplos básicos de lo que imprimen diferentes usos básicos de apuntadores y refrencias en c. 
Es importante distinguir que: 
   * se refiere a un apuntador (un apuntador es una variable a guarda un referencia, es decir, que apunta a una variable) 
   & obitene la direccion en memoria (referencia) de una variable
*/
     //What is stored where
	 int a = 10;    //variable integer = numero
	 int *ptra=&a;  //apuntador integer  =  la referencia de a
	 int **ptrptra = &ptra; //apuntador a apuntador integer = la referencia del apuntandor integer

	 cout << "a \t" << a << "\n";  //variable
	 cout << "&a \t" << &a << "\n";  // referencia de variable a
	 cout << "ptra \t" << ptra << "\n";  // apuntador
	 cout << "&ptra \t" << &ptra << "\n";  // referencia del apuntador
	 cout << "*ptra \t" << *ptra << "\n";  // valor del apuntador 
	 cout << "ptrptra \t" << ptrptra << "\n"; // apuntador a apuntador
	 cout << "&ptrptra \t" << &ptrptra << "\n";  // referencia de apuntador a apuntador 
	 cout << "**ptrptra \t" << **ptrptra << "\n\n";  //pointer to pointer value

/*
La sintaxis de  * cambia al momento de usarse.   *ptra = a lo que sea modifica el valor de la variable a la que apunta ptra (porque ptra es un apuntador normal)
*/
	 
	 *ptra = a -1;   //guarda a -1  en lo que sea que esta apuntando *ptra (como ptra apunta 'a' ahora  'a'  vale 9)
	 cout << "*ptra = a -1 ;\t a \t" << a << "\n\n";

	 **ptrptra = a-1; //guarda a -1  en lo que sea que esta apuntando **ptrptra (porque ptrptra se declaró como un doble apuntador) 'a' valia 9 pero ahora -1 se guarda 8 en 'a' porque ptrptra apunta 'a' lo que apunta ptra.
	 cout << "**ptrptra = a-1;\t a \t" << a << "\n\n";
	 
	 cout << "&a \t" << &a << "\n";
	 cout << "ptra \t" << ptra << "\n";
	 cout << "&ptra \t" << &ptra << "\n";
	 cout << "*ptra \t" << *ptra << "\n";
	 cout << "ptrptra \t" << ptrptra << "\n";
	 cout << "&ptrptra \t" << &ptrptra << "\n";
	 cout << "**ptrptra \t" << **ptrptra << "\n\n";


/*
Paso con de apuntadores a funciones, las funciones pueden recibir o devolver apuntadores, abajo del main vienen las 2 funciones que mandamos a llamar, la primera es un función normal con enteros, la segunda es una función que reciber apuntadores como parámetros. 
*/	 
	 int num1 =10, num2 =20;
     cout << " res_var " << suma_var(num1, num2);
     cout << "\n num1 "<< num1<<  " num2 "<< num2 << "\n\n";
     cout << " res_ptr " << suma_ptr(&num1, &num2);
     cout << "\n num1 "<< num1<<  " num2 "<< num2 << "\n";

	 
/*
Los apuntadores nos permiten almacenar elementos en el heap (memoria dinámica) esto nos da acceso a guardar objetos más grandes de los que se definen por los tipos base de c. Para hacer uso de este espacio es común usar la función malloc que reserva espacion en la memoria dinámica. 
*/
	
	 int *p, *q, n; //creo apuntadores y variabe para longitud
     cout << "\n define la longitud del arreglo?";
     cin >> n;

	 p = (int*)malloc(n*sizeof(int)); // reservo en la memoria espacion para guardar n enteros (osea el arreglo)

     cout << "\n arg in p  \n";
	 for(int i = 0 ; i < n; i++){
		p[i]=99; // comment this to show garbage
		cout << p[i]<< " ";
	 }
	 cout << p[n] << "\n";
/*
Un uso práctico de apuntadores es cuando tenemos un arreglo que es demasiado grande para c (generaría un stack overflow), lo que hacemos es lo guardamos en un apuntador de tal forma que se guarde en el heap, el cual está limitado por la memoria de la computadora.
*/
	// int crash[100000000];  // Esta linea rompe el programa en tiempo de ejecucion porque c no puede crear un arreglo de ese tamaño en el stack
	int *c = new int[10000000];  //
	free(c); //libera la memoria en el heap
}

// parametros por valor o copia, los valores de a y b no se modifican
int suma_var(int a, int b){
    int c = a + b;
    a = 2;
    b = 7;
    return c;
}


// parametros por referencia los valores de a y b se modifican y se guardan los cambios en la variables del main
int suma_ptr(int *a, int *b){
    int c = *a + *b;
    *a = 2;
    *b = 7;
    return c;
}
