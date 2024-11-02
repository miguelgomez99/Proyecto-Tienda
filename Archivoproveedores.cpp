#include "Menu.h"
#include "Proveedores.h"
#include "Archivoproveedores.h"

Archivoproveedores::Archivoproveedores(const std::string& fileName) {
    _fileName = fileName; // Asigna el nombre del archivo
}

 void Archivoproveedores::AgregarProveedores(Proveedores proveedores){

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



bool Archivoproveedores::Guardar(Proveedores proveedores){
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
}
