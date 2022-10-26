/*ejercicio 5.2.1*/

/*#include <stdio.h>
int main ()
{
    int potencia=1;
    while(potencia<600)
    {
        printf("\nLas potencias de 2 son: %d\n", potencia);
        potencia*=2;
    }
}*/

/*ejercicio 5.2.2*/

/*#include <stdio.h>
int main()
{
    int dia, mes;
    printf("\nIngresar el valor numerico del dia 15: ");
    scanf("%d", &dia);
    printf("\nIngresar el valor numerico del mes de diciembre: ");
    scanf("%d", &mes);
    while(dia!=15)
    {
        printf("\nVolver a ingresar el valor numerico del dia 15: ");
        scanf("%d", &dia);
    }
    while(mes!=12)
    {
        printf("\nVolver a ingresar el valor numerico del mes de diciembre: ");
        scanf("%d", &mes);
    }
    printf("\nSe ha registrado el dia %d del %d\n", dia, mes);
}*/

/*ejercicios 5.2.3*/

/*#include <stdio.h>
int main()
{
    int mayus=0, minus=0, num=0, otro=0;
    char carac;
    printf("Ingrese un caracter o * para finalizar: ");
    scanf("%c", &carac);
    while(carac!='*')
    {
        if(carac>=48 && carac<=57)
            num++;
        else
        {
            if(carac>=65 && carac<=90)
                mayus++;
            else
            {
                if(carac>=97 && carac<=122)
                    minus++;
                else
                {
                    if(carac>=32 && carac<=47 || carac>=91 && carac<=96 || carac>=123 && carac<=126)
                        otro++;
                }
            }
        }
        scanf("%c", &carac);
    }
    printf("\nSe ingresaron %d numeros, %d mayusculas, %d minusculas y %d otros caracteres\n", num, mayus, minus, otro);
}*/

/*ejercicio 5.2.4*/

/*#include <stdio.h>
int main()
{
    int imp, cheque=0, efectivo=0, tarjeta=0, total;
    char cod;
    printf("Ingresar codigo C, E, T o F para finalizar: ");
    scanf("%c", &cod);
    cod=toupper(cod);
    while(cod!='F')
    {
        printf("\nIngresar un importe de venta: ");
        scanf("%d", &imp);
        if(cod=='C')
            cheque+=imp*1.2;
        else
        {
            if(cod=='E')
                efectivo+=imp*0.9;

            else
            {
                if(cod=='T')
                    tarjeta+=imp*1.12;
            }
        }
        printf("\nIngresar codigo C, E, T o F para finalizar: \n");
        scanf("%c", &cod);
        cod=toupper(cod);
    }
    printf("\nEfectivo en caja: $%d",efectivo);
    printf("\nVentas con tarjeta de credito: $%d", tarjeta);
    printf("\nVentas con cheque: $%d", cheque);
    total=cheque+efectivo+tarjeta;
    printf("\nTotal de ventas: $%d", total);
    printf("\nImporte del IVA: $%f", total*0.21);
}*/

/*ejercicio 5.2.5*/

/*#include <stdio.h>
int main()
{
    int dni, nota1, nota2, contalum=0, suma=0;
    float prom=0;
    printf("\nIngrese el numero de DNI del alumno o 0 para finalizar: ");
    scanf("%d", &dni);
    while(dni>=0)
    {
        printf("\nIngrese la primer nota del parcial: ");
        scanf("%d", &nota1);
        printf("\nIngrese la segunda nota del parcial: ");
        scanf("%d", &nota2);
        if(nota1>=7 && nota2>=7)
        {
            suma+=nota1+nota2;
            contalum++;
            printf("\nEl alumno con DNI: %d, obtuvo las notas: %d y %d [PROMOCIONA]\n", dni, nota1, nota2);
        }
        else
        {
            if(nota1>=4 && nota2>=4)
                printf("\nEl alumno con DNI: %d, obtuvo las notas: %d y %d [RINDE EXAMEN FINAL]\n", dni, nota1, nota2);
            else
                printf("\nEl alumno con DNI: %d, obtuvo las notas: %d y %d [REPROBO LA MATERIA]\n", dni, nota1, nota2);
        }
        printf("\nIngrese el numero de DNI del alumno o 0 para finalizar: ");
        scanf("%d", &dni);
    }
    prom=(float)suma/contalum;
    printf("\nLa nota promedio de los alumnos promocionados es de: %.2f\n", prom);
}*/

/*ejercicio 5.2.6*/

/*#include <stdio.h>
int main()
{
    float impo, prom, total, suma=0;
    int contvent=0;
    printf("\nIngrese el importe, mayor a 0: ");
    scanf("%f", &impo);
    while(impo>0)
    {
        if(impo<50)
        {
            total=impo*0.965;
            suma+=total;
            contvent++;
        }
        else
        {
            if(impo>=50&&impo<=150)
            {
                total=impo*0.9;
                suma+=total;
                contvent++;
            }
            else
            {
                if(impo>=151&&impo<=300)
                {
                    total=impo*0.8;
                    suma+=total;
                    contvent++;
                }
                else
                {
                    total=impo*0.75;
                    suma+=total;
                    contvent++;
                }
            }
        }
    scanf("%f", &impo);
    }
    printf("\nEl importe neto a cobrar es de: %.2f", suma);
    prom=suma/contvent;
    printf("\nEl importe promedio de todas las ventas es: %.2f", prom);
}*/

/*ejercicio 5.2.8*/

/*#include <stdio.h>
int main ()
{
    int i, j, num, divisores, contprimos=0;
    printf("Ingrese la cantidad de numeros primos que se quiere mostrar: ");
    scanf("%d", &num);
    do{
        for(i=2; i<=100; i++)
        {
            divisores=0;
            for(j=2; j<i; j++)
            {
                if(i%j==0)
                    divisores++;
            }
            if(divisores==0)
                {
                    printf("\n%d", i);
                    contprimos++;
                }
        }
    }while(contprimos<=num);
}*/

/*ejercicio 5.1.15*/

/*El gobierno de la Ciudad de Buenos Aires realiza una encuesta a los estudiantes de los colegios secundarios.
Los primeros datos a ingresar son la fecha (d�a, mes y a�o) y la cantidad de colegios de la ciudad en que se realiz� la encuesta.
De cada colegio se conoce:
    n�mero de escuela,
    la cantidad de alumnos inscriptos y
    la especialidad (�T�: t�cnico, �N�: no t�cnico).
De cada alumno del colegio que respondi� la encuesta se conoce:
    DNI,
    fecha de nacimiento (d�a, mes y a�o),
    sexo (�M� o �F�),
    opini�n con respecto a los conocimientos adquiridos (�B�: buenos, �M�: malos).
Se identifica el fin de ingreso de datos de los alumnos que respondieron la encuesta por cada colegio
con ingreso 0 en el DNI del estudiante.
Validar todos los datos que se ingresan por teclado.
Informar:

a. Por cada colegio, el porcentaje de alumnos que contestaron la encuesta sobre la cantidad de alumnos inscriptos del colegio.
b. Cantidad de estudiantes de colegio no t�cnicos que respondieron la encuesta.
c. Porcentaje de mujeres de escuelas t�cnicas sobre la cantidad de estudiantes que respondieron la encuesta.
d. Porcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos, sobre el total de encuestados.
e. Mayor edad de los estudiantes encuestados.
f. N�mero del colegio con mayor opini�n buena sobre los conocimientos adquiridos.*/
/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main ()
{
    int i,a, c=0,z, ano, ano_alumno, ano_actual, mes_actual, mes_alumno, mes_mayor, dia_actual, dia_alumno, dia_mayor;
    int cantidad_colegios, codigo_colegio, cantidad_alumnos, dni, edad, dni_alumno_mayor, colegio_alumno_mayor, cantidad_total_alumnos=0;
    int encuesta=0, encuesta_total=0, encuesta_no_tecnico=0, mujeres_tecnico=0, opinion_mala=0, opinion_buena=0, opinion_buena_aux=0, colegio_opinion_buena;
    char especialidad, sexo, opinion;

    printf("Fecha actual\n");
    printf("Ingrese el dia: ");
    do
    {
        scanf("%d",&dia_actual);
        if (dia_actual<1||dia_actual>31)
            printf("Dia incorrecto!");
    }while(dia_actual<1||dia_actual>31);

    printf("Ingrese el mes: ");
    do
    {
        scanf("%d",&mes_actual);
        if (mes_actual<1||mes_actual>12)
            printf("Mes incorrecto!");
    }while(mes_actual<1||mes_actual>12);

    printf("Ingrese el anio: ");
    do
    {
        scanf("%d",&ano);
        if (ano<1975||ano>2022)
            printf("Anio fuera de rango!");
    }while(ano<1975||ano>2022);
    ano_actual=ano;

    printf("Ingrese la cantidad de colegios: ");
    do
    {
        scanf("%d",&cantidad_colegios);
        if (cantidad_colegios<=0)
            printf("No se realizo la encuesta en ningun colegio");
    }while(cantidad_colegios<=0);

    for(i=1;i<=cantidad_colegios;i++) /*Inicio for colegios*/
    /*{
        c++;
        printf("Ingrese el numero de la %d%c escuela: ", c,248);
        scanf("%d",&codigo_colegio);

        printf("Ingrese la cantidad de alumnos de la %d%c escuela: ", c,248);
        do
        {
        scanf("%d",&cantidad_alumnos);
        if (cantidad_alumnos<0)
            printf("El colegio N%c %d no tiene alumnos!", 248, codigo_colegio);
        }while(cantidad_alumnos<0);

        cantidad_total_alumnos=cantidad_total_alumnos+cantidad_alumnos;

        printf("Ingrese la especialidad del colegio: ");
        printf("(T: Tecnico; N: No tecnico): ");
        do
        {
            fflush(stdin);
            scanf("%c",&especialidad);
            especialidad = toupper(especialidad);
            if(especialidad!='T'&&especialidad!='N')
                printf("La especialidad no es valida: ");
        }while(especialidad!='T'&&especialidad!='N');

        for(a=1;a<=cantidad_alumnos;a++) /*Inicio for alumnos*/
        /*{
            system("cls");
            printf("Alumno N�%d)\n",a);
            printf("Ingrese su DNI si quiere responder la encuesta (0 si no quiere responder): ");
            scanf("%d",&dni);
            if(dni>0)   /*Inicio de encuesta*/
            /*{
                printf("Encuesta:\n");
                printf("Fecha de nacimiento\n");
                do
                {
                    printf("Ingrese dia de nacimiento: ");
                    scanf("%d",&dia_alumno);
                    printf("Ingrese mes de nacimiento: ");
                    scanf("%d",&mes_alumno);
                    printf("Ingrese ano de nacimiento: ");
                    scanf("%d",&ano_alumno);
                    if(dia_actual<dia_alumno&&mes_actual<mes_alumno&&ano_actual<ano_alumno)
                        printf("El alumno no nacio");
                }while(dia_actual<dia_alumno&&mes_actual<mes_alumno&&ano_actual<ano_alumno);

                        if(ano_alumno<ano||(ano_alumno==ano&&(mes_alumno<mes_mayor||(mes_alumno==mes_mayor)&&dia_alumno<dia_mayor)))
                            {
                            edad=ano_actual-ano_alumno;
                            if(mes_alumno>mes_actual||(mes_alumno==mes_actual&&dia_alumno>dia_actual))
                                edad=edad-1;
                            mes_mayor=mes_alumno;
                            dia_mayor=dia_alumno;
                            ano=ano_alumno;
                            dni_alumno_mayor=dni;
                            colegio_alumno_mayor=codigo_colegio;
                            }

                printf("Ingrese el sexo (M: Masculino; F: Femenino): ");
                do
                {
                    fflush(stdin);
                    scanf("%c",&sexo);
                    sexo = toupper(sexo);
                    if(sexo!='M'&&sexo!='F')
                        printf("El sexo no es valido");
                }while(sexo!='M'&&sexo!='F');

                printf("Ingrese la opinion con respecto a los conocimientos adquiridos\n(B: Buena; M: Mala): ");
                do
                {
                    fflush(stdin);
                    scanf("%c",&opinion);
                    opinion = toupper(opinion);
                    if(opinion!='M'&&opinion!='B')
                        printf("La opinion no es valida");
                }while(opinion!='M'&&opinion!='B');

                encuesta++;
                encuesta_total++;

                if(especialidad=='N')
                    encuesta_no_tecnico++;

                if(especialidad=='T'&&sexo=='F')
                    mujeres_tecnico++;

                if(opinion=='M')
                    opinion_mala++;
                if(opinion=='B')
                    opinion_buena++;
            }/*fin encuesta

        }/*fin for alumnos*/

        /*if(opinion_buena>opinion_buena_aux)
        {
            colegio_opinion_buena=codigo_colegio;
            opinion_buena_aux=opinion_buena;
        }
        printf("A) El porcentaje de alumnos que contestaron la encuesta en el colegio %d es de: %.2f", codigo_colegio, (float)encuesta*100/cantidad_alumnos);
        encuesta=0;
        opinion_buena=0;

    }/*fin for colegios*/
    /*printf("\nB) La cantidad de alumnos de colegio no tecnico que respondieron la encuesta es de: %d", encuesta_no_tecnico);
    printf("\nC) El porcentaje de mujeres tecnicas sobre la cantidad de estudiantes que respondieron es de: %.2f",(float)mujeres_tecnico*100/encuesta_total) ;
    printf("\nD) El porcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos, sobre el total de encuestados es de: %.2f", (float)opinion_mala*100/encuesta_total);
    printf("\nE) El alumno mas grande es del colegio: %d; Tiene %d Anos con DNI: %d",colegio_alumno_mayor, edad, dni_alumno_mayor);
    printf("\nF) El colegio %d es el que mayor opinion buena tiene con %d alumnos\n", colegio_opinion_buena, opinion_buena_aux);
    system("pause");
}*/
