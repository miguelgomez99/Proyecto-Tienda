#include "Menu.h"
#include "Proveedores.h"
#include <cstring>
#include <iostream>

    // constructor
    Proveedores::Proveedores(){
    strcpy(_Nombre, "vacio 3");
    strcpy(_Contacto, "vacio 3");
    strcpy(_Cuit, "vacio 3");
    strcpy(_Producto, "vacio 3");
    }


     void Proveedores::AgregarProveedores(){

    char nombre[20];
    char contacto[20];
    char cuit[20];
    char producto[20];

        std::cout << "Ingrese el nombre del proveedor: " << std::endl;
        std::cin >> nombre;
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

    // GUARDADO DE DATOS
    bool Proveedores::guardarProveedores(Proveedores proveedores){
          FILE *pFile;
          pFile = fopen("Proveedores.dat", "ab");
    if (pFile == nullptr) {

            std::cout << "Error al abrir el archivo.";

            return false;}
    int escribio=fwrite(&proveedores, sizeof(Proveedores), 1, pFile);
    fclose(pFile);

     if (escribio == 1) {
        std::cout << "Registro guardado correctamente." << std::endl;
    } else {
        std::cerr << "Error al guardar el registro." << std::endl;
    }

    return escribio;
    }

    //LISTADO DE PROVEEDORES
    bool Proveedores::listarProveedores (){

    FILE *pFile = fopen("Proveedores.dat", "rb");
    if (pFile==nullptr){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }

    Proveedores proveedores;
    while(fread(&proveedores, sizeof(Proveedores), 1, pFile)==1){
    proveedores.MostrarProveedores();
    }
    fclose(pFile);
    return true;
    }


    void Proveedores::MostrarProveedores (){
        std::cout << "Nombre del proveedor: " << _Nombre << std::endl;
        std::cout << "Contacto del proveedor: " << _Contacto << std::endl;
        std::cout << "Cuit del proveedor: " << _Cuit << std::endl;
        std::cout << "Producto del proveedor: " << _Producto << std::endl;

    }


    // setters
    void Proveedores::setNombre (const char nombre[]){
        strcpy(_Nombre, nombre);
    }

    void Proveedores::setContacto (const char contacto[]){
        strcpy(_Contacto, contacto);
    }

    void Proveedores::setCuit (const char cuit[]){
        strcpy(_Cuit, cuit);
    }

    void Proveedores::setProducto (const char producto[]){
        strcpy(_Producto, producto);
    }


    // getters
    const char* Proveedores::getNombre (){
        return _Nombre;
    }

    const char* Proveedores::getContacto (){
        return _Contacto;
    }

    const char* Proveedores::getCuit (){
        return _Cuit;
    }

    const char* Proveedores::getProducto (){
        return _Producto;
    }


