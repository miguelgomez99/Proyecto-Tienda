#ifndef ARCHIVOPROVEEDORES_H_INCLUDED
#define ARCHIVOPROVEEDORES_H_INCLUDED
#include <string>
#include "Proveedores.h"

/// SOLAMENTE LA CLASE DEL ARCHIVO DE PROVEEDORES
class Archivoproveedores{
public:
  Archivoproveedores();
  bool Guardar(const Proveedores &registro);
private:
  std::string _fileName;
};


#endif // ARCHIVOPROVEEDORES_H_INCLUDED
