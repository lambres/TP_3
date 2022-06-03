#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int getIDNuevo(int* nuevoId);
int putIDNuevo(int* nuevoId);

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int auxIndice;
    LinkedList* listaPasajeros = ll_newLinkedList();
    //Passenger* auxPassenger;

    do{
    	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
    	printf("3. Alta de pasajero\n");
    	printf("4. Modificar datos de pasajero\n");
    	printf("5. Baja de pasajero\n");
    	printf("6. Listar pasajeros\n");
    	printf("7. Ordenar pasajeros\n");
    	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
    	printf("10. Salir\n");
    	utn_getNumeroInt(&option, "Seleccione opcion", "Error reintente", 1, 10, 1);
        switch(option)
        {
            case 1://Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)
                controller_loadFromText("data.csv",listaPasajeros);
                break;
            case 2://Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
            	controller_loadFromBinary("data.bin", listaPasajeros);
                break;
            case 3://Alta de pasajero
            	if (!getIDNuevo(&auxIndice))
            	{
            		auxIndice++;
            	}
            	if (!putIDNuevo(&auxIndice))
				{
					printf("Nuevo Id utilizado %d:\n",auxIndice);
				}

            	//controller_addPassenger(listaPasajeros);
            	break;
            case 4://Modificar datos de pasajero
            	controller_editPassenger(listaPasajeros);
                break;
            case 5://Baja de pasajero
            	controller_removePassenger(listaPasajeros);
                break;
            case 6://Listar pasajeros
            	controller_ListPassenger(listaPasajeros);
                break;
            case 7://Ordenar pasajeros
            	controller_sortPassenger(listaPasajeros);
                break;
            case 8://Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
            	controller_saveAsText("newData.csv",listaPasajeros);
                break;
            case 9://Guardar los datos de los pasajeros en el archivo data.csv (modo binario)
            	controller_saveAsBinary("newData.dat", listaPasajeros);
                break;
            case 10://Salir
                break;
        }
    }while(option != 10);
    return 0;
}

int getIDNuevo(int* nuevoId)
{
	FILE* pArchivo;

	if ((pArchivo=fopen("id.csv","r"))==NULL)
	{
		pArchivo=fopen("id.csv","w+");
		fscanf(pArchivo,"%d",nuevoId);
		if(*nuevoId < 1000)
		{
			*nuevoId=1001;
		}
	}
	//devuleve 0 si el archivo se cerro correctamente
	return fclose(pArchivo);
}


int putIDNuevo(int* nuevoId)
{
	FILE* pArchivo;
	if (!((pArchivo=fopen("id.csv","r"))==NULL))
	{
		pArchivo=fopen("id.csv","w+");
		fwrite(nuevoId,sizeof(nuevoId),1,pArchivo);
	}
	//devuleve 0 si el archivo se cerro correctamente
	return fclose(pArchivo);
}


