#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	char auxId[5];
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[6];
	char auxCodigoVuelo[20];
	char auxTipoPasajero[15];
	char auxEstadoVuelo[20];

	int camposLeidos;

	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\r]\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
		do
		{
			camposLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\r]\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
			if (camposLeidos==7)
			{
				Passenger* pasajero = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
				if (pasajero!=NULL)
				{
					ll_add(pArrayListPassenger, pasajero);
					retorno = 0;
				}
			}
		}while (!feof(pFile));
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
