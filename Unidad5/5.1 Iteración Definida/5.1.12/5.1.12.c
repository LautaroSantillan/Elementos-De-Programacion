// 5.1.12 Calcular el factorial de un número ingresado por teclado. El factorial se calcula como el producto de todos
// los enteros positivos desde 1 hasta el número. En matemática el factorial se expresa con el símbolo. Por
// ejemplo, el factorial de 5 es 120 ya que 5! = 1 x 2 x 3 x 4 x 5 =120
#include <stdio.h>
int main ()
{
    int i, nota, dni, mayor, mayordni;
    mayor=0;
    for(i=1; i<=10; i++)
    {
        printf("\nIngrese la nota promedio del alumno: ");
        scanf("%d", &nota);
        printf("\nIngrese el DNI del alumno: ");
        scanf("%d", &dni);
        if(nota>mayor)
        {
            mayor=nota;
            mayordni=dni;
        }
    }
    printf("\nEl alumno con DNI: %d, tiene una nota promedio de %d\n", mayordni, mayor);
}