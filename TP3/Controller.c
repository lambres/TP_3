#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		if(ll_len(pArrayListPassenger)>0)
		{
			puts("Archivo cargado previamente");
		}
		else
		{
			FILE* pFile=fopen("data.csv","r");
			parser_PassengerFromText(pFile, pArrayListPassenger);
			/*
			if(!parser_PassengerFromText(pFile, pArrayListPassenger))
			{
				printf("Archivo leido correctamnte\n");
			}
			*/
			fclose(pFile);
		}
	}


    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	int i;
	Passenger* pPasajero=NULL;
	if (pArrayListPassenger != NULL)
	{
		for (i=0; i<ll_len(pArrayListPassenger);i++)
		{
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			printf("Indice: %d Nombre: %s Apellido: %s Precio: %.2f CodVuelo: %s\n",pPasajero->id, pPasajero->nombre,
					pPasajero->apellido, pPasajero->precio, pPasajero->codigoVuelo);
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

