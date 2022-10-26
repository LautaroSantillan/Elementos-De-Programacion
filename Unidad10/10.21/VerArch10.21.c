#include<stdio.h>
#include<stdlib.h>
//STRUCTS///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct{
                int cah;
                char ApyNom[31];
                float sdo;
                }T_Sdo;

typedef struct{
                int suc;
                int nca;
                int mes;
                int dia;
                int cop;
                float imp;
                }T_Mov;
//PROTOTIPADO DE FUNCIONES/////////////////////////////////////////////////////////////////////////////////////////
void MostrarArchivo1();
void MostrarArchivo2();
//MAIN/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    MostrarArchivo1();
    printf("\n\n\n");
    MostrarArchivo2();
    printf("\n\n\n");
    return 0;
}
//DECLARACIÓN FUNCIONES//////////////////////////////////////////////////////////////////////////////////////////////
void MostrarArchivo1()
{
    T_Sdo aux;
    FILE *pf;
    pf=fopen("SALDOS", "rb");
    if(pf==NULL)
    {
        printf("\n***ERROR al abrir el archivo***");
        exit(1);
    }
    printf("\nCUENTA\tAPELLIDO Y NOMBRE\tSALDO");
    fread(&aux, sizeof(T_Sdo), 1, pf);
    while(!feof(pf))
    {
        printf("\n%d\t%s\t%.2f", aux.cah, aux.ApyNom, aux.sdo);
        fread(&aux, sizeof(T_Sdo), 1, pf);
    }
    fclose(pf);
}
void MostrarArchivo2()
{
    T_Mov aux;
    FILE *pf;
    pf=fopen("MOVI", "rb");
    if(pf==NULL)
    {
        printf("\n***ERROR al abrir el archivo***");
        exit(1);
    }
    printf("\nSUCURSAL\tNUM CAJA AHORRO\tMES\tDIA\tCOD OPERACION\tIMPORTE");
    fread(&aux, sizeof(T_Mov), 1, pf);
    while(!feof(pf))
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%.2f", aux.suc, aux.nca, aux.mes, aux.dia, aux.cop, aux.imp);
        fread(&aux, sizeof(T_Mov), 1, pf);
    }
    fclose(pf);
}
