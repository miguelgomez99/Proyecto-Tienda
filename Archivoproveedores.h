#pragma once
#include <string>
#include "Menu.h"

/// SOLAMENTE LA CLASE DEL ARCHIVO DE PROVEEDORES
class Archivoproveedores{
public:
  Archivoproveedores();
  bool Guardar(const Proveedores &registro);
  Proveedores leer(int pos);
  int getCantidad();

private:
  std::string _fileName;
};



