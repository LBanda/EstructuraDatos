#include <iostream>
using namespace std; //para no tener que poner std al principio de todo.

//clase papa que va a heredar a las demás
class Papa {
	protected:  //solo las pueden ser vistas por los hijos.
		int var1;
		string var2;

	public:
		Papa(){var1 = 0; var2 ="";}  //constructor por default
		Papa(int p, string t) : var1(p), var2(t) {}; //constructor con variables

		int get_var1() const {return var1;} // getter de var1
		string get_var2() const {return var2;} // getter de var2
		void imprime()const {cout<< "\n("<< var1<< ")," << var2<< "\n";}
};

//clase que hereda de la clase padre
class HijoA : public Papa{
	string var3a; // agrega esta variable a la clase papa
	public:
		HijoA(int p, string t, string art) : Papa(p,t), var3a(art){}; // agrega esta funcion a la clase papa
		void set_var3a(string a){ var3a=a;}
		void imprime()const {cout<< "\n("<< var1<< ")," << var2<< " var3a:" << var3a<<"\n";} //
};

class HijoB: public Papa{
	float var3b;
	public:
        HijoB(int p, string t, float num) : Papa(p,t), var3b(num){}; // agrega esta funcion a la clase papa
		void set_var3a(float b){ var3b=b;}
		void imprime()const {cout<< "\n("<< var1<< ")," << var2<< " var3a:" << var3b<<"\n";} //
};

int main (){
	Papa ancestro(99, "abcdef");   // lo que se hereda es la estructura de los objetos, mas no sus valores.
	ancestro.imprime();
	HijoA descendiente(0001, "asdfgh","jkl");
	descendiente.imprime();
	HijoB algunOtroHijo(43,"vrewrv", 3.3333);
	algunOtroHijo.imprime();
	return 0;
}
