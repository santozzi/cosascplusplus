#include <iostream>
#include <string>

using namespace std;
const int tam_arreglo = 10;
typedef int tArreglo[tam_arreglo];
tArreglo arreglo_hungaro;
void mostrar_arreglo()
{
    for (int i = 0; i < tam_arreglo; i++)
    {
        cout << arreglo_hungaro[i] << " ";
    }
    cout << endl;
}
void dance(int a, int b)
{
    int aux = arreglo_hungaro[a];
    arreglo_hungaro[a] = arreglo_hungaro[b];
    arreglo_hungaro[b] = aux;
}
void cargar_arreglo(){
    arreglo_hungaro[0] = 3;
    arreglo_hungaro[1] = 0;
    arreglo_hungaro[2] = 1;
    arreglo_hungaro[3] = 8;
    arreglo_hungaro[4] = 7;
    arreglo_hungaro[5] = 2;
    arreglo_hungaro[6] = 5;
    arreglo_hungaro[7] = 4;
    arreglo_hungaro[8] = 6;
    arreglo_hungaro[9] = 9;
}
int main()
{
    int cant_vueltas = 0;
    cargar_arreglo();
    cout << endl;
    cout << "Entrada>> ";
    mostrar_arreglo();
    cout << endl;
    bool ordenado = false;
    while (!ordenado)
    {
        ordenado = true;
        int puntero = 0;
        int puntero_sig = 1;
        while (puntero_sig < tam_arreglo)
        {
            int a = arreglo_hungaro[puntero];
            int b = arreglo_hungaro[puntero_sig];
            if (a > b)
            {
                dance(puntero, puntero_sig);
                ordenado = false; // aca
            }
            puntero++;
            puntero_sig++;
        }
        cant_vueltas++;
        cout << cant_vueltas << ". ";
        mostrar_arreglo();
    }
    cout << endl;
    cout << "Salida>> ";
    mostrar_arreglo();
    cout << "Ordenado en " << cant_vueltas << " vueltas" << endl;
    cout << endl;
    return 0;
}