/*7.1.2 Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere
un vector de 10 posiciones con el contenido de ambos vectores uno a continuación del otro.*/
void EJERCICIO712 (int V1[], int V2[], int V3[], int ce){
    int i;
    for (i=0; i < ce; i++)
    {
        V3[i]=V1[i];
        V3[i+ce]=V2[i];
    }
}
