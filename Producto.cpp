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
       /* _dia = 1; _mes = 1; _anio = 2029;*/
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

    /*
    ///Seters fecha
    void Producto::setDia(int dia){
        if(dia>0 && dia<32) _dia = dia;
        }
    void Producto::setMes(int mes){
        if(mes>0 && mes<13) _mes=mes;
        }
    void Producto::setAnio(int anio){
        if(anio>0) _anio=anio;
        }
        */



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
/*
     ///Getters fecha
    int Producto::getDia(){
        return _dia;
        }
    int Producto::getMes(){
        return _mes;
        }
    int Producto::getAnio(){
        return _anio;
        }
*/


    ///AGREGAR PRODUCTOS

    void Producto::AgregarProducto(){

    char nombreMarca[30];
    int  Codigo;
    int Categoria;
    float Precio;
    int Cantidad;
    int Cuit;
   bool validacionCodigo=false, validacionPrecio=false, validacionCantidad=false;
/*
        std::cout << "Ingrese la fecha de ingreso del producto: " << std::endl;
        Cargar();*/

        std::cout << "Ingrese la categoria del producto: " << std::endl;
        std::cout << "1- Ingreso de alimento " << std::endl;
        std::cout << "2- Ingreso de juguetes " << std::endl;
        std::cout << "3- Ingreso de accesorios " << std::endl;
        std::cout << "4- Ingreso de medicamentos " << std::endl;
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
    default:

        std::cout << "Ingrese una opcion valida... " << std::endl;

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

/*
    // FECHA


void Producto::Cargar(){
    int dia, mes, anio;
    bool correcto = false;
    do{
    std::cout << "Ingrese el dia: ";
    std::cin >> dia;
    std::cout << "Ingrese el mes: ";
    std::cin >> mes;
    std::cout << "Ingrese el año: ";
    std::cin >> anio;

    if (dia>0 && dia<32 && mes>0 && mes<13 && anio>0){
        _dia=dia;
        _mes=mes;
        _anio=anio;
        correcto=true;
    }
    else{
        std::cout << "Fecha no valida" << std::endl;
    }

    } while (!correcto);
}

void Producto::Mostrar(){
    std::cout << "La fecha es: " <<_dia << "/" <<_mes << "/" <<_anio << std::endl;
}

*/
