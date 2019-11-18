//Incluyo la libreria.
#include <LibMiniSys.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() {
  
  //Enciendo la luz.
  luz.encender();
  
  //Espera de 1 segundo.
  delay(1000);

  //Apago la luz.
  luz.apagar();

  //Espera de 1 segundo.
  delay(1000);

}
