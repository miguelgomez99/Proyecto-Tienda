#include "Menu.h"
#include "Proveedores.h"
#include "Archivoproveedores.h"
#include <cstring>
#include <iostream>

Archivoproveedores::Archivoproveedores(){
  _fileName = "Proveedores.dat";
}

bool Archivoproveedores::Guardar(const Proveedores &registro){
  FILE *pFile;
  bool result;

  pFile = fopen(_fileName.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&registro, sizeof(Proveedores), 1, pFile) == 1;

  fclose(pFile);

  return result;
}

Proveedores Archivoproveedores::leer(int pos){
  FILE *pFile;
  Proveedores registro;

  pFile = fopen(_fileName.c_str(), "rb");

  if(pFile == nullptr){
      return registro;
  }

  fseek(pFile, sizeof(Proveedores) * pos, SEEK_SET);

  fread(&registro, sizeof(Proveedores), 1, pFile);

  fclose(pFile);

  return registro;
}


int Archivoproveedores::getCantidad(){
  int total;
  FILE *pFile;
  pFile = fopen(_fileName.c_str(), "rb");

  if(pFile==nullptr){
      return 0;
  }

  fseek(pFile,0,SEEK_END);
  total=ftell(pFile);

  fclose(pFile);

  return total / sizeof(Proveedores);
}

