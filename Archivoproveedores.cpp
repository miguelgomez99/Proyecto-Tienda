#include "Menu.h"
#include "Proveedores.h"

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
