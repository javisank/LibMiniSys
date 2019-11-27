/*
  LibSemaforoB.h - Libreria para el manejo de la 
  estacion del cruce de calles con semaforos.
  Javier Sankowicz.
*/
#ifndef LibMiniSys_h
#define LibMiniSys_h

#include "Arduino.h"
#include <Servo.h>

#define ROJO 0
#define AMARILLO 1
#define VERDE 2

#define rojo 0
#define amarillo 1
#define verde 2

#define PRESIONADO HIGH
#define NO_PRESIONADO LOW

#define presionado HIGH
#define no_presionado LOW

#define ACTIVADO HIGH
#define DESACTIVADO LOW

#define activado HIGH
#define desactivado LOW

#define NOCHE 0
#define DIA 1

#define noche 0
#define dia 1

//Probar en ambiente y ver que valores tira, para luego mapearlo a un porcentaje.
#define MAXIMO_LUZ 300
#define MINIMO_LUZ 200

#define REPETIR(X) for(int i=0;i<X;i++)

const int pin_Semaforo1_rojo = 7;
const int pin_Semaforo1_amarillo = 5;
const int pin_Semaforo1_verde = 3;
const int pin_Semaforo2_rojo = 6;
const int pin_Semaforo2_amarillo = 4;
const int pin_Semaforo2_verde = 2;

const int pin_Buzzer = 8;
//const int pin_Buzzer2 = 9;

const int pin_Pulsador1 = 12;
const int pin_Pulsador2 = 11;

const int pin_Luz = A1;

const int pin_Sensor_IR1 = A2;
const int pin_Sensor_IR2 = A3;

const int pin_Sensor_Luz = A0;

const int pin_Barrera = 9;
const int anguloArriba = 10;
const int anguloAbajo = 90;

extern Servo motor;

extern void subir_barrera();
extern void bajar_barrera();
extern void inicializar_barrera();

extern void mostrar_cartel(String);
extern void mostrar_numero(int num);
extern int ingresar_numero();
extern void inicializar_sistema();
extern void finalizar();

//Variables para manejo de sensores y pulsadores.
extern int estado_sensor1;
extern int estado_sensor2;
extern int estado_sensor_luz;
extern int estado_pulsador1;
extern int estado_pulsador2;
extern int numero_ingresado;

//Variable contador
extern int contador;

class Semaforo
{
  public:
    Semaforo(int pin_rojo,int pin_amarillo,int pin_verde);
    void encender(int luz);
    void apagar(int luz);
  private:
    int _pin_rojo;
	int _pin_amarillo;
	int _pin_verde;
};

class Buzzer
{
	public:
		Buzzer(int pin);
		void encender();
		void apagar();
	private:
		int _pin;
};

class Luz
{
	public:
		Luz(int pin);
		void encender();
		void apagar();
	private:
		int _pin;
};

class SensorIR
{
	public:
		SensorIR(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
	
};

class SensorLuz
{
	public:
		SensorLuz(int pin,int valorNoche,int valorDia);
		int leer();
		int leer_analogico();
		void esperar(int estado);
	private:
		int _pin;
		int _valorNoche;
		int _valorDia;
};

class Pulsador
{
	public:
		Pulsador(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
};

//Variables de elementos del sistema.
extern Buzzer buzzer;
extern Pulsador pulsador1;
extern Pulsador pulsador2;
extern SensorLuz sensor_luz;
extern SensorIR sensor1;
extern SensorIR sensor2;
extern Semaforo semaforo1;
extern Semaforo semaforo2;
extern Luz luz;

#endif

