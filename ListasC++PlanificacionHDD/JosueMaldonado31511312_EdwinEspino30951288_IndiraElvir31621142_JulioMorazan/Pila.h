#ifndef PILA_H
#define PILA_H
#include <Lista.h>

template <typename Tipo>
class Pila : public Lista<Tipo>{
public:
    void Apilar( const Tipo & );//InsertaAlFrente
    bool Desapilar( Tipo &);//EliminarDelFrente
    bool estaVacia() const;
    void imprimir() const;
};

template<typename Tipo>
void Pila<Tipo>::Apilar(const Tipo &Valor)
{
    Lista<Tipo>::insertarAlFinal(Valor);
}

template<typename Tipo>
bool Pila<Tipo>::Desapilar(Tipo &Valor)
{
    Lista<Tipo>::eliminarDelFinal(Valor);
}

#endif // PILA_H
