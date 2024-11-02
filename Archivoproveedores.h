#pragma once
#include <string>
#include "Menu.h"

/// SOLAMENTE LA CLASE DEL ARCHIVO DE PROVEEDORES
class Archivoproveedores{
public:
  Archivoproveedores();
  bool Guardar(const Proveedores &registro);
private:
  std::string _fileName;
};



