#include "Menu.h"
#include "Proveedores.h"
#include <cstring>
#include <iostream>
#include "Archivoproveedores.h"

    // constructor
    Proveedores::Proveedores(){
    strcpy(_Nombre, "vacio");
    strcpy(_Contacto, "vacio");
    strcpy(_Cuit, "vacio");
    strcpy(_Producto, "vacio");
    }


     void Proveedores::AgregarProveedores(){

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

    // GUARDADO DE DATOS
    void Proveedores::guardarProveedores(const Proveedores& proveedores){
          FILE *pFile;
          pFile=fopen("Proveedores.dat", "ab");
    if (pFile==nullptr){

            std::cout << "Error al abrir el archivo.";

    }
    int escribio=fwrite(&proveedores, sizeof(Proveedores), 1, pFile);
    fclose(pFile);

     if (escribio == 1) {
        std::cout << "Registro guardado correctamente." << std::endl;
    } else {
        std::cerr << "Error al guardar el registro." << std::endl;
    }
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
    proveedores.MostrarProveedores(proveedores);
    }
    fclose(pFile);
    return true;
    }

    // BUSCAR REGISTRO
    int Proveedores::buscarProveedores (){

        char cuit [20];
        std::cin >> cuit;

        FILE *pProv;
        Proveedores proveedores;

        int pos=0;

        pProv = fopen ("Proveedores.dat", "rb");

        if (pProv==nullptr){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return -2;
    }

    while (fread(&proveedores, sizeof(Proveedores), 1, pProv)==1){
            if (strcmp(proveedores.getCuit(),cuit)==0){
                fclose(pProv);
                return pos;

            }
            pos++;
    }

    std::cout << pos;

    fclose (pProv);
    return -1;

    }



    // MOSTRAR PROVEEDORES
void Proveedores::MostrarProveedores(const Proveedores& proveedor) {
    std::cout << "Nombre del proveedor: " << proveedor.getNombre() << std::endl;
    std::cout << "Contacto del proveedor: " << proveedor.getContacto() << std::endl;
    std::cout << "Cuit del proveedor: " << proveedor.getCuit() << std::endl;
    std::cout << "Producto del proveedor: " << proveedor.getProducto() << std::endl;
}

    // MODIFICAR PROVEEDORES

   bool Proveedores::modificarProveedores (const Proveedores &proveedores, int pos){

        FILE *pModificar;
        pModificar = fopen ("Proveedores.dat", "rb+");

        if (pModificar==nullptr){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }
    fseek (pModificar, pos*sizeof (proveedores), 0);

    bool escribio=fwrite (&proveedores, sizeof (proveedores), 1, pModificar);

    fclose (pModificar);

    return escribio;


    }


    // SETTERS
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
    const char* Proveedores::getNombre () const{
        return _Nombre;
    }

    const char* Proveedores::getContacto () const{
        return _Contacto;
    }

    const char* Proveedores::getCuit () const{
        return _Cuit;
    }

    const char* Proveedores::getProducto () const{
        return _Producto;
    }

