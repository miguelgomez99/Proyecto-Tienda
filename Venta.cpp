#include <iostream>
#include <cstring>
#include "Venta.h"

Venta::Venta()
{
    _ID=0;
    strcpy(_Email, "vacio");
    strcpy(_Formadepago, "vacio");
    _Precio=0;
}

// Setters

void Detalledeventa::setID (int ID)
{
    _ID=ID;
}

void Detalledeventa::setNombreProducto (const char nombre[])
{
    strcpy(_nombreProducto, nombre);
}

void Detalledeventa::setStock (int STOCK)
{
    _Stock=STOCK;
}

void Detalledeventa::setPrecio (float precio)
{
    _Precio=precio;
}

// Getters

int Detalledeventa::getID()const
{
    return _ID;
}


const char* Detalledeventa::getNombreProducto ()const
{
    return _nombreProducto;
}

int Detalledeventa::getStock () const
{
    return  _Stock;
}


float Detalledeventa::getPrecio ()const
{
    return _Precio;
}


