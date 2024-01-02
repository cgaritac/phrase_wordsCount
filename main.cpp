//Universidad: UNED
//Curso:       Introducci�n a la programaci�n
//Tema:        Tarea 2, manejo de arreglos con punteros
//Estudiante:  Carlos Garita Campos
//Periodo:     III Cuatrimestre 2019

// Declaraci�n de bibliotecas necesarias para el programa
#include <iostream>
#include <locale>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;

void encabezado(); // Definici�n de la funci�n  "encabezado"
void imprimeChar(const char*); // Definici�n de la funci�n  "imprimeChar"
void contar(char *); // Definici�n de la funci�n  "contar"
void *invertir(char *); // Definici�n de la funci�n  "invertir"

int main() // Funci�n que da inicio al programa
{
    // Establece el idioma a espa�ol
    setlocale(LC_CTYPE,"Spanish");

     // Declaraci�n de variables
    char frase[] = "Pablito clav� un clavito que clavito clav� Pablito";

    // Llamada a la funci�n "encabezado"
    encabezado();

    cout << "\nLa frase original es:\n" << endl;
    imprimeChar(frase); // Llamada a la funci�n "imprimeChar"

    invertir(frase); // Llamada a la funci�n "invertir"

    contar(frase); // Llamada a la funci�n "contar"

    return 0;
}

void encabezado() // Funci�n que muestra el encabezado del programa
{
    // Se imprime informaci�n del encabezado en pantalla
    cout << "Universidad: Universidad Estatal a Distancia" << endl;
    cout << "Curso:       Introducci�n a la programaci�n" << endl;
    cout << "Tema:        Tarea 2" << endl;
    cout << "Estudiante:  Carlos Garita Campos" << endl;
    cout << "Periodo:     III Cuatrimestre" << endl;
    cout << "________________________________________________\n" << endl;
}

void imprimeChar(const char *texto) // Funci�n que imprime el texto original
{
    // Ciclo for que se encarga de recorrer el texto e imprimirlo en pantalla a trav�z del puntero
    for(;*texto != '\0';texto++)
        cout << *texto;
}

void *invertir(char *texto) // Funci�n que invierte el texto original y devuelve el valor invertido
{
    // Declaraci�n de variables y punteros
    char *fraseInvertida, *letra, temporal;

    // Asignaci�n de direcci�n de puntero a puntero
    fraseInvertida = &texto[0];

    // Ciclo for que se encarga de ubicar el puntero "letra" al final de la cadena de texto
    for (letra = &texto[0]; *letra != '\0'; letra++);

    // Condicional if que valora si el puntero "letra" se ubica al principio de la cadena
    if (letra - texto > 1)
    {
        // Ciclo for que se encarga de recorrer la cadena desde la �ltima letra hasta la primera
        for (letra--; texto < letra; texto++, letra--)
        {
            temporal = *texto;
            *texto = *letra;
            *letra = temporal;
        }
    }

    // Imprime en pantalla la frase invertida
    cout << "\n\nLa frase invertida es:\n\n" << fraseInvertida << endl; // Llamada a la funci�n "invertir" e imprime el valor
}

void contar(char *texto) // Funci�n que cuenta la cantidad de vocales y consonantes en el texto
{
    // Declaraci�n de variables
    int vocales = 0, consonantes = 0;

    strupr(texto); // Convierte el texto en may�scula

    while (*texto) // Ciclo mientras que se repite hasta que nombre sea nulo '\0'
    {
        // Condicional if que se encarga de contabilizar la cantidad de vocales en el texto
        if (*texto == 'A' || *texto == '�' ||*texto == 'E' || *texto == '�' || *texto == 'I' || *texto == '�' || *texto == 'O' || *texto == '�' || *texto == 'U' || *texto == '�')
        {
            vocales++;
        }
        else
        {
            // Condicional if que se encarga de no contabilizar los espacios en blanco en el texto
            if (*texto == ' ')
            {

            }

            // Caso del condicional que contabiliza la cantidad de consonantes
            else
            {
                consonantes++;
            }
        }

        // Reasignaci�n de la posicion del puntero en la cadena
        texto++;
    }

    // Se imprime en pantalla la cantidad de vocales y de consonantes
    cout << "\nEl n�mero de vocales es:\n" << vocales << endl;
    cout << "\nEl n�mero de consonantes es:\n" << consonantes << endl;
}



