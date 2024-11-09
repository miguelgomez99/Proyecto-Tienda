#include "Menu.h"
#include "Detalledeventa.h"
#include <cstring>

// Constructor

    Detalledeventa::Detalledeventa(){

    _IdVenta=0;
    strcpy(_nombreProducto, "No elegido");
    _cantidadVenta=0;
    _precioUnitario=0.0;
    _subtotal=0.0;

    }

// Setters

    void Detalledeventa::setIdVenta(int IdVenta){
        _IdVenta=IdVenta;
    }

    void Detalledeventa::setNombreProducto (const char nombre[]){
        strcpy(_nombreProducto,nombre);
    }


    void Detalledeventa::setCantidad(int cantidad){
        _cantidadVenta=cantidad;
    }


    void Detalledeventa::setPrecioUnitario(int precio){
        _precioUnitario=precio;
    }


    void Detalledeventa::setSubtotal (float subtotal){
        _subtotal=subtotal;
    }


// Getters


    int Detalledeventa::getIdVenta() const{
        return _IdVenta;
    }


    const char* Detalledeventa::getNombreProducto () const{
        return _nombreProducto;
    }


    int Detalledeventa::getCantidad() const{
        return _cantidadVenta;
    }


    float Detalledeventa::getPrecioUnitario() const{
        return _precioUnitario;
    }


    float Detalledeventa::getSubtotal () const{
        return _subtotal;
    }
