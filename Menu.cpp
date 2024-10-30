#include <iostream>
#include "Menu.h"


   void Menu::mostrarMenu (){
    int opcion;

    do {

    std::cout << "Bienvenido a la tienda..." << std::endl;
    std::cout << "Ingrese la opcion deseada." << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1- Gestion de productos." << std::endl;
    std::cout << "2- Gestion de Proveedores." << std::endl;
    std::cout << "3- Consultas de Inventario." << std::endl;
    std::cout << "4- Salir." << std::endl;
    std::cin >> opcion;

    } while (opcion!=4);
    case 1:
        gestionProduct();
    case 2:
        gestionProveedores();
   }






   void Menu::gestionProducto(){
   }




