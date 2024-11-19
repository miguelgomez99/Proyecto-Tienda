#include "Menu.h"
#include "archivoproducto.h"
#include <cstring>
#include <iostream>

Archivoproducto::Archivoproducto(){
  _fileName = "Producto.dat";
}

/*bool Archivoproducto::Guardar(const Producto &registro){
  FILE *pFile;
  bool result;

  pFile = fopen(_fileName.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  result = fwrite(&registro, sizeof(Producto), 1, pFile) == 1;

  fclose(pFile);

  return result;
}

Producto Archivoproducto::leer(int pos){
  FILE *pFile;
  Producto registro;

  pFile = fopen(_fileName.c_str(), "rb");

  if(pFile == nullptr){
      return registro;
  }

  fseek(pFile, sizeof(Producto) * pos, SEEK_SET);

  fread(&registro, sizeof(Producto), 1, pFile);

  fclose(pFile);

  return registro;
}

*/


/*
  bool Archivoproducto::modificarProducto (const Producto &producto, int pos){

        FILE *pModificar;
        pModificar = fopen ("Producto.dat", "rb+");

        if (pModificar==nullptr){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }
    fseek (pModificar, pos*sizeof (Producto), 0);

    bool escribio=fwrite (&producto, sizeof (Producto), 1, pModificar);

    fclose (pModificar);

    return escribio;


    }

*/

int Archivoproducto::getCantidad(){
  int total;
  FILE *pFile;
  pFile = fopen(_fileName.c_str(), "rb");

  if(pFile==nullptr){
      return 0;
  }

  fseek(pFile,0,SEEK_END);
  total=ftell(pFile);

  fclose(pFile);

  return total / sizeof(Producto);


}


    // GUARDADO DE PRODUCTOS
    void Archivoproducto::guardarProducto(const Producto& producto){
          FILE *pGuardar;
          pGuardar=fopen(_fileName.c_str(), "ab");
    if (pGuardar==nullptr){

            std::cout << "Error al abrir el archivo.";

    }
    int escribio=fwrite(&producto, sizeof(Producto), 1, pGuardar);
    fclose(pGuardar);

     if (escribio == 1) {
        std::cout << "Registro guardado correctamente." << std::endl;
    } else {
        std::cerr << "Error al guardar el registro." << std::endl;
    }
    }

    //LISTADO DE PRODUCTOS
    Producto Archivoproducto::leer(int pos){
  FILE *pLeer;
  Producto producto;

   pLeer=fopen(_fileName.c_str(), "rb");

   if(pLeer == nullptr){
      return producto;
  }

  fseek(pLeer, sizeof(Producto) * pos, SEEK_SET);

  fread(&producto, sizeof(Producto), 1, pLeer);

  fclose(pLeer);

  return producto;
}



    // BUSCAR PRODUCTO
    int Archivoproducto::buscarProducto (int num){

        if (num==1){

        std::cout << "Elija el filtro de busqueda: " << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "1. Filtrar por categoria de producto."<< std::endl;
        std::cout << "2. Filtrar por nombre de producto." << std::endl;
        std::cout << "3. Filtrar por proveedor." << std::endl;

        int opcion;
        std::cin >> opcion;



        switch (opcion){

        case 1:{

        FILE *pBuscar;
        Producto producto;

        int pos=0;

        pBuscar = fopen (_fileName.c_str(), "rb");

        if (pBuscar==nullptr){

        return -2;
    }
        std::cout << "Introduzca la categoria a buscar: " << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "1- Alimento." << std::endl;
        std::cout << "2- Juguetes." << std::endl;
        std::cout << "3- Accesorios." << std::endl;
        std::cout << "4- Medicacion." << std::endl;

        int opcion;
        std::cin >> opcion;
        char categoria[30]="";

        switch (opcion){
        case 1:

             strcpy(categoria,"Alimento");

            break;
        case 2:
            strcpy(categoria,"Juguetes");
            break;
        case 3:
            strcpy(categoria,"Accesorios");
            break;
        case 4:
            strcpy(categoria,"Medicacion");
            break;
        default:
            std::cout << "Introduzca una opcion correcta..." << std::endl;
            break;

        }


    while (fread(&producto, sizeof(Producto), 1, pBuscar)==1){
            if (strcmp(producto.getCategoria(),categoria)==0){
                fclose(pBuscar);
                return pos;
            }
            pos++;
    }
    std::cout << pos;

    fclose (pBuscar);
    return -1;

            break;
        }
        case 2:{

        FILE *pBuscar;
        Producto producto;

        int pos=0;

        pBuscar = fopen (_fileName.c_str(), "rb");

        if (pBuscar==nullptr){

        return -2;
    }
        std::cout << "Introduzca el nombre de producto a buscar: " << std::endl;
        char nombre[30];
        std::cin >> nombre;

    while (fread(&producto, sizeof(Producto), 1, pBuscar)==1){
            if (strcmp(producto.getNombreProducto(),nombre)==0){
                fclose(pBuscar);
                return pos;
            }
            pos++;
    }
    std::cout << pos;

    fclose (pBuscar);
    return -1;

            break;
        }
        case 3:{

        FILE *pBuscar;
        Producto producto;

        int pos=0;

        pBuscar = fopen (_fileName.c_str(), "rb");

        if (pBuscar==nullptr){

        return -2;
    }
        std::cout << "Introduzca el proveedor a buscar: " << std::endl;
        char categoria[30];
        std::cin >> categoria;

    while (fread(&producto, sizeof(Producto), 1, pBuscar)==1){
            if (producto.getCategoria()==categoria){
                fclose(pBuscar);
                return pos;
            }
            pos++;
    }
    std::cout << pos;

    fclose (pBuscar);
    return -1;

            break;
        }
        default:

            std::cout << "Elija una opcion correcta" << std::endl;
            break;
        }
        }
        else {

        FILE *pBuscar;
        Producto producto;

        int pos=0;

        pBuscar = fopen (_fileName.c_str(), "rb");

        if (pBuscar==nullptr){

        return -2;
    }
        std::cout << "Introduzca el ID de producto a modificar: " << std::endl;
        int Id;
        std::cin >> Id;

    while (fread(&producto, sizeof(Producto), 1, pBuscar)==1){
            if (producto.getCodigo()==Id){
                fclose(pBuscar);
                return pos;
            }
            pos++;
    }
    std::cout << pos;

        }
    }




    // MOSTRAR PRODUCTO
void Archivoproducto::MostrarProducto(const Producto &producto) {
    std::cout << "Fecha de ingreso de producto: " <<std::endl;
    producto.mostrarFechaProducto();
    std::cout << "Nombre del producto: " << producto.getNombreProducto() <<std::endl;
    std::cout << "Codigo del producto: " << producto.getCodigo() <<std::endl;
    std::cout << "Categoria del producto: " << producto.getCategoria() <<std::endl;
    std::cout << "Precio del producto: " << producto.getPrecio() <<std::endl;
    std::cout << "Cantidad del producto: " << producto.getCantidad() <<std::endl;
    std::cout << "Cuit de la empresa proveedora del producto: " << producto.getCuit() <<std::endl;
    std::cout << "-----------------------------------------------------" <<std::endl;
}

    // MODIFICAR PRODUCTO

   bool Archivoproducto::modificarProducto (const Producto &producto, int pos){

        FILE *pModificar;
        pModificar = fopen (_fileName.c_str(), "rb+");

        if (pModificar==nullptr){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return false;
    }
    fseek (pModificar, pos*sizeof (producto), 0);

    bool escribio=fwrite (&producto, sizeof (Producto), 1, pModificar);

    fclose (pModificar);

    return escribio;


    }

    void Archivoproducto::reporteCantidadPorCategoria() {
    FILE *pFile = fopen(_fileName.c_str(), "rb");
    if (pFile == nullptr) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return;
    }

    const int maxProductosPorCategoria = 100; // Límite de productos por categoría
    const char *categorias[4] = {"Alimento", "Juguetes", "Accesorios", "Medicacion"}; // Categorías fijas
    char productos[4][maxProductosPorCategoria][30]; // Productos por categoría
    int cantidadPorProducto[4][maxProductosPorCategoria] = {0}; // Cantidades por producto
    int numProductosPorCategoria[4] = {0}; // Número de productos por categoría
    int totalCantidadPorCategoria[4] = {0}; // Total acumulado por categoría

    Producto producto;

    while (fread(&producto, sizeof(Producto), 1, pFile) == 1) {
        // Buscar la categoría correspondiente
        for (int i = 0; i < 4; i++) {
            if (strcmp(producto.getCategoria(), categorias[i]) == 0) {
                // Sumar al total de la categoría
                totalCantidadPorCategoria[i] += producto.getCantidad();

                // Verificar si el producto ya existe en la categoría
                bool productoExistente = false;
                for (int j = 0; j < numProductosPorCategoria[i]; j++) {
                    if (strcmp(productos[i][j], producto.getNombreProducto()) == 0) {
                        cantidadPorProducto[i][j] += producto.getCantidad();
                        productoExistente = true;
                        break;
                    }
                }

                // Si el producto no existe, agregarlo
                if (!productoExistente && numProductosPorCategoria[i] < maxProductosPorCategoria) {
                    strcpy(productos[i][numProductosPorCategoria[i]], producto.getNombreProducto());
                    cantidadPorProducto[i][numProductosPorCategoria[i]] = producto.getCantidad();
                    numProductosPorCategoria[i]++;
                }
                break; // Salir del bucle de categorías
            }
        }
    }

    fclose(pFile);

    // Imprimir el reporte
    std::cout << "Reporte de cantidad por categoria y productos:" <<std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "Categoria: " << categorias[i] << std::endl;
        std::cout << "Total en stock: " << totalCantidadPorCategoria[i] << std::endl;;

        for (int j = 0; j < numProductosPorCategoria[i]; j++) {
            std::cout << "    Producto: " << productos[i][j]
                      << ", Cantidad: " << cantidadPorProducto[i][j] << std::endl;;
        }
        std::cout << "---------------------------------" << std::endl;
    }
}



