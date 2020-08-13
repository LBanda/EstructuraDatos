# last-nite
Código de apoyo al curso de Estructuras de datos

## Para compilar
1. Ve a tu archivo  `.replit`
2. Edita la línea que contiene `run` de la siguiente manera:

`run = "g++ archivo.cpp [librería1.h] [librería2.h] ...; ./a.out"`

3. Donde `archivo.cpp` es el nombre del archivo `.cpp` que contiene la función `main()`, y `[librería#.h]` es el nombre de las librerías que requiere tu archivo principal si es que no se incluyeron con `#include` en el código fuente. `./a.out` es para ejecutar el programa después de ser compilado; remueve esta parte si deseas ejecutar el programa manualmente.
4. Si quieres ponerle un nombre particular al archivo ejecutable, agrega después de la lista de las librerías `-o nombre_ejecutable`, donde `nombre_ejecutable` es el nombre que le quieres dar al archivo. Para ejecutar el archivo utiliza: `./nombre_ejecutable`


[![Run on Repl.it](https://repl.it/badge/github/ejuarezp/last-nite)](https://repl.it/github/ejuarezp/last-nite)