#pragma once
#include "Menu.h"

class Venta
{

protected:
    int ID;
    char Email[100];
    Char Formadepago[1];
    float PRECIO;

public:

// Constructor

    Venta();

// Setters
    void setID(int ID);

    void Email (const char Email[]);

    void Formadepago (const char Formadepago[]);

    void setPrecio (float precio);

// Getters

    int getID() const;

    const char* getEmail() const;

    const char* getFormadepago() const;

    float getPrecio () const;


};
