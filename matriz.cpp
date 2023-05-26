#include <iostream>
#include <string>

using namespace std;
const int tam_matriz= 26;
typedef int tMatrizCuadrada[tam_matriz][tam_matriz];


void invertir_palabra(string palabra){
  const int tope = 10;
    typedef char tPalabra[tope];
    tPalabra charArray;
    
    int fin = tope -1;
    
    for(int i= fin ; i>=0; i--){
       if((fin - i)  < palabra.length()){
          charArray[i]=palabra[fin - i];
       }else{
          charArray[i]='*';  
       }
    }

//test
   for(int i = 0; i<tope; i++){
     cout << charArray[i] << " ";
   }

}

void recorrido_matriz_a(tMatrizCuadrada matriz){
  for(int i =tam_matriz-1 ;i>=0  ; i--){
    for(int j=0; j<tam_matriz ; j++){
        //si para que los numero queden parejos
        if(matriz[j][i] < 10){
          cout << "0";
        }
        cout << matriz[j][i] << " ";
    }
    cout << endl;
   }
}

void recorrido_matriz_b(tMatrizCuadrada matriz){
  for(int i = 0 ;i<tam_matriz  ; i++){
    for(int j = 0; j<tam_matriz ; j++){
        if(i % 2 != 0){
            cout << matriz[i][tam_matriz-1-j] << " ";
        }else{
            cout << matriz[i][j] << " ";
        }
    }
    cout << endl;
   }
}
void recorrido_matriz_c(tMatrizCuadrada matriz)
{
   // la matriz debe ser par y mayor que 0
   int mitad_fila = (tam_matriz / 2) - 1;
   // es el mismo valor que mitad_fila pero para diferenciarlo
   int mitad_columna = (tam_matriz / 2) - 1;
   int sig_fila = tam_matriz - 1;
   int sig_columna = 0;
   int cambio = mitad_fila;

   while ((sig_fila < tam_matriz) && (sig_fila >= 0) && (sig_columna < tam_matriz) && (sig_columna >= 0))
   {
    int anterior_columna = sig_columna;

    if (sig_columna <= mitad_columna)
    {
        if (sig_fila > cambio)
        {
            cout << matriz[sig_fila--][sig_columna] << " ";
        }
        else
        {
            anterior_columna = sig_columna;
            while (anterior_columna >= 0)
            {
                cout << matriz[sig_fila][anterior_columna--] << " ";
            }
            if (sig_fila == 0 && anterior_columna + 1 == 0)
            {
                cambio = tam_matriz - 1;
            }
            else
            {
                sig_fila = tam_matriz - 1;
                cambio--;
            }
            sig_columna++;
            cout << endl;
        }
    }
    else
    {

        if (sig_fila < cambio)
        {
            cout << matriz[sig_fila++][sig_columna] << " ";
        }
        else
        {
            int anterior_columna = sig_columna;
            while (anterior_columna < tam_matriz)
            {
                cout << matriz[sig_fila][anterior_columna++] << " ";
            }
            sig_columna++;
            sig_fila = 0;
            cambio--;
            cout << endl;
        }
    }
   }
}



void test_matriz(tMatrizCuadrada matriz){
       for(int i=0; i<tam_matriz;i++){
        for(int j=0; j<tam_matriz;j++){
            if(matriz[i][j] < 10){
                cout << "0";
            }
            cout << matriz[i][j] << " ";

        }
        cout << endl;
    } 
}

void desde_abajo_izquierda(tMatrizCuadrada matriz,int columna, int cambio){
    //int tam_matriz = sizeof(matriz)/sizeof(matriz[0]); 
    int sig_fila = tam_matriz - 1;
    while(sig_fila < tam_matriz && sig_fila>=0 && columna < tam_matriz && columna>=0){
        if(sig_fila >= cambio){
           cout << matriz[sig_fila--][columna] << " ";
        }else{
          
           while(columna>=0){
            cout << matriz[sig_fila][columna--] << " ";
           }
        }
    }
}
void desde_arriba_izquierda(tMatrizCuadrada matriz,int columna, int cambio){
    //int tam_matriz = sizeof(matriz)/sizeof(matriz[0]); 
    int sig_fila = 0;
    while(sig_fila < tam_matriz && sig_fila>=0 && columna < tam_matriz && columna>=0){
        if(sig_fila < cambio){
           cout << matriz[sig_fila++][columna] << " ";
        }else{
          
           while(columna>=0){
            cout << matriz[sig_fila][columna--] << " ";
           }
        }
    }
}
void desde_arriba_derecha(tMatrizCuadrada matriz,int columna, int cambio){
    
    int sig_fila = 0;
    while(sig_fila < tam_matriz && sig_fila>=0 && columna < tam_matriz && columna>=0){
        if(sig_fila < cambio){
           cout << matriz[sig_fila++][columna] << " ";
        }else{
          
           while(columna<tam_matriz){
            cout << matriz[sig_fila][columna++] << " ";
           }
        }
    }
}

void recorrido_matriz_d(tMatrizCuadrada matriz)
{
  int mitad = tam_matriz /2-1 ;
  int i=mitad;
  int j= mitad+1;
  int cambio = tam_matriz -1;
  while(i>=0 && j<tam_matriz){
    //par para la derecha
    
        
        desde_arriba_izquierda(matriz,i,cambio);
        cout << endl;
        desde_arriba_derecha(matriz,j,cambio);
        cout << endl;
        cambio--;
    //impar para la izquierada
    
   
    
    i--;
    j++;
  }
}

void recorrido_seg_parcial_recu(tMatrizCuadrada matriz, int tam_matriz_fila,int tam_matriz_columna, int col){
    if(tam_matriz_fila==1){
        cout << matriz[0][tam_matriz_columna-1];
    }else{
        for(int i= tam_matriz_columna-1;i >=col;i--){
            cout << matriz[tam_matriz_fila-1][i] << " ";
        }
        for(int i= tam_matriz_fila-2;i >=0;i--){
            cout << matriz[i][col] << " ";
        }
        cout << endl;
        recorrido_seg_parcial_recu(matriz,tam_matriz_fila-1, tam_matriz_columna ,col + 1);
    }
}
int main (){

   // string palabra;
   // cout << "Intruduzca una palabra no mayor a 10 letras: ";
   // cin >> palabra;
    //invertir_palabra(palabra);


    tMatrizCuadrada matriz;
    int cont = 0;
    for(int i=0; i<tam_matriz;i++){
        for(int j=0; j<tam_matriz;j++){
            if(cont < 10){
                 matriz[i][j]=  cont ;
                 cont++;
            }else{
                matriz[i][j]= cont ++;
            }
            
        }
    }
  cout << endl;
  cout << endl;
  cout << "------------------" << endl;
  cout << "Matriz base" << endl;
  cout << "------------------" << endl;
  test_matriz(matriz);
  
  cout << endl;
  /*
  cout << "------------------" << endl;
  cout << "Recorrido matriz a" << endl;
  cout << "------------------" << endl;
  recorrido_matriz_a(matriz);
  cout << endl;
    cout << endl;
  cout << "------------------" << endl;
  cout << "Recorrido matriz b" << endl;
  cout << "------------------" << endl;
  recorrido_matriz_b(matriz);
  cout << endl;
  

  cout << endl;
  cout << "------------------" << endl;
  cout << "Recorrido matriz c" << endl;
  cout << "------------------" << endl;
  recorrido_matriz_c(matriz);
  cout << endl;
  */
  cout << endl;
  cout << "------------------" << endl;
  cout << "Recorrido" << endl;
  cout << "------------------" << endl;
  //desde_arriba_derecha(matriz,tam_matriz/2,tam_matriz-1);
  //recorrido_matriz_d(matriz);
  //recorrido_seg_parcial_recu(matriz,tam_matriz,tam_matriz,0);
  cout << sizeof(matriz[0])/4 <<" ";
  return 0;
}
