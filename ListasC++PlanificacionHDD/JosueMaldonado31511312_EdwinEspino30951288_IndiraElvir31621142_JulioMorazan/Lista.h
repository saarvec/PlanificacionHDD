#ifndef LISTA_H
#define LISTA_H
#include <Nodo.h>
#include<Bienes_Raices.h>
#include <iostream>
using std::cout;

template< typename Tipo > class Pila;
template< typename Tipo >
class Lista{
public:
    Lista();
    ~Lista();
    void insertarAlFrente( const Tipo & );
    void insertarEnPenultimo(const Tipo & );
    void insertarAlFinal( const Tipo & );
    bool eliminarDelFrente( Tipo & );
    bool eliminarDelPenultimo( Tipo & );
    bool eliminarDelFinal( Tipo & );
    bool estaVacia() const;
    void imprimir() const;
private:
    Nodo< Tipo > *primeroPtr;
    Nodo< Tipo > *ultimoPtr;
    Nodo< Tipo > *obtenerNuevoNodo( const Tipo & );
};

// constructor predeterminado
template< typename Tipo >
Lista< Tipo >::Lista()
    : primeroPtr( 0 ), ultimoPtr( 0 ){ }

// destructor
template< typename Tipo >
Lista< Tipo >::~Lista(){
    if ( !estaVacia() )
    {
        cout << "Destruyendo nodos ...\n";
        Nodo<Tipo> *actualPtr = primeroPtr;
        Nodo<Tipo> *tempPtr;
        while ( actualPtr != 0 ){
            tempPtr = actualPtr;
            cout << tempPtr->datos << "\t";
            actualPtr = actualPtr->sigPtr;
            delete tempPtr;
        }
    }
    cout << "Se destruyeron todos los nodos\n\n";
}


template< typename Tipo >
void Lista< Tipo >::insertarAlFrente( const Tipo &valor ){
    Nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor );
    if ( estaVacia() )
        primeroPtr = ultimoPtr = nuevoPtr;
    else{
        nuevoPtr->sigPtr = primeroPtr;
        primeroPtr = nuevoPtr;
    }
}

template< typename Tipo >
void Lista< Tipo >::insertarEnPenultimo( const Tipo &valor ){
    Nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor );
    if ( estaVacia() )
        primeroPtr = ultimoPtr = nuevoPtr;
    else{
        if(primeroPtr == ultimoPtr){
            nuevoPtr->sigPtr = primeroPtr;
            primeroPtr = nuevoPtr;
        }else if(primeroPtr->sigPtr == ultimoPtr){
            nuevoPtr->sigPtr = ultimoPtr;
            primeroPtr->sigPtr = nuevoPtr;
        }else{
            Nodo<Tipo>*PenulPtr = primeroPtr;
            while(PenulPtr->sigPtr != ultimoPtr){
                PenulPtr = PenulPtr->sigPtr;
            }
            nuevoPtr->sigPtr = ultimoPtr;
            PenulPtr->sigPtr = nuevoPtr;
        }
    }
}

template< typename Tipo >
void Lista< Tipo >::insertarAlFinal( const Tipo &valor ){
    Nodo< Tipo > *nuevoPtr = obtenerNuevoNodo( valor );
    if ( estaVacia() )
        primeroPtr = ultimoPtr = nuevoPtr;
    else{
        ultimoPtr->sigPtr = nuevoPtr;
        ultimoPtr = nuevoPtr;
    }
}

template< typename Tipo >
bool Lista< Tipo >::eliminarDelFrente( Tipo &valor ){
    if ( estaVacia() )
        return false;
    else{
        Nodo< Tipo > *tempPtr = primeroPtr;
        if ( primeroPtr == ultimoPtr )
            primeroPtr = ultimoPtr = 0;
        else
            primeroPtr = primeroPtr->sigPtr; // apunta al nodo que antes era el segundo
        valor = tempPtr->datos;
        delete tempPtr;
        return true;
    }
}


template< typename Tipo >
bool Lista< Tipo >::eliminarDelPenultimo( Tipo &valor ){
    if ( estaVacia() )
        return false;
    else{
        Nodo<Tipo> *tempPtr = primeroPtr;
        if ( primeroPtr == ultimoPtr )
            primeroPtr = ultimoPtr = 0;
        else if(primeroPtr->sigPtr == ultimoPtr){
            primeroPtr = primeroPtr->sigPtr;
        }else{
            Nodo< Tipo > *actualPtr = primeroPtr;
            while ( actualPtr->sigPtr->sigPtr != ultimoPtr ){
                actualPtr = actualPtr->sigPtr;
            }
            tempPtr = actualPtr->sigPtr;//Penultima
            actualPtr->sigPtr = ultimoPtr;
        } // fin de else
        valor = tempPtr->datos;
        delete tempPtr;
        return true;
    }
}

template< typename Tipo >
bool Lista< Tipo >::eliminarDelFinal( Tipo &valor ){
    if ( estaVacia() )
        return false;
    else{
        Nodo< Tipo > *tempPtr = ultimoPtr;
        if ( primeroPtr == ultimoPtr )
            primeroPtr = ultimoPtr = 0;
        else{
            Nodo< Tipo > *actualPtr = primeroPtr;
            // localiza el pen�ltimo elemento
            while ( actualPtr->sigPtr != ultimoPtr )
                actualPtr = actualPtr->sigPtr;
            ultimoPtr = actualPtr;
            actualPtr->sigPtr = 0;
        } // fin de else
        valor = tempPtr->datos;
        delete tempPtr;
        return true;
    }
}

// �est� la Lista vac�a?
template< typename Tipo >
bool Lista< Tipo >::estaVacia() const{
    return primeroPtr == 0;
} // fin de la funci�n estaVacia

// devuelve el apuntador al nodo reci�n asignado
template< typename Tipo >
Nodo< Tipo > *Lista< Tipo >::obtenerNuevoNodo(const Tipo &valor ){
    return new Nodo< Tipo >( valor );
} // fin de la funci�n obtenerNuevoNodo


template< typename Tipo >
void Lista< Tipo >::imprimir() const{
    if ( estaVacia() ) {
        cout << "La lista esta vacia\n\n";
        return;
    }
    Nodo< Tipo > *actualPtr = primeroPtr;
    cout << "La lista es: ";
    while ( actualPtr != 0 ) {
       /* if( typeid (actualPtr->datos)==typeid (Bienes_Raices*) ){
            cout<<actualPtr->datos->getCodigo()<<"|"
                <<actualPtr->datos->getDireccion()<<"|"
                <<actualPtr->datos->getColor()<<"|"
                <<actualPtr->datos->getNivel()<<"|"
                <<actualPtr->datos->getHabitacion()<<"|"
                <<actualPtr->datos->getBanio()<<"|"
                <<actualPtr->datos->getParqueo()<<"|"
                <<actualPtr->datos->getPrecio()<<"|\n";
        }else{*/
            cout << actualPtr->datos << "\t";
        //}
        actualPtr = actualPtr->sigPtr;
    }
    cout << "\n\n";
}
#endif
