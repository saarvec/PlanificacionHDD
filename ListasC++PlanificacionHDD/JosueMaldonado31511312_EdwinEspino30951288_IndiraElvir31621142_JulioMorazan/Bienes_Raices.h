#ifndef BIENES_RAICES_H
#define BIENES_RAICES_H
#include <iostream>
#include <cstring>
using std::string;

class Bienes_Raices
{
private:
    char *Codigo = new char[6];
    string Direccion, Color;
    short Nivel, Habitacion, Banio, Parqueo;
    float Precio;
public:
    Bienes_Raices();
    Bienes_Raices(char *Codigo, string Direccion, string Color, short Nivel, short Habitacion, short Banio, short Parqueo, float Precio);
    ~Bienes_Raices();
    char *getCodigo() const;
    void setCodigo(char *newCodigo);
    const string &getDireccion() const;
    void setDireccion(const string &newDireccion);
    const string &getColor() const;
    void setColor(const string &newColor);
    short getNivel() const;
    void setNivel(short newNivel);
    short getHabitacion() const;
    void setHabitacion(short newHabitacion);
    short getBanio() const;
    void setBanio(short newBanio);
    short getParqueo() const;
    void setParqueo(short newParqueo);
    float getPrecio() const;
    void setPrecio(float newPrecio);
};

#endif // BIENES_RAICES_H
