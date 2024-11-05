#include "Menu.h"
#include "Producto.h"

class Archivoproducto{
public:
  Archivoproducto();
  bool Guardar(const Producto &registro);
  Producto leer(int pos);
  int getCantidad();
  bool modificarProducto (const Producto &producto, int pos);

private:
  std::string _fileName;
};


