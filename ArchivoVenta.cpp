#include "ArchivoVenta.h"

ArchivoVenta::ArchivoVenta(){
    _fileName = "Venta.dat";
}

void ArchivoVenta::MostrarVenta(const Venta &venta) {
    std::cout << "-----------------------------------------------" <<std::endl;
    std::cout << "Nombre del cliente: " << venta.getNombre() <<std::endl;
    std::cout << "Correo electronico del cliente: " << venta.getEmail() <<std::endl;
    std::cout << "metodo de pago: " << venta.getFormadepago() <<std::endl;
    std::cout << "Id de venta: " << venta.getIdVenta() <<std::endl;
}

int ArchivoVenta::getCantidad(){
  int total;
  FILE *pCantidad;
  pCantidad = fopen(_fileName.c_str(), "rb");

  if(pCantidad==nullptr){
      return 0;
  }

  fseek(pCantidad,0,SEEK_END);
  total=ftell(pCantidad);

  fclose(pCantidad);

  return total / sizeof(Venta);

}


    // GUARDADO DE VentaS
    void ArchivoVenta::guardarVenta(const Venta& venta){
          FILE *pGuardar;
          pGuardar=fopen(_fileName.c_str(), "ab");
    if (pGuardar==nullptr){

            std::cout << "Error al abrir el archivo.";

    }
    int escribio=fwrite(&venta, sizeof(Venta), 1, pGuardar);
    fclose(pGuardar);

     if (escribio == 1) {
        std::cout << "Venta guardada correctamente." << std::endl;
    } else {
        std::cerr << "Error al guardar la venta." << std::endl;
    }
    }

    //LISTADO DE VentaS
   Venta ArchivoVenta::leer(int pos){
  FILE *pLeer;
  Venta venta;

   pLeer=fopen(_fileName.c_str(), "rb");

   if(pLeer == nullptr){
      return venta;
  }

  fseek(pLeer, sizeof(Venta) * pos, SEEK_SET);

  fread(&venta, sizeof(Venta), 1, pLeer);

  fclose(pLeer);

  return venta;
}



    // BUSCAR Venta
    int ArchivoVenta::buscarVenta (){

        int id;
        std::cin >> id;

        FILE *pBuscar;
        Venta venta;


        int pos=0;

        pBuscar = fopen (_fileName.c_str(), "rb");

        if (pBuscar==nullptr){

        return -2;
    }

    while (fread(&venta, sizeof(Venta), 1, pBuscar)==1){
            if (venta.getIdVenta()==id){
                fclose(pBuscar);
                return pos;

            }
            pos++;
    }

    std::cout << pos;

    fclose (pBuscar);
    return -1;

    }

        // MODIFICAR Venta

   bool ArchivoVenta::modificarVenta (const Venta &venta, int pos){

        FILE *pModificar;
        pModificar = fopen (_fileName.c_str(), "rb+");

        if (pModificar==nullptr){
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return false;
    }
    fseek (pModificar, pos*sizeof (Venta), 0);

    bool escribio=fwrite (&venta, sizeof (Venta), 1, pModificar);

    fclose (pModificar);

    return escribio;

    }
