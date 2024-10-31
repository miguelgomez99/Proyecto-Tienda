#include <iostream>
#include "Menu.h"
#include "Proveedores.h"

    // MENU PRINCIPAL
   void Menu::mostrarMenu (){
    int opcion;

    do {

    std::cout << "...Bienvenido a la tienda..." << std::endl;
    std::cout << "------Menu principal------" << std::endl;
    std::cout << "Ingrese la opcion deseada:" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "1- Administracion de Productos." << std::endl;
    std::cout << "2- Administracion de Proveedores." << std::endl;
    std::cout << "3- Administracion de Ventas." << std::endl;
    std::cout << "4- Administracion de Promociones y Descuentos." << std::endl;
    std::cout << "5- Administracion de Consultas." << std::endl;
    std::cout << "6- Administracion de Reportes." << std::endl;
    std::cout << "0- Salir." << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cin >> opcion;

    switch (opcion){
    case 1:
        system("cls");
        AdminProductos();
        break;
    case 2:
        system("cls");
        AdminProveedores();
        break;
    case 3:
        system("cls");
        AdminVentas();
        break;
    case 4:
        system("cls");
        AdminPromociones();
        break;
    case 5:
        system("cls");
        AdminConsultas();
        break;
    case 6:
        system("cls");
        AdminReportes();
        break;
    case 0:
        std::cout << "Saliendo del sistema..." << std::endl;
        break;
    default:
        std::cout << "Opcion invalida, por favor ingrese una opcion correcta :)." << std::endl;
        break;

    }

    } while (opcion!=0);

   }

     // SUBMENU PRODUCTOS
   void Menu::AdminProductos(){
       int opcion;

    do {
        std::cout << "----Administracion de Productos----" << std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "1- Ingreso de producto." << std::endl;
        std::cout << "2- Buscar producto." << std::endl;
        std::cout << "3- Modificar inventario." << std::endl;
        std::cout << "0- Volver al menu principal." << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cin >> opcion;

        switch(opcion){
            case 1:
                std::cout << "Ingrese los siguientes datos del producto: " << std::endl;
                break;
            case 2:
                std::cout << "Ingrese el producto a buscar:" << std::endl;
                break;
            case 3:
                std::cout << "Ingrese el ID de producto que desea modificar:" << std::endl;
                break;
            case 0:
                system ("cls");
                break;
            default:
                std::cout << "Opcion invalida, por favor ingrese una opcion correcta :)." << std::endl;
        }
    } while(opcion!=0);
    }



    // SUBMENU PROVEEDORES
       void Menu::AdminProveedores(){
            int opcion;
            Proveedores proveedores;
    do {
        std::cout << "----Administracion de Proveedores----"<< std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "1- Listado de proveedores."<< std::endl;
        std::cout << "2- Modificar Proveedores." << std::endl;
        std::cout << "3- Agregar proveedores." << std::endl;
        std::cout << "0- Volver al menu principal." << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cin >> opcion;

        switch(opcion){
            case 1:
                std::cout << "Mostrando listado de proveedores: " << std::endl;
                break;
            case 2:
                std::cout << "Ingrese el cuit de los datos del proveedor que quiera modificar: " << std::endl;
                break;
            case 3:
                std::cout << "Ingrese los siguientes datos:" << std::endl;
                proveedores.AgregarProveedores();
                proveedores.guardarProveedores(proveedores);
                break;
            case 0:
                system ("cls");
                break;
            default:
                std::cout << "Opcion invalida, por favor ingrese una opcion correcta :)." << std::endl;
        }
    } while(opcion!=0);
        }



    // SUBMENU VENTAS
        void Menu::AdminVentas(){
            int opcion;
    do {
        std::cout << "----Administracion de Ventas----" << std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "1- Registro de ventas." << std::endl;
        std::cout << "2- Listado de venta." << std::endl;
        std::cout << "3- Modificacion de venta." << std::endl;
        std::cout << "0- Volver al menu principal." << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cin >> opcion;

        switch(opcion){
            case 1:
                std::cout << "Ingrese los siguientes datos de la venta: " << std::endl;
                break;
            case 2:
                std::cout << "Listado de ventas: " << std::endl;
                break;
            case 3:
                std::cout << "Ingrese que venta desea modificar: " << std::endl;
                break;
            case 0:
                system ("cls");
                break;
            default:
                std::cout << "Opcion invalida, por favor ingrese una opcion correcta :)." << std::endl;
        }
    } while(opcion!=0);
        }


    // SUBMENU PROMOCIONES
        void Menu::AdminPromociones(){
            int opcion;
    do {
        std::cout << "----Promociones y Descuentos----" << std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "1. Listado de promociones activas." << std::endl;
        std::cout << "2. Modificar promociones." << std::endl;
        std::cout << "0. Volver al menu principal." << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cin >> opcion;

        switch(opcion){
            case 1:
                std::cout << "Listado de promociones: " << std::endl;
                break;
            case 2:
                std::cout << "Ingrese que promocion desea modificar: " << std::endl;
                break;
            case 0:
                system ("cls");
                break;
            default:
                std::cout << "Opcion invalida, por favor ingrese una opcion correcta :)." << std::endl;
        }
    } while(opcion!=0);

        }



    // SUBMENU CONSULTAS
        void Menu::AdminConsultas(){
                int opcion;
    do {
        std::cout << "----Consultas----" << std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "1. Consulta de clientes." << std::endl;
        std::cout << "2. Consulta de en stock." << std::endl;
        std::cout << "0. Volver al menu principal." << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cin >> opcion;

        switch(opcion){
            case 1:
                std::cout << "Ingrese el dato del cliente que desea consultar: " << std::endl;
                break;
            case 2:
                std::cout << "Ingrese el dato del producto en stock que desea consultar:" << std::endl;
                break;
            case 0:
                system ("cls");
                break;
            default:
                std::cout << "Opcion invalida, por favor ingrese una opcion correcta :)." << std::endl;
        }
    } while(opcion!=0);
        }



    // SUBMENU REPORTES
        void Menu::AdminReportes(){
            int opcion;
    do {
        std::cout << "----Reportes----" << std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "1. Reporte de stock de productos." << std::endl;
        std::cout << "2. Reporte de ventas." << std::endl;;
        std::cout << "3. Reporte de productos mas vendidos." << std::endl;
        std::cout << "4. Reporte de proveedores." << std::endl;
        std::cout << "0. Volver al menu principal." << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cin >> opcion;

        switch(opcion){
            case 1:
                std::cout << "Generando reporte de stock de productos..." << std::endl;
                break;
            case 2:
                std::cout << "Generando reporte de ventas..." << std::endl;
                break;
            case 3:
                std::cout << "Generando reporte de productos mas vendidos..." << std::endl;
                break;
            case 4:
                std::cout << "Generando reporte de proveedores..." << std::endl;
                break;
            case 0:
                system ("cls");
                break;
            default:
                std::cout << "Opcion invalida, por favor ingrese una opcion correcta :)." << std::endl;
        }
    } while(opcion!=0);

        }




