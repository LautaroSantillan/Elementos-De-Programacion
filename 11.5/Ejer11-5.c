/*En un estadio de f�tbol se incorpor� un nuevo sistema para censar la cantidad de espectadores que pasan por cada una de
las entradas de forma de analizar el comportamiento de la gente y poder dise�ar una mejor distribuci�n de las v�as de acceso.

El estadio tiene 15 puertas numeradas del 1 al 15. La recolecci�n de datos se realiz� en todos los partidos disputados en
el estadio a lo largo de varios meses para poder tener un volumen de informaci�n suficiente que permita realizar un an�lisis.

La informaci�n registrada se encuentra en un archivo (EVENTOS.dat) con la siguiente estructura:

 �  C�digo del Evento (texto de 10 caracteres m�ximo) //ORDENADO CORTE DE CONTROL
 �  N�mero de puerta (entero)
 �  Cantidad de Espectadores (entero)

La informaci�n se haya ordenada por C�digo de Evento. Se solicita calcular y mostrar:

 a.  Cantidad de espectadores por cada evento.
 b.  El evento con menor cantidad de espectadores.
 c.  Grabar un archivo con el promedio de espectadores que ingresaron por cada una de las 15 entradas en todos los eventos
 analizados, informando el n�mero de puerta y promedio.*/
 //INCLUDES///////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ESTRUCTURAS//////////////////////////////////////////////////////////////
typedef struct {
                char codEvent[11]; //Ordenado para Corte de Control
                int numPuerta;
                int cantEspect;
                }T_Evento;

typedef struct {
                int numPuerta;
                float prom;
                }T_Prom;
//PROTOTIPADO DE FUNCIONES////////////////////////////////////////////////////


//MAIN/////////////////////////////////////////////////////////////////////////
int main()
{
    T_Evento auxEvent;
    T_Prom auxProm;
    int cantEspec, menorCantEspec, band=0;
    char codEventAnt[11], minCodigoEvento[11];
    //Apertura Archivos
    FILE *pf, *sf;
    pf=fopen("EVENTOS.dat", "rb");
    if(pf==NULL)
    {
        printf("\nNo se pudo abrir el archivo EVENTOS.dat");
        exit(1);
    }
    sf=fopen("PROMEDIOS.dat", "wb");
    if(sf==NULL)
    {
        printf("\nNo se pudo abrir el archivo PROMEDIOS.dat");
        exit(1);
    }
    //Proceso
    fread(&auxEvent, sizeof(T_Evento), 1, pf);
    while(!feof(pf)) //WHILE mayor
    {
        cantEspec=0;
        strcpy(codEventAnt, auxEvent.codEvent);
        while(!feof(pf) && codEventAnt == auxEvent.codEvent) //Corte de control por codigo de evento
        {
            cantEspec+=auxEvent.cantEspect;
            fread(&auxEvent, sizeof(T_Evento), 1, pf);
        }
        if(band==0||cantEspec<menorCantEspec)
        {
            band=1;
            cantEspec=menorCantEspec;
            strcpy(minCodigoEvento, codEventAnt);
        }
        printf("\nLa cantidad de espectadores del evento %s es: %d", codEventAnt, cantEspec);
    }
    printf("\nEl evento con menor cantidad de espectadores es %s con %d", minCodigoEvento, menorCantEspec);
    fclose(pf);

    return 0;
}
