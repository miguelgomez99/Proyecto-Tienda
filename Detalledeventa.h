#pragma once
#include "Menu.h"


class Detalledeventa
{

protected:
    int _IdVentaDetalle;
    char _nombreProducto[20];
    int _cantidadVenta;
    float _precioUnitario;
    float _subtotal;
    float _totalDetalleVenta;

public:

// Constructor

    Detalledeventa();

// Setters

    void setIdVentaDetalle(int ID);

    void setNombreProducto (const char nombre[]);

    void setCantidad(int cantidad);

    void setPrecioUnitario(int precio);

    void setSubtotal (float precio, int cantidad);

    void setTotalDetalleVenta (float _subtotal);

// Getters

    int getIdDetalle() const;

    int getIdVentaDetalle() const;

    const char* getNombreProducto () const;

    int getCantidad() const;

    float getPrecioUnitario() const;

    float getSubtotal () const;

    float getTotalDetalleVenta () const;

    // metodo

    void cargarDetalledeVenta (int IdVenta);
};
