/*Se dispone de un archivo llamado RATING.dat que guarda la informaci�n de los puntos obtenidos de rating en los
distintos programas de canales de cable a lo largo del dia. Cada registro contiene:
 -  Numero de canal (entero)
 -  Programa (texto de 35 caracteres m�ximo)
 -  Rating (float)
El archivo se encuentra ordenado por canal. Se solicita informar:
 a.  Aquellos canales que obtengan menos de 15 puntos en total.
 b.  El canal m�s visto.
 c.  Generar un archivo con el promedio de rating de cada canal que incluya dos campos:
 -  Numero de canal
 -  Promedio*/
 //INCLUDE///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
//ESTRUCTURAS////////////////////////////////////////////////////////////////////////////////////////////////////
 typedef struct{
                int numcanal;
                char prog[36];
                float rating;
                }T_Puntostv;

 typedef struct {
                int Numcan;
                float prom;
                }T_ArchRating;
//MAIN//////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
 {
    FILE *pf, *sf;
    T_Puntostv aux;
    T_ArchRating aux2;
    int canalAnt, puntosOb, canal, canalMasVisto, cPrograma, i=0, band=0;
    pf=fopen("RATING.dat","rb");
    if(pf==NULL)
    {
        printf("\n No se pudo abrir el archivo...");
        exit(1);
    }
    sf=fopen("PROMEDIO.dat","wb");
    if(sf==NULL)
    {
        printf("\n No se pudo abrir el archivo...");
        exit(1);
    }
    fread(&aux, sizeof(T_Puntostv), 1, pf);
    while(!feof(pf))
    {
        canalAnt=aux.numcanal;
        puntosOb=0;
        cPrograma=0;
        while(canalAnt==aux.numcanal && !feof(pf))
        {
            puntosOb+=aux.rating;
            cPrograma++;
            fread(&aux, sizeof(T_Puntostv), 1, pf);
        }

        if(puntosOb<15)
            printf("\nEl canal %d no alcanzo los 15 puntos de rating", canalAnt);
        if(band==0||puntosOb>canalMasVisto)
        {
            band=1;
            canalMasVisto=puntosOb;
            canal=canalAnt;
        }
        aux2.prom=(float)puntosOb/cPrograma;
        aux2.Numcan=canalAnt;
        fwrite(&aux2, sizeof(T_ArchRating), 1, sf);
    }
    printf("\nEl canal mas visto es %d",canal);
    printf("\n\n\n");
    fclose(pf);
    fclose(sf);
}
