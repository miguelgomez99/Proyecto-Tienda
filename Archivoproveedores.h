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

      void guardarProveedores(const Proveedores& proveedores);

    bool listarProveedores();

    void MostrarProveedores(const Proveedores& proveedor);

    int buscarProveedores ();

    bool bajaRegistro ();

    bool modificarProveedores (const Proveedores &proveedors, int pos);





private:
  std::string _fileName;
};



