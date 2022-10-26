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
//MAIN/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    FILE *pf;
    int i;
    T_Sdo VSaldos[5]= {
                       {451750,"Santillan Lautaro", 4500},
                       {782136,"Santillan Luciano", 1200},
                       {985426,"Santillan Marcelo", 7300},
                       {145687,"Sosa Edith", 9800},
                       {164749,"Santillan Lola", 2200}
                      };

    T_Mov VMovi[15]= {
                       {1145, 451750, 11, 25, 1, 3500},
                       {4567, 145687, 11, 26, 2, 2800},
                       {7821, 782136, 11, 26, 1, 1800},
                       {1145, 985426, 11, 27, 1, 2600},
                       {1065, 451750, 11, 28, 2, 1300}, //5
                       {8974, 164749, 11, 28, 1, 2700},
                       {4567, 451750, 11, 28, 1, 1500},
                       {1546, 145687, 11, 29, 2, 1500},
                       {7821, 985426, 11, 29, 2, 2900},
                       {1065, 145687, 11, 29, 2, 0500}, //10
                       {1065, 145687, 11, 29, 2, 0500},
                       {1065, 145687, 11, 30, 2, 0500},
                       {1065, 782136, 11, 30, 2, 5500},
                       {1065, 164749, 11, 30, 1, 3300},
                       {1065, 145687, 11, 30, 2, 0500} //15
                     };

    pf=fopen("SALDOS", "wb");
    if(pf==NULL)
    {
        printf("\n***ERROR al abrir el archivo***");
        exit(1);
    }
    for(i=0; i<5; i++)
        fwrite(&VSaldos[i], sizeof(T_Sdo), 1, pf);
    fclose(pf);

    pf=fopen("MOVI", "wb");
    if(pf==NULL)
    {
        printf("\n***ERROR al abrir el archivo***");
        exit(1);
    }
    for(i=0; i<15; i++)
        fwrite(&VMovi[i], sizeof(T_Mov), 1, pf);
    fclose(pf);
}
