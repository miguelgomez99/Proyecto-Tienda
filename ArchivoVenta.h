#include "Menu.h"
#include "Venta.h"
#pragma once



class ArchivoVenta {

public:

    ArchivoVenta();
    void MostrarVenta(const Venta &venta);
    int getCantidad();
    void guardarVenta(const Venta& venta);
    Venta leer(int pos);
    int buscarVenta ();
    bool modificarVenta (const Venta &venta, int pos);

private:

    std::string _fileName;

   };





