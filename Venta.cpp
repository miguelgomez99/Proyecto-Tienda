#include <iostream>
#include <cstring>
#include "Venta.h"
#include "ArchivoDetalledeVenta.h"
#include "Detalledeventa.h"

///FECHA
      Fecha::Fecha(){
            _Dia=0;
            _Mes=0;
            _Anio=0;
         }

         void Fecha::Cargar(){
            int d, m, a;
            std::cout<<"Dia: ";
            std::cin>>d;
            setDia(d);
            std::cout<<"Mes: ";
            std::cin>>m;
            setMes(m);
            std::cout<<"Anio: ";
            std::cin>>a;
            setAnio(a);
         }

         void Fecha::Mostrar()const {
    std::cout << _Dia << "/" << _Mes << "/" << _Anio << std::endl;
}
         void Fecha::setDia(int dia){
             if(dia>=1 &&dia<=31){
                _Dia=dia;
             }
             else {
                _Dia=0;
             }
                ;
             }
        void Fecha::setMes(int mes){
                if(mes>=1 &&mes<=12){
                _Mes=mes;
             }
             else {}
                _Mes=mes;
                ;
            _Mes=mes;}
        void Fecha::setAnio(int anio){
                if(anio>=1 &&anio<=31){
                _Dia=anio;
             }
             else {}
                _Anio=0;
                ;
            _Anio=anio;}
        ///getter
        int Fecha::getDia() const{return _Dia;}
        int Fecha::getMes() const{return _Mes;}
        int Fecha::getAnio() const{return _Anio;}


/// VENTA
Venta::Venta(){

    _IdVenta=0;
    strcpy(_Email, "vacio");
    strcpy(_Formadepago, "No elegido");
    strcpy(_NombreCLiente, "vacio");
    _FechaVenta = Fecha();


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

    void Venta::setFechaVenta(const Fecha &fecha) {
    _FechaVenta = fecha;
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

    Fecha Venta::getFechaVenta() const {
    return _FechaVenta;
}




    // Metodos

    void Venta::CargarVenta( Detalledeventa &detalledeventa){

    int IdVenta;
    char Email[100];
    int Formadepago;
    char NombreCLiente[20];
    bool validacionIdVenta=false;



    std::cout << "--------------------------------------------------------- " << std::endl;

    std::cout << "Ingrese la fecha de la venta:" << std::endl;
    _FechaVenta.Cargar();

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
        std::cout << "****10% de descuento si se elige el modo de pago en efectivo***" << std::endl;
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
                   setIdVenta(IdVenta);
                    validacionIdVenta=true;
                }
                else {
                    std::cout << "Ingrese un numero de ID correcto..." << std::endl;
                }
        }

        system("cls");
    }



