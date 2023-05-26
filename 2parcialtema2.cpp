#include <iostream>
#include <string>

using namespace std;
void menu(bool riego)
{
    system("cls");
    cout <<endl;
    cout << "---------OPCIONES----------"<< endl;
    cout << "1.Controlar la temperatura" << endl;
    cout << "2.Controlar la iluminacion" << endl;
    cout << "3.Controlar riego (";
    if(riego)
       cout << "ENCENDIDO)"<< endl;
    else
       cout <<"APAGADO)"<< endl;
    cout << "4.Salir del programa" << endl;
    cout << "---------------------------"<< endl;

    cout <<endl;
}
int main()
{
    int respuesta = 0;
    float temperatura = 17.5;
    float temperatura_ingresada;
    int iluminacion = 0;
    int iluminacion_ingresada;
    bool riego = false;
    while (respuesta != 4)
    {
        menu(riego);
        cout<<"Opcion>> ";
        cin >> respuesta;
         system("cls");
        switch (respuesta)
        {
        case 1:
        {
            cout << "Temperatura actual: " << temperatura << "° [17.9;24.5]: ";
            cin >> temperatura_ingresada;
            if (temperatura_ingresada >= 17.9 && temperatura_ingresada <= 24.5)
            {
                temperatura = temperatura_ingresada;
                cout << "Temperatura actual: " << temperatura;
            }
            else
            {
                cout << "Ingrese temperatura [17.9;24.5]"<<endl;
            }
        }
        break;
        case 2:
        {
            cout << "Iluminacion actual: " << iluminacion << " [0;100]: "<< endl;
            cin >> iluminacion_ingresada;
            if (iluminacion_ingresada >= 0 && iluminacion_ingresada <= 100)
            {
                iluminacion = iluminacion_ingresada;
                cout << "Iluminacion actual: " << iluminacion<<endl;
            }
            else
            {
                cout << "Ingrese iluminacion [0;100]"<< endl;
            }
        }
        break;
        case 3:
        {
            if (riego)
            {
                cout << "Apagado"<<endl;
                riego = false;
            }
            else
            {
                cout << "Encendido"<<endl;
                riego = true;
            }
        }
        break;
        case 4:
        {
            cout << "Gracias por cuidar las plantas, si no quien te va a cuidar de los Zombies!!! "<<endl;
            respuesta = 4;
        }
            break;
        default:
            cout << "Invalido"<<endl;
            break;
        }
        system("PAUSE()");
      }

    return 0;
}