#include <iostream>
#include <cstring>
#include "Venta.h"
#include "ArchivoDetalledeVenta.h"
#include "Detalledeventa.h"

Venta::Venta()
{
    _IdVenta=0;
    strcpy(_Email, "vacio");
    strcpy(_Email, "No elegido");
    _TotalVenta=0;
    _Estado=false;
    strcpy(_NombreCLiente, "vacio");

}


// Setters
    void Venta::setIdVenta(int IdVenta){
        _IdVenta=IdVenta;
    }

    void Venta::setEmail (const char Email[]){
        strcpy(_Email,Email);
    }

    void Venta::setFormadepago (const char Formadepago[]){
        strcpy(_Formadepago,Formadepago);
    }

    void Venta::setTotalVenta (float total){
        _TotalVenta=total;
    }

    void Venta::setEstado (bool Estado){
        _Estado=Estado;
    }

    void Venta::setNombre (const char NombreCLiente[]){
        strcpy (_NombreCLiente, NombreCLiente);
    }

// Getters

    int Venta::getIdVenta() const{
        return _IdVenta;
    }

    const char* Venta::getEmail() const{
        return _Email;
    }

    const char* Venta::getFormadepago() const{
        return _Formadepago;
    }

    float Venta::getTotalVenta () const{
        return _TotalVenta;
    }

    bool Venta::getEstado () const{
        return _Estado;
    }

    const char* Venta::getNombre () const{
        return _NombreCLiente;
    }


    // Metodos

    void Venta::CargarVenta( Detalledeventa &detalledeventa){

    int IdVenta;
    char Email[100];
    int Formadepago;
    float TotalVenta;
    bool Estado;
    char NombreCLiente[20];
    bool validacionIdVenta=false;



    std::cout << "--------------------------------------------------------- " << std::endl;
    std::cout << "Ingrese el nombre del cliente: " << std::endl;
    std::cin>> NombreCLiente;
    setNombre(NombreCLiente);

    std::cout << "Ingrese el correo electronico del cliente: " << std::endl;
    std::cin.ignore();
    std::cin>> Email;
    setEmail(Email);

    std::cout << "Ingrese el metodo de pago del Venta: " << std::endl;
        std::cout << "1- Efectivo." << std::endl;
        std::cout << "2- Transferencia." << std::endl;
        std::cin>> Formadepago;
        switch (Formadepago){
    case 1:
            setFormadepago ("Efectivo");
            break;
    case 2:
            setFormadepago ("Transferencia");
            break;
    default:

        std::cout << "Ingrese una opcion valida... " << std::endl;

        }

        std::cout << "Ingrese el ID de venta: " << std::endl;
        while (validacionIdVenta!=true){
                std::cin >> IdVenta;
                if (IdVenta>0){
                detalledeventa.setIdVentaDetalle(IdVenta);
                   setIdVenta(IdVenta);
                    validacionIdVenta=true;
                }
                else {
                    std::cout << "Ingrese un numero de ID correcto..." << std::endl;
                }
        }


        system("cls");
    }



