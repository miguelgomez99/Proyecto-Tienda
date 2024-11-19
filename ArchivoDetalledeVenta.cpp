#include "ArchivoDetalledeVenta.h"
#include "ArchivoVenta.h"
#include <cstring>

    ArchivoDetalledeVenta::ArchivoDetalledeVenta(){
    _fileName = "DetalledeVenta.dat";
}


void ArchivoDetalledeVenta::MostrarDetalledeVenta(const Detalledeventa& detalledeventa) {
    std::cout << detalledeventa.getIdVentaDetalle() << "           ";
    std::cout << detalledeventa.getCategoriaVenta() << "        ";
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

    void ArchivoDetalledeVenta::reporteProductoMasVendido() {
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");
    if (pFile == nullptr) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return;
    }

    char masVendido[30]="";
    int masCantidad=0;

    const int maxCategorias = 100; // Límite de categorías para el ejemplo
    char categorias[maxCategorias][30]; // Arreglo para nombres de categorías
    int cantidades[maxCategorias] = {0}; // Arreglo para cantidades acumuladas
    int numCategorias = 0;

    Detalledeventa venta;
    bool categoriaExistente;

    // Leer cada producto y acumular la cantidad en su categoría
    while (fread(&venta, sizeof(Detalledeventa), 1, pFile) == 1) {
        categoriaExistente = false;

        // Verificar si la categoría ya está en el arreglo
        for (int i = 0; i < numCategorias; i++) {
            if (strcmp(categorias[i], venta.getCategoriaVenta()) == 0) {
                cantidades[i] += venta.getCantidad();
                categoriaExistente = true;
                break;
            }
        }

        // Si la categoría no existe, se agrega como nueva
        if (!categoriaExistente && numCategorias < maxCategorias) {
            strcpy(categorias[numCategorias], venta.getCategoriaVenta());
            cantidades[numCategorias] = venta.getCantidad();
            numCategorias++;
        }
    }

    fclose(pFile);

      if (numCategorias == 0) {
        std::cout << "No hay productos vendidos." << std::endl;
        return;
    }

    // Imprimir el reporte de categorías y cantidades acumuladas


    for (int i = 0; i < numCategorias; i++) {
        if (cantidades[i]>masCantidad){
            strcpy(masVendido,categorias[i] );
            masCantidad=cantidades[i];
        }
    }

    std::cout << "La categoria del producto mas vendido es la de:" << masVendido << std::endl;
    std::cout << "Con una cantidad de:" << masCantidad << std::endl;

}





