//Incluyo la libreria.
#include <LibMiniSys.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() {

  //leer pulsador 1 y guardarlo en valor_pulsador1.
  estado_pulsador1 = pulsador1.leer();
  
  if(estado_pulsador1 == PRESIONADO)
  {
    mostrar_cartel("Pulsador 1 PRESIONADO\n");
  }
  else
  {
    mostrar_cartel("Pulsador 1 NO PRESIONADO\n");
  }

  //leer pulsador 1 y guardarlo en valor_pulsador2.
  estado_pulsador2 = pulsador2.leer();
  
  if(estado_pulsador2 == PRESIONADO)
  {
    mostrar_cartel("Pulsador 2 PRESIONADO\n");
  }
  else
  {
    mostrar_cartel("Pulsador 2 NO PRESIONADO\n");
  }

  mostrar_cartel("----------------------------------\n");
  //espera 500 mSeg.
  delay(500);
}
