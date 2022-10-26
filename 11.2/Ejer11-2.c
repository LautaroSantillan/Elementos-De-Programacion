/*Se dispone de un archivo con las ventas del mes de cada una de las sucursales de una empresa (VENTAS.DAT) El archivo se
encuentra ordenado por sucursal y contiene la siguiente estructura:
 •  Sucursal (15 caracteres máximo)     //ORDENADO para Corte de Control
 •  Código de producto (entero) //ENLACE
 •  Cantidad (entero)
Por otro lado se dispone de un archivo de los productos (PRODUCTOS.dat) que vende la empresa y el estado del stock al mes
pasado con la siguiente estructura:
 •  Código de producto (entero) //ENLACE
 •  Descripción (20 caracteres máximo)
 •  Precio (float)
 •  Stock (entero)
 •  Punto de pedido (entero)
 •  Cantidad para pedido (entero)
No se sabe la cantidad exacta de productos pero sí se sabe que no hay más de 200. Se desea:
 a.  Mostrar el total vendido en cada sucursal.
 b.  Mostrar la recaudación total de la empresa en el mes.
 c.  Determinar la sucursal que vendió mayor cantidad de productos.
 d.  Actualizar el archivo de productos con el nuevo stock.
 e.  Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse (código y cantidad) de
aquellos productos que al finalizar de procesar las ventas del mes queden con stock menor al punto de pedido.*/
//INCLUDE///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ESTRUCTURAS/////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
				char suc[16];
				int codProd;
				int cant;
				}T_Vta;

typedef struct {
				int codProd;
				char descrip[21];
				float precio;
				int stock;
				int puntoPedido;
				int cantPedido;
				}T_Prod;

typedef struct {
				int codProd;
				int cantidadPedido;
				}T_Faltantes;
//FUNCIONES///////////////////////////////////////////////////////////////////////////////////////////////////////
int CargaArch(T_Prod[], int);
void ProcesarArch(T_Prod[], int);
void GrabarArch(T_Prod[], int);
int Busqueda(T_Prod[], int, int);
//MAIN////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	T_Prod VProd[200];
    int cant;
	cant=CargaArch(VProd, 200);
	ProcesarArch(VProd, cant);
	GrabarArch(VProd, cant);
    printf("\n\n\n");

	return 0;
}
//FUNCIONES////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CargaArch(T_Prod V[], int ce)
{
    FILE *pf;
	T_Prod aux;
	int i=0;
	pf= fopen("PRODUCTOS.dat", "rb");
	if(pf==NULL)
	{
		printf("\nNo se pudo abrir el archivo");
		exit(1);
	}
	fread(&aux, sizeof(T_Prod), 1, pf);
    while(!feof (pf) && i<ce)
    {
        V[i]=aux; // PASAR A MEMORIA
        i++; //CONTADOR DE PRODUCTOS
        fread(&aux, sizeof(T_Prod), 1, pf);
    }
    fclose(pf);
    return i;
}
void ProcesarArch(T_Prod V[], int ce)
{
	FILE *pf, *sf;
	T_Vta aux;
	T_Faltantes faltantes;
	char sucAnt[16], maxSuc[16];
	int pos, band=0, cantProd, maxCantProd=0;
	float recauT=0, totVtaSuc;
	//Apertura archivos
	pf=fopen("VENTAS.dat", "rb"); //LECTURA ARCHIVO VENTAS
	if(pf==NULL)
	{
		printf("\nNo se pudo abrir el archivo");
		exit(1);
	}
	sf=fopen("PEDIDOS.dat", "wb"); //ESCRITURA ARCHIVO PEDIDOS
	if(sf==NULL)
	{
		printf("\nNo se pudo abrir el archivo");
		exit(1);
	}
	//Proceso
	fread(&aux, sizeof(T_Vta), 1, pf);
	while(!feof(pf)) //WHILE MAYOR
	{
        totVtaSuc=0;
        cantProd=0;
        strcpy(sucAnt, aux.suc);
        while(strcmpi(sucAnt, aux.suc)==0 && !feof(pf)) //CORTE DE CONTROL
        {
            pos=Busqueda(V, ce, aux.codProd); //BUSQUEDA PRODUCTO
            if(pos!=-1)
            {
                if(V[pos].stock>V[pos].puntoPedido)
                {
                    totVtaSuc+=aux.cant*V[pos].precio;
                    cantProd+=aux.cant;
                    V[pos].stock-=aux.cant;
                }
                else
                {
                    faltantes.cantidadPedido+=aux.cant;
                    faltantes.codProd=faltantes.codProd;
                    fwrite(&faltantes, sizeof(T_Faltantes), 1, sf); //ESCRIBIR PEDIDOS.DAT
                }
            }
            fread(&aux, sizeof(T_Vta), 1, pf);
        }
		recauT+=totVtaSuc; //ACUMULADOR DE RECAUDACION TOTAL DE LA EMPRESA
		if(band==0||cantProd>maxCantProd) //SUCURSAL QUE VENDIO MAS PRODUCTOS
        {
            band=1;
            maxCantProd=cantProd;
            strcpy(maxSuc, sucAnt);
        }
        printf("\nEl importe total vendido en la sucursal %s fue de %.2f", sucAnt, totVtaSuc);
	}
	printf("\nRecaudacion total de la empresa en el mes es %.2f", recauT);
	printf("\nLa sucursal que vendio la mayor cantidad de productos fue: %s", maxSuc);
	fclose(pf);
    fclose(sf);
}
void GrabarArch(T_Prod V[], int ce)
{
    int i;
    FILE *pf;
    pf=fopen("PRODUCTOS.dat", "wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    for(i=0; i<ce; i++)
        fwrite(&V[i], sizeof(T_Prod), 1, pf);
    fclose(pf);
}
//BUSQUEDA//////////////////////////////////////////////////////////////////////////////////////////////////////
int Busqueda(T_Prod V[], int ce, int x)
{
	int i=0;
	while(V[i].codProd!=x && i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return i;
}
