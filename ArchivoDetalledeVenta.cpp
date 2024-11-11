#include "ArchivoDetalledeVenta.h"

    ArchivoDetalledeVenta::ArchivoDetalledeVenta(){
    _fileName = "DetalledeVenta.dat";
}


void ArchivoDetalledeVenta::MostrarDetalledeVenta(const Detalledeventa& detalledeventa) {

    std::cout << detalledeventa.getIdVentaDetalle() << "            ";
    std::cout << detalledeventa.getNombreProducto() << "               ";
    std::cout << detalledeventa.getCantidad() << "        ";
    std::cout << detalledeventa.getPrecioUnitario() << "       ";
    std::cout << detalledeventa.getSubtotal() <<std::endl;
}

int ArchivoDetalledeVenta::getCantidadDetalle(){
  int total;
  FILE *pCantidad;
  pCantidad = fopen(_fileName.c_str(), "rb");

  if(pCantidad==nullptr){
      return 0;
  }

  fseek(pCantidad,0,SEEK_END);
  total=ftell(pCantidad);

  fclose(pCantidad);

  return total / sizeof(Detalledeventa);

}


    // GUARDADO DE DetalledeVentaS
    void ArchivoDetalledeVenta::guardarDetalledeVenta(const Detalledeventa& detalledeventa){
          FILE *pGuardar;
          pGuardar=fopen(_fileName.c_str(), "ab");
    if (pGuardar==nullptr){

            std::cout << "Error al abrir el archivo.";

    }
    int escribio=fwrite(&detalledeventa, sizeof(Detalledeventa), 1, pGuardar);
    fclose(pGuardar);

     if (escribio == 1) {
        std::cout << "DetalledeVenta guardada correctamente." << std::endl;
    } else {
        std::cerr << "Error al guardar la DetalledeVenta." << std::endl;
    }
    }

    //LISTADO DE DetalledeVentaS
   Detalledeventa ArchivoDetalledeVenta::leerDetalle(int pos){
  FILE *pLeer;
  Detalledeventa detalledeventa;

   pLeer=fopen(_fileName.c_str(), "rb");

   if(pLeer == nullptr){
      return detalledeventa;
  }

  fseek(pLeer, sizeof(Detalledeventa) * pos, SEEK_SET);

  fread(&detalledeventa, sizeof(Detalledeventa), 1, pLeer);

  fclose(pLeer);

  return detalledeventa;
}



    // BUSCAR DetalledeVenta
    int ArchivoDetalledeVenta::buscarDetallesPorVenta (){

        int id;
        std::cin >> id;

        FILE *pBuscar;
        Detalledeventa Detalledeventa;


        int pos=0;

        pBuscar = fopen (_fileName.c_str(), "rb");

        if (pBuscar==nullptr){

        return -2;
    }

    while (fread(&Detalledeventa, sizeof(Detalledeventa), 1, pBuscar)==1){
            if (Detalledeventa.getIdVentaDetalle()==id){
                fclose(pBuscar);
                return pos;

            }
            pos++;
    }

    std::cout << pos;

    fclose (pBuscar);
    return -1;

    }

/*
    int ArchivoDetalledeVenta::buscarDetallesPorVenta(int idVenta, Detalledeventa detalles[], int maxDetalles) {
    FILE *pBuscar = fopen(_fileName.c_str(), "rb");
    if (pBuscar == nullptr) {
        return 0;
    }

    Detalledeventa detalle;
    int count = 0;
    while (fread(&detalle, sizeof(Detalledeventa), 1, pBuscar) == 1) {
        if (detalle.getIdVentaDetalle() == idVenta) {
            if (count < maxDetalles) {
                detalles[count++] = detalle;
            } else {
                std::cout << "Se alcanzó el límite de detalles por venta." << std::endl;
                break;
            }
        }
    }

    fclose(pBuscar);
    return count;
}
*/
        // MODIFICAR DetalledeVenta

   bool ArchivoDetalledeVenta::modificarDetalledeVenta (const Detalledeventa &detalledeventa, int pos){

        FILE *pModificar;
        pModificar = fopen (_fileName.c_str(), "rb+");

        if (pModificar==nullptr){
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return false;
    }
    fseek (pModificar, pos*sizeof (Detalledeventa), 0);

    bool escribio=fwrite (&detalledeventa, sizeof (Detalledeventa), 1, pModificar);

    fclose (pModificar);

    return escribio;

    }

