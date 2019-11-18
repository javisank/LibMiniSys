//Incluyo la libreria.
#include <LibMiniSys.h>

void setup() {
 //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() 
{
  //Leer sensor de luz y guardar el estado en estado_sensor_luz.
  estado_sensor_luz = sensor_luz.leer();
  
  if(estado_sensor_luz == DIA)    //Si el sensor lee que es de dia
  {
    mostrar_cartel("Es de dia.\n");   //escribo por monitor serie que es de dia.
  }
  else //Si el sensor lee que es de noche
  {
    mostrar_cartel("Es de noche.\n");   //escribo por monitor serie que es de noche.
  }

  //Espera de 500 mSeg entre lecturas del sensor.
  delay(500);

}
