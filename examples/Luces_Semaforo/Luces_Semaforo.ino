//Incluyo la libreria.
#include <LibMiniSys.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() 
{
  semaforo2.apagar(ROJO);
  semaforo2.apagar(AMARILLO);
  semaforo2.apagar(VERDE);

  semaforo1.encender(ROJO);
  semaforo1.encender(AMARILLO);  
  semaforo1.encender(VERDE);

  delay(1000);    //espera de 1000 mSeg o 1 Seg.

  semaforo1.apagar(ROJO);
  semaforo1.apagar(AMARILLO);
  semaforo1.apagar(VERDE);

  semaforo2.encender(ROJO);
  semaforo2.encender(AMARILLO);
  semaforo2.encender(VERDE);

  delay(1000);    //espera de 1000 mSeg o 1 Seg.
}
