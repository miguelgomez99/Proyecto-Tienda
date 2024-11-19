#pragma once
#include "Menu.h"
#include "Producto.h"


class Archivoproducto{
public:
  Archivoproducto();
  /*
  bool Guardar(const Producto &registro);
  Producto leer(int pos);
  int getCantidad();
  bool modificarProducto (const Producto &producto, int pos);
  */

  void guardarProducto(const Producto &producto);
  Producto leer(int pos);
  int buscarProducto (int num);
  void MostrarProducto(const Producto &producto);
  bool modificarProducto (const Producto &producto, int pos);
  int getCantidad ();
  void reporteCantidadPorCategoria();




private:
  std::string _fileName;
};


