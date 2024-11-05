#pragma once
#include "Menu.h"

class Producto {

protected:
    std::string _nombreProducto;
    int _Codigo;
    std::string _Categoria;
    float _Precio;
    int _Cantidad;
    int _Cuit;

public:

// Constructor

    Producto();
    void AgregarProducto();

// Setters
    void setNombreProducto (std::string nombre);

    void setCodigo(int codigo);

    void setCategoria (std::string categoria);

    void setPrecio (float precio);

    void setCantidad (int cantidad);

    void setCuit (int cuit);



// Getters
    std::string getNombreProducto ();

    int getCodigo();

    std::string getCategoria ();

    float getPrecio ();

    int getCantidad ();

    int getCuit ();


};
