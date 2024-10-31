#pragma once
#include "Menu.h"

class Proveedores{
private:

    char _Nombre[20];
    char _Contacto[20];
    char _Cuit[20];
    char _Producto[20];

public:

    // constructor
    Proveedores();


     void AgregarProveedores();

    // guardar datos

    bool guardarProveedores(Proveedores proveedores);

    bool listarProveedores();

    void MostrarProveedores();

    // setters
    void setNombre (const char nombre[]);
    void setContacto (const char contacto[]);

    void setCuit (const char cuit[]);

    void setProducto (const char producto[]);


    // getters
    const char* getNombre ();

    const char* getContacto ();

    const char* getCuit ();

    const char* getProducto ();



};
