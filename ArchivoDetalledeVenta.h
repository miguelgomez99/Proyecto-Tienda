#pragma once
#include "Menu.h"
#include "Detalledeventa.h"

class ArchivoDetalledeVenta {

public:

    ArchivoDetalledeVenta();

    void MostrarDetalledeVenta(const Detalledeventa &detalledeventa);
    int getCantidadDetalle();
    void guardarDetalledeVenta(const Detalledeventa &detalledeventa);
    Detalledeventa leerDetalle(int pos);
    int buscarDetalledeVenta ();
    bool modificarDetalledeVenta (const Detalledeventa &detalledeventa, int pos);

private:

    std::string _fileName;

   };
