/*La empresa RED VIAL S.A. desea controlar el flujo vehicular en sus cabinas de peaje a lo largo del mes. Para ello se debe
procesar la información provista por las barreras que se encuentra almacenada en el archivo (BARRERAS.dat) que contiene la
siguiente información:

 •  Día (entero)
 •  Hora (0 a 24)
 •  Número de barrera (entero)

Dentro del archivo la información se encuentra ordenada por día y hora. Determinar:

 a.  La cantidad de vehículos por cada hora.
 b.  La cantidad de vehículos de cada día.
 c.  Ingresar por teclado los precios del peaje para horario normal y horario pico (de 7 a 11 y de 17 a 19). Con esos
 valores guardar un archivo con la recaudación de cada día.*/
 //INCLUDES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 //ESTRUCTURAS//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
                int dia; //Ordenado para Corte de Control 1ero
                int hora; //0 a 24 => Ordenado para Corte de Control 2do
                int numBarrera;
                }T_Barre;

typedef struct {
                int dia;
                float recaudacion;
                }T_Recau;
//PROTOTIPADO DE FUNCIONES//////////////////////////////////////////////////////////////////////////////////////////////////
int CargaArch(T_Barre[]);
void ProcesarYGrabarArch(T_Barre[], int);
int IngrDatoVal(int);
//MAIN//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int cant;
    T_Barre VBarre[cant];
    cant=CargaArch(VBarre);
    ProcesarYGrabarArch(VBarre, cant);
    printf("\n\n");

    return 0;
}
//FUNCIONES/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CargaArch(T_Barre V[])
{
    FILE *pf;
	T_Barre aux;
	int i=0;
	pf= fopen("BARRERAS.dat", "rb");
	if(pf==NULL)
	{
		printf("\nNo se pudo abrir el archivo");
		exit(1);
	}
	fread(&aux, sizeof(T_Barre), 1, pf);
    while(!feof (pf))
    {
        V[i]=aux; // PASAR A MEMORIA
        i++; //CONTADOR DE PRODUCTOS
        fread(&aux, sizeof(T_Barre), 1, pf);
    }
    fclose(pf);
    return i;
}
void ProcesarYGrabarArch(T_Barre V[], int ce)
{
    FILE *pf, *sf;
    T_Barre aux;
    T_Recau aux2;
    int cantDia, cantHora, diaAnt, horaAnt, i=0;
    float precioNormal, precioPico;
    //Apertura archivos
	pf=fopen("BARRERAS.dat", "rb"); //LECTURA ARCHIVO BARRERAS
	if(pf==NULL)
	{
		printf("\nNo se pudo abrir el archivo barreras");
		exit(1);
	}
	sf=fopen("RECAUDACION.dat", "wb"); //ESCRITURA ARCHIVO RECAUDACION
	if(sf==NULL)
	{
		printf("\nNo se pudo abrir el archivo recaudacion");
		exit(1);
	}
	//PROCESO
    printf("\nIngresar precio del peaje en horario normal: ");
    precioNormal=IngrDatoVal(0);
    printf("\nIngresar precio del peaje en horario pico: ");
    precioPico=IngrDatoVal(0);
    fread(&aux, sizeof(T_Barre), 1, pf);
    while(!feof(pf)) //WHILE PRINCIPAL
    {
        cantDia=0;
        diaAnt=aux.dia;
        while(diaAnt==aux.dia && !feof(pf)) //Corte de Control por dia
        {
            cantHora=0;
            horaAnt=aux.hora;
            while(diaAnt==aux.dia && horaAnt==aux.hora && !feof(pf)) //Corte de Control por hora
            {
                cantHora+=V[i].hora;
                i++;
                if(horaAnt>=7 && horaAnt<=11 && horaAnt>=17 && horaAnt<=19)
                {
                    aux2.recaudacion+=precioPico;
                    aux2.dia=diaAnt;
                }
                else
                {
                    aux2.recaudacion+=precioNormal;
                    aux2.dia=diaAnt;
                }
                fwrite(&aux2, sizeof(T_Recau), 1, sf);
                fread(&aux, sizeof(T_Barre), 1, pf);
            }
            printf("\nLa cantidad de vehiculos que pasaron en la hora %d es: %d", horaAnt, cantHora);
            cantDia+=cantHora;
        }
        printf("\nLa cantidad de vehiculos que pasaron en el dia %d es: %d", diaAnt, cantDia);
    }
}
//FUNCIONES COMPLEMENTARIAS/////////////////////////////////////////////////////////////////////////////////////////////////
int IngrDatoVal(int lim)
{
    float dato;
    do{
        scanf("%f", &dato);
    }while(dato<lim);
    return dato;
}
