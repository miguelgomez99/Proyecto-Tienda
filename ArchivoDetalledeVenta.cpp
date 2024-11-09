#include "ArchivoDetalledeVenta.h"

    ArchivoDetalledeVenta::ArchivoDetalledeVenta(){
    _fileName = "DetalledeDetalledeVenta.dat";
}

void ArchivoDetalledeVenta::MostrarDetalledeVenta(const Detalledeventa& detalledeventa) {
    std::cout << "-----------------------------------------------" <<std::endl;
    std::cout << "Id de la venta: " << detalledeventa.getIdVenta() <<std::endl;
    std::cout << "Nombre del producto: " << detalledeventa.getNombreProducto() <<std::endl;
    std::cout << "Cantidad: " << detalledeventa.getCantidad() <<std::endl;
    std::cout << "Precio unitario: " << detalledeventa.getPrecioUnitario() <<std::endl;
    std::cout << "Precio unitario: " << detalledeventa.getSubtotal() <<std::endl;
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
    int ArchivoDetalledeVenta::buscarDetalledeVenta (){

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
            if (Detalledeventa.getIdVenta()==id){
                fclose(pBuscar);
                return pos;

            }
            pos++;
    }

    std::cout << pos;

    fclose (pBuscar);
    return -1;

    }

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

