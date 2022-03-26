#ifndef NODO_H
#define NODO_H

template< typename Tipo > class Lista;
template< typename Tipo >
class Nodo{
    friend class Lista<Tipo>;
public:
    Nodo( const Tipo & );
    Tipo obtenerDatos() const;
private:
    Tipo datos;
    Nodo<Tipo> *sigPtr;
};

// constructor
template< typename Tipo >
Nodo<Tipo>::Nodo( const Tipo &info )
    : datos( info ), sigPtr( 0 ){ }

// devuelve una copia de los datos en el nodo
template<typename Tipo>
Tipo Nodo<Tipo>::obtenerDatos() const
{
    return datos;
}
#endif
