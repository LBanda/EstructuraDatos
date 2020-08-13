#include <iostream>
using namespace std;


class Estudiante{  //Base
    public:
        void come(){cout<< "Alimentos Baratos \n";}  //se llama en tiempo de compilación
        virtual  void toma(){cout<< "Bebidas Baratas \n";} //se llama en tiempo de ejecución
};

class Programador : public Estudiante{
    public:
        void come(){cout << "Pizza \n";}
        void toma(){cout << "cafe \n";}
};

/** Al usar apuntadores al obejto padre (Estudiante),
se define come() en tiempo de compilacion(Memoria Estática) por lo que se manda a
llamar a la funcion de come de Estudiante.

Pero toma() es virtual lo que hace que se mande en tiempo de ejecución (Memoria Dinámica)
como "new" es memoria dinámica que crea el objeto en tiempo de ejecución
entonces es hasta que programador ya está creado que se manda a llama toma()
**/

int main(){
   //Mem.Estatica   o  //Mem. Dinámica
   //Tiempo de comp    //tiempo de ejecución
    Estudiante *est =  new Programador();

    est->come();   //imprime Alimentos Baratos  (sin virtual)
    est->toma();   //imprime Cafe               (con virtual)

}
