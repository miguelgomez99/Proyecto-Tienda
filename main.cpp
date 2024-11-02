#include <iostream>
#include "Menu.h"
#include "Proveedores.h"
#include "Archivoproveedores.h"

using namespace std;

    // MOSTRAR PROVEEDORES
void Proveedores::MostrarProveedores(Proveedores Proveedores) {
    std::cout << "Nombre del proveedor: " << Proveedores.getNombre() << std::endl;
    std::cout << "Contacto del proveedor: " << Proveedores.getContacto() << std::endl;
    std::cout << "Cuit del proveedor: " << Proveedores.getCuit() << std::endl;
    std::cout << "Producto del proveedor: " << Proveedores.getProducto() << std::endl;
}

int main()
//xd
{
    Menu menu;
    Proveedores pr;
    Archivoproveedores ap;
    menu.mostrarMenu();
    return 0;
}
//Prueba de cambio
//ASD
//msakfakf
//kfnaodfno
