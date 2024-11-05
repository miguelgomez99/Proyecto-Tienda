#include "Menu.h"
#include "archivoproducto.h"
#include <cstring>
#include <iostream>

Archivoproducto::Archivoproducto(){
  _fileName = "Producto.dat";
}

bool Archivoproducto::Guardar(const Producto &registro){
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
