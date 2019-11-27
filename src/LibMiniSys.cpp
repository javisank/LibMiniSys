/*
  LibSemaforoB.cpp - Libreria para el manejo de la 
  estacion del cruce de calles con semaforos.
  Javier Sankowicz.
*/

#include "Arduino.h"
#include "LibMiniSys.h"

/* ************ Funciones de la clase Semaforo ************ */

Semaforo::Semaforo(int pin_rojo,int pin_amarillo,int pin_verde)
{
  pinMode(pin_rojo, OUTPUT);
  pinMode(pin_amarillo, OUTPUT);
  pinMode(pin_verde, OUTPUT);
  _pin_rojo = pin_rojo;
  _pin_amarillo = pin_amarillo;
  _pin_verde = pin_verde;
  digitalWrite(_pin_rojo,LOW);
  digitalWrite(_pin_amarillo,LOW);
  digitalWrite(_pin_verde,LOW);
}

void Semaforo::encender(int luz)
{
  switch(luz)
  {
	  case ROJO:
	  digitalWrite(_pin_rojo,HIGH);
	  break;
	  case AMARILLO:
	  digitalWrite(_pin_amarillo,HIGH);
	  break;
	  case VERDE:
	  digitalWrite(_pin_verde,HIGH);
	  break;
	  default:
	  break;
  }
}

void Semaforo::apagar(int luz)
{
	switch(luz)
	{
		case ROJO:
		digitalWrite(_pin_rojo,LOW);
		break;
		case AMARILLO:
		digitalWrite(_pin_amarillo,LOW);
		break;
		case VERDE:
		digitalWrite(_pin_verde,LOW);
		break;
		default:
		break;
  }
}

/* ********************************************************************************** */

/* ************ Funciones de la clase Buzzer **************** */

Buzzer::Buzzer(int pin)
{
	pinMode(pin,OUTPUT);
	_pin = pin;
	digitalWrite(_pin,LOW);
}

void Buzzer::encender()
{
	digitalWrite(_pin,HIGH);
}

void Buzzer::apagar()
{
	digitalWrite(_pin,LOW);
}

/* ********************************************************************************** */

/* ************ Funciones de la clase LuzCalle **************** */

Luz::Luz(int pin)
{
	pinMode(pin,OUTPUT);
	_pin = pin;
	digitalWrite(_pin,LOW);
}

void Luz::encender()
{
	digitalWrite(_pin,HIGH);
}

void Luz::apagar()
{
	digitalWrite(_pin,LOW);
}

/* ********************************************************************************** */

/* ************ Funciones para el manejo de los  servos de las barreras************** */
Servo motor;

void subir_barrera(){
  motor.write(anguloArriba);
}

void bajar_barrera(){
  motor.write(anguloAbajo);
}

void inicializar_barrera(){
	motor.attach(pin_Barrera);
	bajar_barrera();
}

/* ********************************************************************************* */

/* ************ Funciones de la clase SensorIR ************ */

SensorIR::SensorIR(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int SensorIR::leer()
{
	return(digitalRead(_pin));
}

void SensorIR::esperar(int estado)
{
	while(leer()!=estado);
} 

/* ********************************************************************************** */

/* ************ Funciones de la clase SensorLuz ************** */

SensorLuz::SensorLuz(int pin,int valorNoche,int valorDia)
{
	pinMode(pin,INPUT);
	_pin = pin;
	_valorNoche = valorNoche;
	_valorDia = valorDia;
}

int SensorLuz::leer()
{
	int value;
	value = analogRead(_pin);
	if(value>=_valorNoche)
	{
		return(NOCHE);
	}
	else if(value<=_valorDia)
	{
		return(DIA);
	}
	return(DIA);
}

int SensorLuz::leer_analogico()
{
	int value=0;
	value = analogRead(_pin);
	return(value);
}

void SensorLuz::esperar(int estado)
{
	while(leer()!=estado);
}

/* ********************************************************************************** */

/* ************ Funciones de la clase Pulsador ************** */

Pulsador::Pulsador(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int Pulsador::leer()
{
	return(digitalRead(_pin));
}

void Pulsador::esperar(int estado)
{
	while(leer()!=estado);
}

/* ********************************************************************************** */

/* ************Ingresar numero por puerto serie************** */

int ingresar_numero()   //devuelve un entero que va de -32768 a 32767
{
  String readString;
  
  while(!(Serial.available()>0));

  while(Serial.available()>0)
  {
    char c = Serial.read();
    readString += c;
    delay(2);
  }

  int number = readString.toInt();

  return number;
}

/* ********************************************************************************** */

/* ************Funciones imprimir texto********************* */

void mostrar_cartel(String text)
{
	Serial.print(text);
	Serial.print(" ");
}

void mostrar_numero(int num)
{
	Serial.println(num);
}

/* ********************************************************************************** */

/* *****************Inicializacion************************** */
void inicializar_sistema()
{
	Serial.begin(9600);
	//inicializar_barrera();
}
/* ********************************************************************************** */

/* ******************Finalizacion*************************** */
void finalizar()
{
	while(1);
}
/* ********************************************************************************** */

//Variables para manejo de sensores y pulsadores.
int estado_sensor1=DESACTIVADO;
int estado_sensor2=DESACTIVADO;
int estado_sensor_luz=DIA;
int estado_pulsador1=NO_PRESIONADO;
int estado_pulsador2=NO_PRESIONADO;
int numero_ingresado=0;

//Variable contador
int contador=0;

//Variables de elementos del sistema.
Buzzer buzzer(pin_Buzzer);
Pulsador pulsador1(pin_Pulsador1);
Pulsador pulsador2(pin_Pulsador2);
SensorLuz sensor_luz(pin_Sensor_Luz,MINIMO_LUZ,MAXIMO_LUZ);
SensorIR sensor1(pin_Sensor_IR1);
SensorIR sensor2(pin_Sensor_IR2);
Semaforo semaforo1(pin_Semaforo1_rojo,pin_Semaforo1_amarillo,pin_Semaforo1_verde);
Semaforo semaforo2(pin_Semaforo2_rojo,pin_Semaforo2_amarillo,pin_Semaforo2_verde);
Luz luz(pin_Luz);
