#include "Arbol.h"

Arbol::Arbol(){
    Raiz = NULL; 
}

void Arbol::ver(){
    inOrder(Raiz); 
}

void Arbol::inOrder(Nodo &aux){
    if(aux != NULL){
        inOrder(aux -> Izq); 
        cout << aux ->data << " "; 
        inOrder(aux -> Der); 
    }
}

void Arbol::agregar(int x){
    try{
        Raiz = agregar(Raiz, x); 
    }catch(const char *e){
        cout << e; 
    }
}

Nodo Arbol::agregar(Nodo &aux, int x){
    if(aux == NULL){
        aux = new nodo(); 
        aux -> data = x; 
        aux -> Izq = NULL; 
        aux -> Der = NULL; 
    }else if(x < aux -> data){
        Nodo iz = agregar(aux -> Izq, x); 
        aux -> Izq = iz; 
    }else if(x > aux -> data){
        Nodo der = agregar(aux -> Der, x); 
        aux -> Der = der; 
    }else{
        throw "No se pueden repetir elementos"; 
    }
    return aux; 
}