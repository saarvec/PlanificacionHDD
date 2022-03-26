#ifndef COLA_H
#define COLA_H
#include <Lista.h>

template<typename Tipo>
class Cola : public Lista<Tipo>{
public:
    void Encolar( const Tipo & );//InsertarAlFrente
    bool Desencolar( Tipo &);//EliminarDelFinal
    bool estaVacia() const;
    void imprimir() const;
};

template<typename Tipo>
void Cola<Tipo>::Encolar(const Tipo &Valor)
{
    Lista<Tipo>::insertarAlFinal(Valor);
}

template<typename Tipo>
bool Cola<Tipo>::Desencolar(Tipo &Valor)
{
    return Lista<Tipo>::eliminarDelFrente(Valor);
}

template<typename Tipo>
bool Cola<Tipo>::estaVacia() const
{
    return Lista<Tipo>::estaVacia();
}

template<typename Tipo>
void Cola<Tipo>::imprimir() const
{
    Lista<Tipo>::imprimir();
}

#endif // COLA_H
