#pragma once
#include "Menu.h"
#include "Detalledeventa.h"

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
