#pragma once
#include "Menu.h"

class Proveedores{
private:

    char _Nombre[20];
    char _Contacto[20];
    char _Cuit[20];
    char _Producto[20];
    int tamRegistro;

public:

    // constructor
    Proveedores();


    void AgregarProveedores();

    // guardar datos



    // setters
    void setNombre (const char nombre[]);
    void setContacto (const char contacto[]);

    void setCuit (const char cuit[]);

    void setProducto (const char producto[]);


    // getters
    const char* getNombre () const;

    const char* getContacto () const;

    const char* getCuit () const;

    const char* getProducto () const;



};

