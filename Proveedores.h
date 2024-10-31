#pragma once
#include "Menu.h"

class Proveedores{
private:

    std::string _Nombre;
    std::string _Contacto;
    std::string _Cuit;
    std::string _Producto;

public:

    // constructor
    Proveedores();


     void AgregarProveedores();

    // guardar datos

    bool guardarProveedores ();

    bool listarProveedores ();

    // setters
    void setNombre (std::string nombre);
    void setContacto (std::string contacto);

    void setCuit (std::string cuit);

    void setProducto (std::string producto);


    // getters
    std::string getNombre ();

    std::string getContacto ();

    std::string getCuit ();

    std::string getProducto ();



};
