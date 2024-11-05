#include <iostream>
#include <cstring>
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
    void Producto::setNombreProducto (std::string nombre){
        _nombreProducto=nombre;
    }

    void Producto::setCodigo (int codigo){
        _Codigo=codigo;
    }

    void Producto::setCategoria (std::string categoria){
        _Categoria=categoria;
    }

    void Producto::setPrecio (float precio){
        _Precio=precio;
    }

    void Producto::setCantidad (int cantidad){
        _Cantidad=cantidad;
    }

    void Producto::setCuit (int cuit){
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

    ///AGREGAR PRODUCTOS

    void Producto::AgregarProducto(){

    char nombreProducto[30];
    int  Codigo;
    char Categoria[3];
    float Precio;
    int Cantidad;
    char Cuit[30];


        std::cout << "Ingrese el nombre del producto: " << std::endl;
        std::cin.ignore();
        std::cin>> nombreProducto;
        setNombre(nombreProducto);


        std::cout << "Ingrese el codigo: " << std::endl;
        std::cin >> Codigo;
        setContacto(Codigo);

        std::cout << "Ingrese categoria: " << std::endl;
        std::cin >> Categoria;
        setCuit(Categoria);

        std::cout << "Ingrese el precio del producto: " << std::endl;
        std::cin >> Precio;
        setProducto(Precio);

        std::cout << "Ingrese cantidad: " << std::endl;
        std::cin >> Cantidad;
        setProducto(Cantidad);

        std::cout << "Ingrese el cuit de la empresa proveedota: " << std::endl;
        std::cin >> Cuit;
        setProducto(Cuit);

        system("cls");
    }
