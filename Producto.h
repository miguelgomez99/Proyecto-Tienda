#pragma once
#include "Menu.h"

class Producto {

protected:
    char _nombreProducto[20];
    int _Codigo;
    char _Categoria [20];
    float _Precio;
    int _Cantidad;
    int _Cuit;

public:

// Constructor

    Producto();
    void AgregarProducto();

// Setters
    void setNombreProducto (const char nombre[]);

    void setCodigo(int codigo);

    void setCategoria (const char categoria[]);

    void setPrecio (float precio);

    void setCantidad (int cantidad);

    void setCuit (int cuit);



// Getters
    const char* getNombreProducto () const;

    int getCodigo() const;

    const char* getCategoria () const;

    float getPrecio () const;

    int getCantidad () const;

    int getCuit () const;


};
