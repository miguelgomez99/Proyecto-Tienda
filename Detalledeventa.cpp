#include "Menu.h"
#include "Detalledeventa.h"
#include <cstring>

// Constructor

    Detalledeventa::Detalledeventa(){

    _IdVentaDetalle=0;
    strcpy(_nombreProducto, "No elegido");
    _cantidadVenta=0;
    _precioUnitario=0.0;
    _subtotal=0.0;

    }

// Setters

    void Detalledeventa::setIdVentaDetalle(int IdVenta){
        _IdVentaDetalle=IdVenta;
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


    int Detalledeventa::getIdVentaDetalle() const{
        return _IdVentaDetalle;
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

    void Detalledeventa::cargarDetalledeVenta (){

    char nombreProducto[20];
    int cantidadVenta;
    float precioUnitario;
    float subtotal;
    bool validacion=false, validacionPrecio=false;

    std::cout << "Ingrese el nombre xd del producto: " << std::endl;
    std::cin.ignore();
    std::cin>> nombreProducto;
    setNombreProducto(nombreProducto);



        std::cout << "Ingrese la cantidad de articulos a vender: " << std::endl;
        while (validacion!=true){
                std::cin >> cantidadVenta;
                if (cantidadVenta>0){
                    setCantidad(cantidadVenta);
                    validacion=true;
                }
                else {
                    std::cout << "Ingrese una cantidad de articulos correcta..." << std::endl;
                }
        }

    std::cout << "Ingrese el precio unitario del producto: " << std::endl;
        while (validacionPrecio!=true){
                std::cin >> precioUnitario;
                if (precioUnitario>0){
                    setPrecioUnitario(precioUnitario);
                    validacionPrecio=true;
                }
                else {
                    std::cout << "Ingrese una cantidad de articulos correcta..." << std::endl;
                }
        }


        system("cls");
    }
