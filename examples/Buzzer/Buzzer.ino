//Incluyo la libreria.
#include <LibMiniSys.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() {

  //Enciende Buzzer 1.
  buzzer.encender();

  //Espera de 1 segundo.
  delay(1000);

  //Apaga Buzzer 1.
  buzzer.apagar();

  //Espera de 3 segundos.
  delay(3000);

}
