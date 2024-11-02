#ifndef ARCHIVOPROVEEDORES_H_INCLUDED
#define ARCHIVOPROVEEDORES_H_INCLUDED
#include <string>
#include "Proveedores.h"

/// SOLAMENTE LA CLASE DEL ARCHIVO DE PROVEEDORES
class Archivoproveedores{
    private:
        std::string _fileName;

    public:
        Archivoproveedores(const std::string& fileName);
        void AgregarProveedores();
        bool Guardar(Proveedores proveedores);
};


#endif // ARCHIVOPROVEEDORES_H_INCLUDED
