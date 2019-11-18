//Incluyo la libreria.
#include <LibMiniSys.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();

  //Función de inicialización de la barrera.
  inicializar_barrera();
}

void loop() {
  
  //Subo la Barrera
  subir_barrera();

  //Espera de 1 segundo
  delay(1000);

  //Bajo la Barrera
  bajar_barrera();

  //Espera de 1 segundo
  delay(1000);
 
}



