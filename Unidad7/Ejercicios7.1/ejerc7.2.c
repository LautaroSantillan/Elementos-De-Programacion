/*7.1.2 Realizar una funci�n que reciba por par�metro dos vectores enteros de 5 elementos cada uno y genere
un vector de 10 posiciones con el contenido de ambos vectores uno a continuaci�n del otro.*/
void EJERCICIO712 (int V1[], int V2[], int V3[], int ce){
    int i;
    for (i=0; i < ce; i++)
    {
        V3[i]=V1[i];
        V3[i+ce]=V2[i];
    }
}
