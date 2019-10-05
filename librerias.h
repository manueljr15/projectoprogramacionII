#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include<time.h>
#include<windows.h>
using namespace std;

struct nodo{
	float promedio;
	int id_cocinero;
	char nombre[20];
	char status[10];
	char turno[10];
	float pedidosA;
	float ganancias;
	struct nodo *izq, *der;
};

typedef struct nodo *ARBOLB;
ARBOLB arbol = NULL;

#define CONTRASENIA "upslp123"
#define precioTacos 5.5
#define precioHamburguesa 25

#include"validaciones.h"
#include"agregar.h"
#include"recuperar.h"
#include"modificar.h"
#include"actualizar.h"
#include"asignar.h"
#include"administrador.h"
#include"personal.h"
#include"creditos.h"
