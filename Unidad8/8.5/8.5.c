// 8.5. Una empresa de alquiler de autos tiene una flota de 30 autos de alta gama, identificados por su 
// número de patente, cargado en la memoria principal en un vector de 30 posiciones. Al comenzar el 
// procesamiento de los alquileres, se ingresa la fecha y la cotización del dólar de ese día. A continuación,
// se ingresan los siguientes datos correspondiente a cada alquiler realizado en el día:
// • Patente del auto (alfanumérico, de 6 caracteres)
// • Cantidad de días de alquiler (entero, mayor que 0)
// • Precio diario del alquiles en dólares (real, mayor que 0)
// Para finalizar la carga del día, se ingresa una patente de auto igual a “FINDIA”
// Determinar e informar:
// a. El porcentaje de autos alquilados durante el día.
// b. Realizar el informe con el formato siguiente:
//                                ALQUILER DE AUTOS DEL DÍA: DD-MM-AAAA
//                                    COTIZACION DEL DÓLAR: $ XX,XX

//            NRO. DE AUTO     DIAS DE ALQUILER     PRECIO DEL ALQUILER EN PESOS
//                XXXXX               XX                      XXXX,XX 
//                XXXXX               XX                      XXXX,XX
//TOTAL RECAUDADO X ALQUILER (EN PESOS) $ XXXXX,
//TOTAL RECAUDADO X ALQUILER (EN DÓLARES) $ XXXXX,XX
#include <stdio.h>
#include <string.h>

int main()
{
    int dia, mes, anio, diasAlq[30]={0}, cont=0, i;
    float cotDolar, precAlq[30]={0}, dato1, total;
    char patente[30][7]={{0}};
    printf("Ingrese la fecha de hoy");
    printf("\nIngrese el dia: ");
    do{
        scanf("%d", &dia);
    }while(!(dia>=1&&dia<=31));
    printf("\nIngrese el mes: ");
    do{
        scanf("%d", &mes);
    }while(!(mes>=1&&mes<=12));
    printf("\nIngrese el anio: ");
    do{
        scanf("%d", &anio);
    }while(!(anio>=1582&&dia<=2022));
    printf("\nIngrese la cotizacion del dolar de hoy: ");
    do{
        scanf("%f", &cotDolar);
    }while(!(cotDolar>0));
    printf("\nIngresar la patente del auto. PARA FINALIZAR CARGA PONER FINDIA: ");
    scanf("%s", &patente[cont]);
    while (cont<3||strcmpi(patente[cont], "findia")!=0)
    {
        printf("\nIngresar la cantidad de dias del alquiler: ");
        scanf("%d", &diasAlq[cont]);
        printf("\nIngresar el precio diario del alquiler en dolares: ");
        do{
            scanf("%f", &dato1);
        }while(!(dato1>0));
        precAlq[cont]=dato1*diasAlq[cont];
        total+=precAlq[cont];
        cont++;
        printf("\nIngresar la patente del auto. PARA FINALIZAR CARGA PONER FINDIA: ");
        scanf("%s", &patente[cont]);
    }
    printf("\n\t\t\tALQUILER DE AUTOS DEL DIA: %d/%d/%d", dia, mes, anio);
    printf("\n\t\t\t    COTIZACION DEL DOLAR: $%.2f", cotDolar);
    printf("\nNRO. DE AUTO        DIAS DE ALQUILER          PRECIO DEL ALQUILER EN PESOS");
    for(i=0; i<cont; i++)
        printf("\n\t%s\t\t\t%d\t\t\t$%.2f", patente[i], diasAlq[i], precAlq[i]);
    printf("\nTOTAL RECAUDADO X ALQUILER (EN PESOS): $%.2f", total*cotDolar);
    printf("\nTOTAL RECAUDADO X ALQUILER (EN DOLARES): $%.2f", total);
    return 0;
}