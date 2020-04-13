#ifndef ARBOL_H
#define ARBOL_H
#include<iostream>
#include<sstream>

using namespace std; 

struct nodo{
    int data; 
    nodo *Izq; 
    nodo *Der; 
}; 
typedef struct nodo *Nodo; 

class Arbol{
    public: 
        Arbol(); 
        void ver();  
        void agregar(int);    
    private: 
        Nodo Raiz; 
        Nodo agregar(Nodo &, int); 
        void inOrder(Nodo &); 

}; 
#endif 
