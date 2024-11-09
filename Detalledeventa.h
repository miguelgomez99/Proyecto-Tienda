#pragma once
#include "Menu.h"


class Detalledeventa
{

protected:
    int _IdVenta=0;
    char _nombreProducto[20];
    int _cantidadVenta=0;
    float _precioUnitario=0.0;
    float _subtotal=0.0;

public:

// Constructor

    Detalledeventa();

// Setters

    void setIdVenta(int ID);

    void setNombreProducto (const char nombre[]);

    void setCantidad(int cantidad);

    void setPrecioUnitario(int precio);

    void setSubtotal (float subtotal);

// Getters

    int getIdDetalle() const;

    int getIdVenta() const;

    const char* getNombreProducto () const;

    int getCantidad() const;

    float getPrecioUnitario() const;

    float getSubtotal () const;


};
