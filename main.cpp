//Universidad: UNED
//Curso:       Introducción a la programación
//Tema:        Tarea 2, manejo de arreglos con punteros
//Estudiante:  Carlos Garita Campos
//Periodo:     III Cuatrimestre 2019

// Declaración de bibliotecas necesarias para el programa
#include <iostream>
#include <locale>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;

void encabezado(); // Definición de la función  "encabezado"
void imprimeChar(const char*); // Definición de la función  "imprimeChar"
void contar(char *); // Definición de la función  "contar"
void *invertir(char *); // Definición de la función  "invertir"

int main() // Función que da inicio al programa
{
    // Establece el idioma a español
    setlocale(LC_CTYPE,"Spanish");

     // Declaración de variables
    char frase[] = "Pablito clavó un clavito que clavito clavó Pablito";

    // Llamada a la función "encabezado"
    encabezado();

    cout << "\nLa frase original es:\n" << endl;
    imprimeChar(frase); // Llamada a la función "imprimeChar"

    invertir(frase); // Llamada a la función "invertir"

    contar(frase); // Llamada a la función "contar"

    return 0;
}

void encabezado() // Función que muestra el encabezado del programa
{
    // Se imprime información del encabezado en pantalla
    cout << "Universidad: Universidad Estatal a Distancia" << endl;
    cout << "Curso:       Introducción a la programación" << endl;
    cout << "Tema:        Tarea 2" << endl;
    cout << "Estudiante:  Carlos Garita Campos" << endl;
    cout << "Periodo:     III Cuatrimestre" << endl;
    cout << "________________________________________________\n" << endl;
}

void imprimeChar(const char *texto) // Función que imprime el texto original
{
    // Ciclo for que se encarga de recorrer el texto e imprimirlo en pantalla a travéz del puntero
    for(;*texto != '\0';texto++)
        cout << *texto;
}

void *invertir(char *texto) // Función que invierte el texto original y devuelve el valor invertido
{
    // Declaración de variables y punteros
    char *fraseInvertida, *letra, temporal;

    // Asignación de dirección de puntero a puntero
    fraseInvertida = &texto[0];

    // Ciclo for que se encarga de ubicar el puntero "letra" al final de la cadena de texto
    for (letra = &texto[0]; *letra != '\0'; letra++);

    // Condicional if que valora si el puntero "letra" se ubica al principio de la cadena
    if (letra - texto > 1)
    {
        // Ciclo for que se encarga de recorrer la cadena desde la última letra hasta la primera
        for (letra--; texto < letra; texto++, letra--)
        {
            temporal = *texto;
            *texto = *letra;
            *letra = temporal;
        }
    }

    // Imprime en pantalla la frase invertida
    cout << "\n\nLa frase invertida es:\n\n" << fraseInvertida << endl; // Llamada a la función "invertir" e imprime el valor
}

void contar(char *texto) // Función que cuenta la cantidad de vocales y consonantes en el texto
{
    // Declaración de variables
    int vocales = 0, consonantes = 0;

    strupr(texto); // Convierte el texto en mayúscula

    while (*texto) // Ciclo mientras que se repite hasta que nombre sea nulo '\0'
    {
        // Condicional if que se encarga de contabilizar la cantidad de vocales en el texto
        if (*texto == 'A' || *texto == 'Á' ||*texto == 'E' || *texto == 'É' || *texto == 'I' || *texto == 'Í' || *texto == 'O' || *texto == 'Ó' || *texto == 'U' || *texto == 'Ú')
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

        // Reasignación de la posicion del puntero en la cadena
        texto++;
    }

    // Se imprime en pantalla la cantidad de vocales y de consonantes
    cout << "\nEl número de vocales es:\n" << vocales << endl;
    cout << "\nEl número de consonantes es:\n" << consonantes << endl;
}



