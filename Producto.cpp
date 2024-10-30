#include <iostream>
#include "Producto.h"


    Producto::Producto(){
        _nombreProducto="Vacio";
        _Codigo=0;
        _Categoria="vacio";
        _Precio=0.0;
        _Cantidad=0;
        _Cuit=0;
    }

// Setters
    void Producto::setNombreProducto const (std::string nombre){
        _nombreProducto=nombre;
    }

    void Producto::setCodigo const (int codigo){
        _Codigo=codigo;
    }

    void Producto::setCategoria const (std::string categoria){
        _Categoria=categoria;
    }

    void Producto::setPrecio const (float precio){
        _Precio=precio;
    }

    void Producto::setCantidad const (int cantidad){
        _Cantidad=cantidad;
    }

    void Producto::setCuit const (int cuit){
        _Cuit=cuit;
    }



// Getters
    std::string Producto::getNombreProducto (){
        return _nombreProducto;
    }

    int Producto::getCodigo(){
        return _Codigo;
    }

    std::string Producto::getCategoria (){
        return _Categoria;
    }

    float Producto::getPrecio (){
       return _Precio;
    }

    int Producto::setCantidad (){
      return  _Cantidad;
    }

    int Producto::getCuit (){
      return  _Cuit;
    }

