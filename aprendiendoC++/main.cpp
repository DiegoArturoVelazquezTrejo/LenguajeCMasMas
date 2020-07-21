#include "Arbol.h"

using namespace std; 

int main(){
    Arbol *a = new Arbol(); 
    a -> agregar(9); 
    a -> agregar(78); 
    a -> agregar(93); 
    a -> agregar(12); 
    a -> agregar(45); 

    a -> ver();  
    return 0; 
}
