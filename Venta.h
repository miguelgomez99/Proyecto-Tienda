#pragma once
#include "Menu.h"
#include "Detalledeventa.h"

/*class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int d, int m, int a);
         void Cargar();
         void Mostrar() const;
        ///setters
         void setDia(int dia);
        void setMes(int m);
        void setAnio(int a);
        ///getters
        int getDia() const;
        int getMes() const;
        int getAnio() const;


};

*/
class Venta
{

protected:
    int _IdVenta;
    char _Email[100];
    char _Formadepago[15];
    float _TotalVenta;
    bool _Estado;
    char _NombreCLiente[100];


public:

// Constructor

    Venta();

// Setters
    void setIdVenta(int IdVenta);

    void setEmail (const char Email[]);

    void setFormadepago (const char Formadepago[]);

    void setTotalVenta (float total);

    void setEstado (bool Estado);

    void setNombre (const char NombreCLiente[]);

// Getters

    int getIdVenta() const;

    const char* getEmail() const;

    const char* getFormadepago() const;

    float getTotalVenta () const;

    bool getEstado () const;

    const char* getNombre () const;


    // metodos

    void CargarVenta( Detalledeventa &detalledeventa);

};
