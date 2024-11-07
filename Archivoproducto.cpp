#include "Menu.h"
#include "archivoproducto.h"
#include <cstring>
#include <iostream>

Archivoproducto::Archivoproducto(){
  _fileName = "Producto.dat";
}

/*bool Archivoproducto::Guardar(const Producto &registro){
  FILE *pFile;
  bool result;

  pFile = fopen(_fileName.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&registro, sizeof(Producto), 1, pFile) == 1;

  fclose(pFile);

  return result;
}

Producto Archivoproducto::leer(int pos){
  FILE *pFile;
  Producto registro;

  pFile = fopen(_fileName.c_str(), "rb");

  if(pFile == nullptr){
      return registro;
  }

  fseek(pFile, sizeof(Producto) * pos, SEEK_SET);

  fread(&registro, sizeof(Producto), 1, pFile);

  fclose(pFile);

  return registro;
}

*/


/*
  bool Archivoproducto::modificarProducto (const Producto &producto, int pos){

        FILE *pModificar;
        pModificar = fopen ("Producto.dat", "rb+");

        if (pModificar==nullptr){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }
    fseek (pModificar, pos*sizeof (Producto), 0);

    bool escribio=fwrite (&producto, sizeof (Producto), 1, pModificar);

    fclose (pModificar);

    return escribio;


    }

*/

int Archivoproducto::getCantidad(){
  int total;
  FILE *pFile;
  pFile = fopen(_fileName.c_str(), "rb");

  if(pFile==nullptr){
      return 0;
  }

  fseek(pFile,0,SEEK_END);
  total=ftell(pFile);

  fclose(pFile);

  return total / sizeof(Producto);


}


    // GUARDADO DE PRODUCTOS
    void Archivoproducto::guardarProducto(const Producto& producto){
          FILE *pGuardar;
          pGuardar=fopen(_fileName.c_str(), "ab");
    if (pGuardar==nullptr){

            std::cout << "Error al abrir el archivo.";

    }
    int escribio=fwrite(&producto, sizeof(Producto), 1, pGuardar);
    fclose(pGuardar);

     if (escribio == 1) {
        std::cout << "Registro guardado correctamente." << std::endl;
    } else {
        std::cerr << "Error al guardar el registro." << std::endl;
    }
    }

    //LISTADO DE PRODUCTOS
    Producto Archivoproducto::leer(int pos){
  FILE *pLeer;
  Producto producto;

   pLeer=fopen(_fileName.c_str(), "rb");

   if(pLeer == nullptr){
      return producto;
  }

  fseek(pLeer, sizeof(Producto) * pos, SEEK_SET);

  fread(&producto, sizeof(Producto), 1, pLeer);

  fclose(pLeer);

  return producto;
}



    // BUSCAR PRODUCTO
    int Archivoproducto::buscarProducto (){

        int cuit;
        std::cin >> cuit;

        FILE *pBuscar;
        Producto producto;


        int pos=0;

        pBuscar = fopen (_fileName.c_str(), "rb");

        if (pBuscar==nullptr){

        return -2;
    }

    while (fread(&producto, sizeof(Producto), 1, pBuscar)==1){
            if (producto.getCuit()==cuit){
                fclose(pBuscar);
                return pos;

            }
            pos++;
    }

    std::cout << pos;

    fclose (pBuscar);
    return -1;

    }




    // MOSTRAR PRODUCTO
void Archivoproducto::MostrarProducto(const Producto &producto) {
    std::cout << "-----------------------------------------------" <<std::endl;
    std::cout << "Categoria del producto: " << producto.getCategoria() <<std::endl;
    std::cout << "Nombre del producto: " << producto.getnombreMarca() <<std::endl;
    /*std::cout << "Fecha de ingreso: " << producto.Mostrar() <<std::endl;*/
    std::cout << "Codigo del producto: " << producto.getCodigo() <<std::endl;
    std::cout << "Precio del producto: " << producto.getPrecio() <<std::endl;
    std::cout << "Cantidad del producto: " << producto.getCantidad() <<std::endl;
    std::cout << "Cuit de la empresa proveedora del producto: " << producto.getCuit() <<std::endl;


}

    // MODIFICAR PRODUCTO

   bool Archivoproducto::modificarProducto (const Producto &producto, int pos){

        FILE *pModificar;
        pModificar = fopen (_fileName.c_str(), "rb+");

        if (pModificar==nullptr){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }
    fseek (pModificar, pos*sizeof (producto), 0);

    bool escribio=fwrite (&producto, sizeof (Producto), 1, pModificar);

    fclose (pModificar);

    return escribio;


    }

