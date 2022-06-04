/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

Passenger* Passenger_new()
{
	return (Passenger*) malloc(sizeof(Passenger));
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr ,char* apellidoStr, char* precioStr,
		char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	int auxTipoPasajero = -1;
	Passenger* aux = Passenger_new();
	if (aux != NULL)
	{
		aux->id=atoi(idStr);
		strncpy(aux->nombre,nombreStr,50);
		strncpy(aux->apellido,apellidoStr,50);
		aux->precio = atof(precioStr);
		aux->tipoPasajero=auxTipoPasajero;
		strncpy(aux->codigoVuelo,codigoVueloStr,7);
		if(strncmp(tipoPasajeroStr,"FirstClass",10)==0)
		{
			auxTipoPasajero = 0;
		}
		else
		{
			if(strncmp(tipoPasajeroStr,"ExecutiveClass",10)==0)
			{
				auxTipoPasajero = 1;
			}
			else
			{
				if(strncmp(tipoPasajeroStr,"EconomyClass",10)==0)
				{
					auxTipoPasajero = 2;
				}
			}
		}
	}
	if(auxTipoPasajero==-1)
	{
		aux = NULL;
	}
	return aux;
}

void Passenger_delete(Passenger* this)
{
	free (this);
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		this->id=id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id >=0 )
	{
		id=&this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre,nombre,50);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL )
	{
		strncpy(nombre,this->nombre,50);
		retorno = 0;
	}
	return retorno;
}


int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL )
	{
		strncpy(this->apellido,apellido,50);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL )
	{
		strncpy(apellido,this->apellido,50);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio >=0 )
	{
		precio=&this->precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;
	if (this != NULL && tipoPasajero >= 0 )
	{
		this->tipoPasajero=tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL )
	{
		tipoPasajero=&this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if (this != NULL && codigoVuelo != NULL)
	{
		strncpy(this->codigoVuelo,codigoVuelo,7);
		retorno = 0;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL )
	{
		strncpy(codigoVuelo,this->codigoVuelo,7);
		retorno = 0;
	}
	return retorno;
}
