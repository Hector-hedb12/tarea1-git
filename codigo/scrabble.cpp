#include <string>
#include <iostream>

using namespace std;
string palabra;
bool letraRepetida[26];
int numRepetidos;

// Recorre los caracteres de una palabra y compara los consecutivos
void procesar(){
  int l = palabra.length();
  for (int i = 0; i < l-1; i++){
    if ( palabra[i] == palabra[i+1] && !letraRepetida[ palabra[i] - 'A' ] ){
      letraRepetida[ palabra[i] - 'A' ] = true;
      numRepetidos++;
    }
  }
}

int main(){
  while ( cin >> palabra ){
    procesar();
    
    if ( numRepetidos == 26 ){
      // Se rompe el ciclo, pues ya todas las letras estan repetidas
      cout << "Todas las letras se repiten" << endl;
      break;
    }
  }
  
  // Si hay alguna letra no repetida, se busca:
  if ( numRepetidos != 26 ){
    cout << "Letras que no se repiten:" << endl;
    
    for(int i = 0; i < 26; i++){
      if ( !letraRepetida[i] ){
	cout << (char) (i + 'A') << endl;
      }
    }
    
  }
}