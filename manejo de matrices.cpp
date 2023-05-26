#include <iostream>
#include <string>

using namespace std;
const int tam_matriz = 6;
typedef int tMatriz_cuadrada[tam_matriz][tam_matriz];
tMatriz_cuadrada matriz_cuadrada;

void ingresar_matriz_a()
{
    const int tam_matriz = 6;
    typedef int tMatriz_cuadrada[tam_matriz][tam_matriz];
    tMatriz_cuadrada matriz_cuadrada;
    int cont = 1;
    cout << "Ingrese 36 valores enteros para completar la  matriz, si 36: " << endl;
    for (int i = 0; i < tam_matriz; i++)
    {
        for (int j = 0; j < tam_matriz; j++)
        {
            cout << cont++ << ". ";
            cin >> matriz_cuadrada[i][j];
        }
    }
    system("cls");
    for (int i = 0; i < tam_matriz; i++)
    {
        for (int j = 0; j < tam_matriz; j++)
        {
            if (matriz_cuadrada[i][j] < 10)
                cout << "0";
            cout << matriz_cuadrada[i][j] << " ";
        }
        cout << endl;
    }
}

void matriz_base()
{
    int cont = 10;
    cout << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < tam_matriz; i++)
    {
        for (int j = 0; j < tam_matriz; j++)
        {
            matriz_cuadrada[i][j] = cont++;
            cout << matriz_cuadrada[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
    cout << endl;
}
void recorrido()
{
    matriz_base();

    /*
     *  Estrategia
     *  ----------
     *  Recorrer desde el tope_fila iniciado en la ultima fila y la ultima columna, un recorrido descendente de las columnas,
     *  hasta llegar a un tope_columna iniciado en la primer columna,
     *  luego desde la columna tope_columna, recorrer de forma descendente hasta llegar a la primer fila,
     *  repeptir el procedimiento anterior sumando en una unidad al tope_columna y restando una unidad al tope_fila
     *  hasta que que tope_fila este en la primer fila y tope_columna en la ultima columna
     */
    int tope_fila = tam_matriz - 1;
    int tope_columna = 0;
    while (tope_columna < tam_matriz && tope_fila >= 0)
    {
        for (int i = tam_matriz - 1; i >= tope_columna; i--)
        {
            cout << matriz_cuadrada[tope_fila][i] << " ";
        }
        // tope_fila -1 pq la casilla  (tope_fila;tope_columna) ya esta mostrada cuando se recorrio en el anterior for
        for (int i = tope_fila - 1; i >= 0; i--)
        {
            cout << matriz_cuadrada[i][tope_columna] << " ";
        }
        cout << endl;
        tope_columna++;
        tope_fila--;
    }
}

int main()
{
    // ingresar_matriz_a();
    recorrido();
    return 0;
}