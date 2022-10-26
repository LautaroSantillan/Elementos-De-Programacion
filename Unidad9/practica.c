#include <stdio.h>
#include <conio.h>
struct FECHA
{
int Dia;
int Mes;
int Anio;
};
struct FECHA IngresoDeFecha( );// Prototipo de la función
int esFechaCorrecta(struct FECHA );// Prototipo de la función
int main()
{
    struct FECHA fecha_main;// Declaración de una variable tipo estructura FECHA.
    int retorno;
    fecha_main = IngresoDeFecha();// llamada a la función
    retorno = esFechaCorrecta(fecha_main);
    if( retorno == 1)
        printf("La fecha es correcta");
    else
        printf("Es una fecha Incorrecta");
    return 0;
}
struct FECHA IngresoDeFecha( )
{
    struct FECHA fecha;
    printf("Ingrese Numero del Dia de una fecha:");
    scanf("%d", &fecha.Dia);
    printf("Ingrese Numero del Mes de una fecha:");
    scanf("%d", &fecha.Mes);
    printf("Ingrese Numero del Anio de una fecha:");
    scanf("%d", &fecha.Anio);
    return fecha;// Aquí se retorna la variable tipo estructura FECHA
}
int esFechaCorrecta (struct FECHA fecha)
{
    int retorno, bisiesto, cantidaddiasmes;
    retorno = 0;
    if(fecha.Anio%4==0 && fecha.Anio %100!=0|| fecha.Anio %400==0)
        bisiesto=1;
    else
        bisiesto =0;
    if(fecha.Mes==4|| fecha.Mes ==6|| fecha.Mes ==9|| fecha.Mes ==11)
        cantidaddiasmes =30;
    else
    {
        if(fecha.Mes ==2)
        cantidaddiasmes =28+ bisiesto;
        else
        cantidaddiasmes =31;
    }
    if(fecha.Anio >=1900&& fecha.Mes >=1&& fecha.Mes <=12&& fecha.Dia>=1&&
    fecha.Dia<= cantidaddiasmes )
        retorno =1;
    else
        retorno =0;
    return retorno;
}

