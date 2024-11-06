#pragma once
#include "Menu.h"

class Detalledeventa
{

protected:
    int ID;
    char _nombreProducto[20];
    int STOCK;
    float PRECIO;

public:

// Constructor

    Detalledeventa();

// Setters
    void setID(int ID);

    void setNombreProducto (const char nombre[]);

    void setStock(int stock);

    void setPrecio (float precio);

// Getters

    int getID() const;

    const char* getNombreProducto () const;

    int getStock() const;

    float getPrecio () const;


};
