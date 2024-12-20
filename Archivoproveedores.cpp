#include "Menu.h"
#include "Proveedores.h"
#include "Archivoproveedores.h"
#include <cstring>
#include <iostream>

Archivoproveedores::Archivoproveedores()
{
    _fileName = "Proveedores.dat";
}

bool Archivoproveedores::Guardar(const Proveedores &registro)
{
    FILE *pFile;
    bool result;

    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&registro, sizeof(Proveedores), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

Proveedores Archivoproveedores::leer(int pos)
{
    FILE *pFile;
    Proveedores registro;

    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return registro;
    }

    fseek(pFile, sizeof(Proveedores) * pos, SEEK_SET);

    fread(&registro, sizeof(Proveedores), 1, pFile);

    fclose(pFile);

    return registro;
}


int Archivoproveedores::getCantidad()
{
    int total;
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile==nullptr)
    {
        return 0;
    }

    fseek(pFile,0,SEEK_END);
    total=ftell(pFile);

    fclose(pFile);

    return total / sizeof(Proveedores);
}



// GUARDADO DE DATOS
void Archivoproveedores::guardarProveedores(const Proveedores& proveedores)
{
    FILE *pFile;
    pFile=fopen("Proveedores.dat", "ab");
    if (pFile==nullptr)
    {

        std::cout << "Error al abrir el archivo.";

    }
    int escribio=fwrite(&proveedores, sizeof(Proveedores), 1, pFile);
    fclose(pFile);

    if (escribio == 1)
    {
        std::cout << "Registro guardado correctamente." << std::endl;
    }
    else
    {
        std::cerr << "Error al guardar el registro." << std::endl;
    }
}

//LISTADO DE PROVEEDORES
bool Archivoproveedores::listarProveedores ()
{

    FILE *pFile = fopen("Proveedores.dat", "rb");
    if (pFile==nullptr)
    {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }

    Proveedores proveedores;
    while(fread(&proveedores, sizeof(Proveedores), 1, pFile)==1)
    {
        MostrarProveedores(proveedores);
    }
    fclose(pFile);
    return true;
}

// BUSCAR REGISTRO
int Archivoproveedores::buscarProveedores ()
{

    char cuit [20];
    std::cin >> cuit;

    FILE *pProv;
    Proveedores proveedores;

    int pos=0;

    pProv = fopen ("Proveedores.dat", "rb");

    if (pProv==nullptr)
    {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return -2;
    }

    while (fread(&proveedores, sizeof(Proveedores), 1, pProv)==1)
    {
        if (strcmp(proveedores.getCuit(),cuit)==0)
        {
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
void Archivoproveedores::MostrarProveedores(const Proveedores& proveedor)
{
    std::cout << "Nombre del proveedor: " << proveedor.getNombre() << std::endl;
    std::cout << "Contacto del proveedor: " << proveedor.getContacto() << std::endl;
    std::cout << "Cuit del proveedor: " << proveedor.getCuit() << std::endl;
    std::cout << "Producto del proveedor: " << proveedor.getProducto() << std::endl;
}

// MODIFICAR PROVEEDORES

bool Archivoproveedores::modificarProveedores (const Proveedores &proveedores, int pos)
{

    FILE *pModificar;
    pModificar = fopen ("Proveedores.dat", "rb+");

    if (pModificar==nullptr)
    {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }
    fseek (pModificar, pos*sizeof (proveedores), 0);

    bool escribio=fwrite (&proveedores, sizeof (proveedores), 1, pModificar);

    fclose (pModificar);

    return escribio;


}
