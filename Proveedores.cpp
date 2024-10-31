#include "Menu.h"
#include "Proveedores.h"


    // constructor
    Proveedores::Proveedores(){
    _Nombre="vacio";
    _Contacto="vacio";
    _Cuit="vacio";
    _Producto="vacio";
    }


     void Proveedores::AgregarProveedores(){

        std::string nombre, contacto, cuit, producto;

        std::cout << "Ingrese el nombre del proveedor: " << std::endl;
        std::cin >> nombre;
        _Nombre=nombre;

        std::cout << "Ingrese el contacto del proveedor: " << std::endl;
        std::cin >> contacto;
        _Contacto=contacto;

        std::cout << "Ingrese el cuit del proveedor: " << std::endl;
        std::cin >> cuit;
        _Cuit=cuit;

        std::cout << "Ingrese el producto del proveedor: " << std::endl;
        std::cin >> producto;
        _Producto=producto;

    }

    // guardar datos

    bool Proveedores::guardarProveedores (Proveedores proveedores){
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

    bool Proveedores::listarProveedores (){

    FILE *pFile = fopen("Proveedores.dat", "rb");
    if (pFile==nullptr){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }

    Proveedores proveedores;
    while(fread(&proveedores, sizeof(Proveedores), 1, pFile)==1){
        Proveedores.mostrarDatos();
    }
    fclose(pFile);
    return true;
    }





    // setters
    void Proveedores::setNombre (std::string nombre){
        _Nombre=nombre;
    }

    void Proveedores::setContacto (std::string contacto){
        _Contacto=contacto;
    }

    void Proveedores::setCuit (std::string cuit){
        _Cuit=cuit;
    }

    void Proveedores::setProducto (std::string producto){
        _Producto=producto;
    }


    // getters
    std::string Proveedores::getNombre (){
        return _Nombre;
    }

    std::string Proveedores::getContacto (){
        return _Contacto;
    }

    std::string Proveedores::getCuit (){
        return _Cuit;
    }

    std::string Proveedores::getProducto (){
        return _Producto;
    }


