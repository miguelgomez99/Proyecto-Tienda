#pragma once
#include "Menu.h"
#include "Detalledeventa.h"

class ArchivoDetalledeVenta {

public:

    ArchivoDetalledeVenta();

    void CargarDetalledeventa ();
    void MostrarDetalledeVenta(const Detalledeventa &detalledeventa);
    int getCantidadDetalle();
    void guardarDetalledeVenta(const Detalledeventa &detalledeventa);
    Detalledeventa leerDetalle(int pos);
    int buscarDetallesPorVenta();
    bool modificarDetalledeVenta (const Detalledeventa &detalledeventa, int pos);
    void reporteProductoMasVendido();


private:

    std::string _fileName;

   };
