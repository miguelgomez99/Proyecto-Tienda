#include "Menu.h"
#include "Proveedores.h"
#include <cstring>
#include <iostream>
#include "Archivoproveedores.h"

// constructor
Proveedores::Proveedores()
{
    strcpy(_Nombre, "vacio");
    strcpy(_Contacto, "vacio");
    strcpy(_Cuit, "vacio");
    strcpy(_Producto, "vacio");
}

// SETTERS
void Proveedores::setNombre (const char nombre[])
{
    strcpy(_Nombre, nombre);
}

void Proveedores::setContacto (const char contacto[])
{
    strcpy(_Contacto, contacto);
}


void Proveedores::setCuit (const char cuit[])
{
    strcpy(_Cuit, cuit);
}

void Proveedores::setProducto (const char producto[])
{
    strcpy(_Producto, producto);
}

// getters
const char* Proveedores::getNombre () const
{
    return _Nombre;
}

const char* Proveedores::getContacto () const
{
    return _Contacto;
}

const char* Proveedores::getCuit () const
{
    return _Cuit;
}

const char* Proveedores::getProducto () const
{
    return _Producto;
}

void Proveedores::AgregarProveedores()
{

    char nombre[20];
    char contacto[20];
    char cuit[20];
    char producto[20];


    std::cout << "Ingrese el nombre del proveedor: " << std::endl;
    std::cin.ignore();
    std::cin.getline(nombre, 20);
    setNombre(nombre);


    std::cout << "Ingrese el contacto del proveedor: " << std::endl;
    std::cin >> contacto;
    setContacto(contacto);

    std::cout << "Ingrese el cuit del proveedor: " << std::endl;
    std::cin >> cuit;
    setCuit(cuit);

    std::cout << "Ingrese el producto del proveedor: " << std::endl;
    std::cin >> producto;
    setProducto(producto);

    system("cls");
}

