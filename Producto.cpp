#include <iostream>
#include <cstring>
#include "Producto.h"


    Producto::Producto(){
        strcpy(_nombreMarca, "vacio");
        _Codigo=0;
        strcpy(_Categoria, "vacio");
        _Precio=0.0;
        _Cantidad=0;
        _Cuit=0;
    }

// Setters
    void Producto::setnombreMarca (const char nombre[]){
        strcpy(_nombreMarca, nombre);
    }

    void Producto::setCodigo (int codigo){
        _Codigo=codigo;
    }

    void Producto::setCategoria (const char categoria[]){
        strcpy(_Categoria, categoria);
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
    const char* Producto::getnombreMarca ()const {
        return _nombreMarca;
    }

    int Producto::getCodigo()const {
        return _Codigo;
    }

    const char* Producto::getCategoria () const {
        return _Categoria;
    }

    float Producto::getPrecio ()const {
       return _Precio;
    }

    int Producto::getCantidad () const {
      return  _Cantidad;
    }

    int Producto::getCuit () const {
      return  _Cuit;
    }

    ///AGREGAR PRODUCTOS

    void Producto::AgregarProducto(){

    char nombreMarca[30];
    int  Codigo;
    int Categoria;
    float Precio;
    int Cantidad;
    int Cuit;
     bool validacionCodigo=false, validacionPrecio=false, validacionCantidad=false;



        std::cout << "Ingrese la categoria del producto: " << std::endl;
        std::cin>> Categoria;
        switch (Categoria){
    case 1:
            setCategoria ("Alimento");
            break;
    case 2:
            setCategoria ("Juguetes");
            break;
    case 3:
            setCategoria ("Accesorios");
            break;

    case 4:
            setCategoria ("Medicamentos");
            break;
        }


        std::cout << "Ingrese la marca del producto: " << std::endl;
        std::cin.ignore();
        std::cin>> nombreMarca;
        setnombreMarca(nombreMarca);


        std::cout << "Ingrese el codigo: " << std::endl;
        while (validacionCodigo!=true){
                std::cin >> Codigo;
                if (Codigo>0){
                    setCodigo(Codigo);
                    validacionCodigo=true;
                }
                else {
                    std::cout << "Ingrese un numero de codigo correcto..." << std::endl;
                }
        }

        std::cout << "Ingrese el precio del producto: " << std::endl;
         while (validacionPrecio!=true){
                std::cin >> Precio;
                if (Precio>0){
                    setPrecio(Precio);
                    validacionPrecio=true;
                }
                else {
                    std::cout << "Ingrese un precio real..." << std::endl;
                }
                }

        std::cout << "Ingrese cantidad: " << std::endl;
        while (validacionCantidad!=true){
                std::cin >> Cantidad;
                if (Cantidad>0){
                    setCantidad(Cantidad);
                    validacionCantidad=true;
                }
                else {
                    std::cout << "Ingrese una cantidad real..." << std::endl;
                }
                }


        std::cout << "Ingrese el cuit de la empresa proveedota: " << std::endl;
        std::cin >> Cuit;
        setCuit(Cuit);

        system("cls");
    }
