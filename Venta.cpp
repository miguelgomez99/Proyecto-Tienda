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

void Venta::setID (int ID)
{
    _ID=ID;
}

void Venta::setEmail(const char email[])
{
    strcpy(_Email, email);
}

void Venta::setFormadepago (const char pago[])
{
    strcpy(_Formadepago, pago);
}

void Venta::setPrecio (float precio)
{
    _Precio=precio;
}

// Getters

int Venta::getID()const
{
    return _ID;
}


const char* Venta::getEmail ()const
{
    return _Email;
}

const char* Venta::getFormadepago ()const
{
    return _Formadepago;
}


float Venta::getPrecio ()const
{
    return _Precio;
}


