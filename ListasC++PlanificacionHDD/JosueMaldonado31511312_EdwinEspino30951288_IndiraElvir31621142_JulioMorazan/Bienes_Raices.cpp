#include "Bienes_Raices.h"

char *Bienes_Raices::getCodigo() const
{
    return Codigo;
}

void Bienes_Raices::setCodigo(char *newCodigo)
{
    Codigo = newCodigo;
}

const string &Bienes_Raices::getDireccion() const
{
    return Direccion;
}

void Bienes_Raices::setDireccion(const string &newDireccion)
{
    Direccion = newDireccion;
}

const string &Bienes_Raices::getColor() const
{
    return Color;
}

void Bienes_Raices::setColor(const string &newColor)
{
    Color = newColor;
}

short Bienes_Raices::getNivel() const
{
    return Nivel;
}

void Bienes_Raices::setNivel(short newNivel)
{
    Nivel = newNivel;
}

short Bienes_Raices::getHabitacion() const
{
    return Habitacion;
}

void Bienes_Raices::setHabitacion(short newHabitacion)
{
    Habitacion = newHabitacion;
}

short Bienes_Raices::getBanio() const
{
    return Banio;
}

void Bienes_Raices::setBanio(short newBanio)
{
    Banio = newBanio;
}

short Bienes_Raices::getParqueo() const
{
    return Parqueo;
}

void Bienes_Raices::setParqueo(short newParqueo)
{
    Parqueo = newParqueo;
}

float Bienes_Raices::getPrecio() const
{
    return Precio;
}

void Bienes_Raices::setPrecio(float newPrecio)
{
    Precio = newPrecio;
}

Bienes_Raices::Bienes_Raices()
{
    strcpy(this->Codigo,"");
    this->Direccion = "";
    this->Color = "";
    this->Nivel = 0;
    this->Habitacion = 0;
    this->Banio = 0;
    this->Parqueo = 0;
    this->Precio = 0;
}

Bienes_Raices::Bienes_Raices(char *Codigo, std::string Direccion, std::string Color, short Nivel, short Habitacion, short Banio, short Parqueo, float Precio)
{
    this->Codigo = Codigo;
    this->Direccion = Direccion;
    this->Color = Color;
    this->Nivel = Nivel;
    this->Habitacion = Habitacion;
    this->Banio = Banio;
    this->Parqueo = Parqueo;
    this->Precio = Precio;
}

Bienes_Raices::~Bienes_Raices()
{
    this->Codigo = NULL;
    delete this->Codigo;
}
