/*Se desea hacer un estudio de los alumnos de la Universidad que están cursando 4to año de la carrera de
Ingeniería (como máximo hay 5000 alumnos). Para ello, de cada alumno se ingresan los siguientes datos:
    DNI(entero, entre 1 y 99999999)
    Apellido y Nombre(string, de 30 caracteres)
    Domicilio(string, de 30 caracteres)
    Sexo(carácter, 'F', 'M' o 'X')
    Fecha de Nacimiento(enteros, dia, mes y año)
    Cantidad de Materias Aprobadas(entero, mayor o igual a cero)
    Promedio de notas de las Materias Aprobadas(real, mayor a cero)
La informacion finaliza con un DNI igual a cero
Informar:
a)Los datos de los alumnos ordenados descendente por promedio.
b)Modificar el ejercicio para informar el DNI y el Apellido y Nombre de aquellos alumnos que tienen mas de 30 años.
c)Modificar el ejercicio para informar el DNI y el Apellido y Nombre de aquellos alumnos que tienen la mayor
cantidad de materias aprobadas(puede haber más de uno).
d)Modificar el ejercicio para informar el porcentaje de alumnos, alumnas y no binarios en 4to. año de Ingeniería.*/
#include <stdio.h>
#include <string.h>
#define LIMITE 5000
//ESTRUCTURAS//////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
                int dia;
                int mes;
                int anio;}TFecha;

typedef struct {
                int DNI;
                char ApeyNom[31];
                char Domi[31];
                char sex;
                TFecha FNac;
                int MatAprob;
                float prom;}TAlumno;
//PROTOTIPO FUNCIONES///////////////////////////////////////////////////////////////////////////////////////////////
int esDatoVal(int, int, int);
int IngrDatoVal(int, int);
void LeerTexto(char[], int);
int esDatoValCh(char, char, char, char);
int esBisiesto(int);
int CantDiaDelMes(int, int);
int esFechaValida(int, int, int);
TFecha IngrFechaVal();
int CargaStr(TAlumno[]);
void Ordenar(TAlumno[], int);
void MostrarStr(TAlumno[], int);
int Maximo(TAlumno[], int);
void MostrarIgualA(TAlumno[], int, int);
void MostrarMayorA(TAlumno[], int, int);
void ContarYMostrarIgualesA(TAlumno[], char, char, char, int);
//MAIN///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    TAlumno VAlum[LIMITE];
    TFecha VFecha[LIMITE];
    int cant, max;
    printf("Ingresar datos de alumnos - DNI igual a cero para terminar: ");
    cant=CargaStr(VAlum);
    if(cant>0)
    {
        Ordenar(VAlum, cant);
        printf("\nDNI\tApell-Nombr\tDomi\tSexo\tDia\tMes\tAnio\tMat Aprob\tProm");
        MostrarStr(VAlum, cant);
        //Punto B)
        MostrarMayorA(VAlum, cant, 1992);
        //Punto C)
        max=Maximo(VAlum, cant);
        MostrarIgualA(VAlum, cant, max);
        //Punto D)
        ContarYMostrarIgualesA(VAlum, 'F', 'M', 'X', cant);
    }
    else
        printf("\nNo se ingresaron alumnos");
    printf("\n\n");
    return 0;
}
//FUNCIONES///////////////////////////////////////////////////////////////////////////////////////////////////////////
int CargaStr(TAlumno V[])
{
    TAlumno aux;
    int i=0;
    printf("\nIngrese DNI del alumno: ");
    aux.DNI=IngrDatoVal(0, 99999999);
    while(aux.DNI!=0&&i<LIMITE)
    {
        printf("\nIngrese el Apellido y Nombre: ");
        fflush(stdin);
        LeerTexto(aux.ApeyNom, 31);
        printf("\nIngrese el Domicilio: ");
        fflush(stdin);
        LeerTexto(aux.Domi, 31);
        do{
            printf("\nIngrese sexo: ");
            fflush(stdin);
            scanf("%c", &aux.sex);
            aux.sex=toupper(aux.sex);
        }while(!esDatoValCh(aux.sex, 'F', 'M', 'X'));
        printf("\nIngrese la Fecha de Nacimiento(dia, mes, anio): ");
        aux.FNac=IngrFechaVal();
        do{
            printf("\nIngrese Cantidad de Materias Aprobadas: ");
            scanf("%d", &aux.MatAprob);
        }while(aux.MatAprob<0);
        do{
            printf("\nIngrese Promedio de Materias Aprobadas: ");
            scanf("%f", &aux.prom);
        }while(aux.prom<0);
        V[i]=aux;
        i++;
        printf("\nIngrese DNI del alumno: ");
        aux.DNI=IngrDatoVal(0, 99999999);
    }
    return i;
}
void LeerTexto(char texto[], int largo)
{
    int i;
    fgets(texto, largo, stdin);
    i=0;
    while(texto[i]!='\0')
    {
        if(texto[i]=='\n')
            texto[i]='\0';
        else
            i++;
    }

}
void Ordenar(TAlumno V[], int ce)
{
    TAlumno aux;
    int IndMayor, i, j;
    for(i=0;i<ce-1;i++)
    {
        IndMayor=i;
        for(j=1+i;j<ce;j++)
            if(V[i].prom>V[IndMayor].prom)
                IndMayor=j;
        if(i!=IndMayor)
        {
            aux=V[i];
            V[i]=V[IndMayor];
            V[IndMayor]=aux;
        }
    }
}
void MostrarStr(TAlumno V[], int ce)
{
    int i;
     for(i=0;i<ce;i++)
        printf("\n%d\t%s\t%s\t%c\t%d\t%d\t%d\t%d\t%.2f", V[i].DNI, V[i].ApeyNom, V[i].Domi, V[i].sex, V[i].FNac, V[i].MatAprob, V[i].prom);
}
//VALIDACIÓN DE DATOS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int IngrDatoVal(int lim1, int lim2)
{
    int dato;
    do{
        scanf("%d", &dato);
    }while(esDatoVal(dato, lim1, lim2)==0);
    return dato;
}
int esDatoVal(int x, int lim1, int lim2)
{
    if(x>=lim1&&x<=lim2)
        return 1;
    else
        return 0;
}
int esDatoValCh(char x, char car1, char car2, char car3)
{
    if(x==car1||x==car2||x==car3)
        return 1;
    else
        return 0;
}
//VALIDACION FECHA//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TFecha IngrFechaVal()
{
    TFecha fecha;
    do{
        printf("\nIngrese Dia: ");
        scanf("%d", &fecha.dia);
        printf("Ingrese Mes: ");
        scanf("%d", &fecha.mes);
        printf("Ingrese Anio: ");
        scanf("%d", &fecha.anio);
    }while(esFechaValida(fecha.dia, fecha.mes, fecha.anio)==0);
    return fecha;
}
int esFechaValida(int d, int m, int a)
{
    int r=0;
    if(a>=1582)
    {
        if(m>=1&&m<=12)
        {
            if(d>=1&&d<=CantDiaDelMes(m, a))
                r=1;
        }
    }
    return r;
}
int CantDiaDelMes(int m, int a)
{
    int cmd;
    if(m==4||m==6||m==9||m==11)
        cmd=30;
    else
    {
        if(m==2)
            cmd=28+esBisiesto(a);
        else
            cmd=31;
    }
    return cmd;
}
int esBisiesto(int a)
{
    if(a%4==0&&a%100!=0||a%400==0)
        return 1;
    else
        return 0;
}
//b)Modificar el ejercicio para informar el DNI y el Apellido y Nombre de aquellos alumnos que tienen más de 30 años./////////////////////////////////////////////////
void MostrarMayorA(TAlumno A[], int ce, int x)
{
    int i;
    printf("\n\nAlumnos con mas de 30 anios:");
    for(i=0; i<ce; i++)
    {
        if(A[i].FNac.anio<=x)
            printf("\n%d\t%s", A[i].DNI, A[i].ApeyNom );
    }
}
//C)Modificar el ejercicio para informar el DNI y el Apellido y Nombre de aquellos alumnos que tienen la mayor cantidad de materias aprobadas(puede haber más de uno).
int Maximo(TAlumno V[], int ce)
{
    int i, m;
    for(i=0; i<ce; i++)
    {
        if(i==0||V[i].MatAprob>m)
            m=V[i].MatAprob;
    }
    return m;
}
void MostrarIgualA(TAlumno V[], int ce, int x)
{
    int i;
    printf("\n\nAlumnos con Mayor Cantidad de Materias Aprobadas:");
    for(i=0; i<ce; i++)
    {
        if(V[i].MatAprob==x)
            printf("\n%d\t%s", V[i].DNI, V[i].ApeyNom);
    }
}
//D)Modificar el ejercicio para informar el porcentaje de alumnos, alumnas y no binarios en 4to. año de Ingeniería.
void ContarYMostrarIgualesA(TAlumno V[], char car1, char car2, char car3, int ce)
{
    int i, contM=0, contF=0, contX=0;
    for(i=0; i<ce; i++)
    {
        if(V[i].sex==car1)
            contF++;
        else
        {
            if(V[i].sex==car2)
                contM++;
            else
            {
                if(V[i].sex==car3)
                    contX++;
            }
        }
    }
    printf("\n\nPorcentaje de alumnos: %d", contM*100/ce);
    printf("\nPorcentaje de alumnas: %d", contF*100/ce);
    printf("\nPorcentaje de no binarios: %d", contX*100/ce);
}
