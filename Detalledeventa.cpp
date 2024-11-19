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
    _totalDetalleVenta=0.0;
    strcpy(_categoriaVenta, "No elegido");

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


    void Detalledeventa::setSubtotal (float precio, int cantidad){
        _subtotal=precio*cantidad;
    }

    void Detalledeventa::setTotalDetalleVenta (float _subtotal){
        _totalDetalleVenta+=_subtotal;
    }

    void Detalledeventa::setCategoriaVenta (const char categoria[]){
         strcpy(_categoriaVenta, categoria);
    }


// Getters


    int Detalledeventa::getIdVentaDetalle() const{
        return _IdVentaDetalle;
    }


    const char* Detalledeventa::getNombreProducto () const{
        return _nombreProducto;
    }

     const char* Detalledeventa::getCategoriaVenta () const{
         return _categoriaVenta;
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

    float Detalledeventa::getTotalDetalleVenta () const {
        return _totalDetalleVenta;
    }

    void Detalledeventa::cargarDetalledeVenta (int IdVenta){

    char nombreProducto[20];
    int Categoria;
    int cantidadVenta;
    float precioUnitario;
    float subtotal;
    bool validacion=false, validacionPrecio=false;


    setIdVentaDetalle(IdVenta);

        std::cout << "Seleccione la categoria del producto a vender: " << std::endl;
        std::cout << "1- Alimento." << std::endl;
        std::cout << "2- Juguetes." << std::endl;
        std::cout << "3- Accesorios." << std::endl;
        std::cout << "4- Medicacion." << std::endl;
        std::cin>> Categoria;
        switch (Categoria){
    case 1:
            setCategoriaVenta ("Alimento");
            break;
    case 2:
            setCategoriaVenta ("Juguetes");
            break;
    case 3:
            setCategoriaVenta ("Accesorios");
            break;
    case 4:
            setCategoriaVenta ("Medicacion");
            break;
    default:
        std::cout << "Ingrese una opcion valida... " << std::endl;

        }


    std::cout << "Ingrese el nombre del producto: " << std::endl;
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

        setSubtotal (precioUnitario, cantidadVenta);


        system("cls");
    }
