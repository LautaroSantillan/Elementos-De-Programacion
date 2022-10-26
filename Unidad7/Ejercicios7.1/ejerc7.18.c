/*7.1.18 Se procesan los datos de los casi 90 alumnos de un turno de la materia Elementos de Programación. Por
cada alumno se ingresan:
• DNI (entero, mayor que cero y menor que 99.999.999).
• Nota del Parcial 1 (entero, de 0 a 10).
• Nota del Parcial 2 (entero, de 0 a 10).
• Porcentaje de asistencia (real, mayor o igual a cero).
Para finalizar, se ingresa un DNI igual a cero.
Se pide informar con las leyendas aclaratorias y/o títulos:
a. Según los parciales si promocionó, aprobó, reprobó o estuvo ausente (uno o ambos parciales igual
a cero).
b. Listar los alumnos que no cumplen con la asistencia (mayor o igual a 75%).
c. Informar cuántos alumnos que promocionaron NO cumplen en la asistencia.
d. Informar los alumnos que sacaron 10 en el parcial 2.
e. Informar los alumnos con menor asistencia (puede haber varios).
f. Al finalizar, informar el promedio total de notas de cada parcial y de asistencia.*/
#include <stdio.h>
void IngresoDNI(int[], int, int, int);
int esDatoVal1(int, int, int);
int EstaDentroDelRango(int, int, int);
int IngrDatoVal(int);
int esDatoVal(int, int);
int main()
{
    int Valumno[5]={0}, Vparcial1[5]={0}, Vparcial2[5]={0}, Vasist[5]={0}, Vpromoc[5]={0}, DNI, parcial1, parcial2,
    DNIexiste=0, acumparc1=0, acumparc2=0, acumasist=0;
    float asistencia;
    IngresoDNI(Valumno, 1, 99999999, 5);
    do{
        printf("\nIngrese el DNI de algun alumno: ");
        scanf("%d", &DNI);
    }while(EstaDentroDelRango(DNI, 1, 99999999)==0 && DNI != 0);
    while(DNI!=0)
    {
        pos=BusquedaSec1(Valumno, 5, DNI);
        if(pos!=1)
        {

        }
        Valumno[DNIexiste]=DNI;
        printf("\nIngrese la primera nota del parcial: ");
        do{
            scanf("%d", &parcial1);
        }while(EstaDentroDelRango(parcial1, 0, 10)==0);
        Vparcial1[DNIexiste]=parcial1;
        acumparc1+=parcial1;
        printf("\nIngrese la segunda nota del parcial: ");
        do{
            scanf("%d", &parcial2);
        }while(EstaDentroDelRango(parcial1, 0, 10)==0);
        Vparcial2[DNIexiste]=parcial2;
        acumparc2+=parcial2;
        printf("\nIngrese el porcentaje de asistencias: ");
        do{
            scanf("%f", &asistencia);
        }while(IngrDatoVal(75));
        Vasist[DNIexiste]=asistencia;
        acumasist+=asistencia;
        DNIexiste++;
    }
    if(DNIexiste>=1)
    {
        printf("\El promedio de notas del primer parcial es de: ", (float)acumparc1/DNIexiste);
        printf("\El promedio de notas del segundo parcial es de: ", (float)acumparc2/DNIexiste);
        printf("\El promedio de asistencias es de: ", (float)acumasist/DNIexiste);
    }
    else
        printf("\nNo se ingresaron alumnos");
}
void IngresoDNI (int V[], int lim1, int lim2, int ce){
    int i, dato;
    printf("Ingrese los DNI de los alumnos (de 1 a 99999999): ");
    for (i=0; i<ce; i++)
    {
        do{
            scanf("%d", &dato);
        } while (esDatoVal1(dato, lim1, lim2)==0);
        V[i]=dato;
    }
}
int esDatoVal1 (int x, int lim1, int lim2){
    if(x>=lim1&&x<=lim2)
        return 1;
    else
        return 0;
}
int EstaDentroDelRango(int num, int x, int y){
    if(num>=x&&num<=y)
        return 1;
    else
        return 0;
}
int IngrDatoVal (int lim){
    int dato;
    do{
        scanf("%d", &dato);
    }while (esDatoVal(dato, lim)==0);
    return dato;
}
int esDatoVal(int x, int lim){
    if(x>lim)
        return 1;
    else
        return 0;
}
