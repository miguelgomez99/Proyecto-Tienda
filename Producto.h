#pragma once
#include "Menu.h"

class Producto {

protected:
    char _nombreMarca[20];
    int _Codigo;
    char _Categoria [20];
    float _Precio;
    int _Cantidad;
    int _Cuit;
    /*int _dia;
    int _mes;
    int _anio;
    */

public:

// Constructor

    Producto();
    void AgregarProducto();

  /*  // Metodos de fecha

    void Cargar();
    void Mostrar();
    */

// Setters
    void setnombreMarca (const char nombre[]);

    void setCodigo(int codigo);

    void setCategoria (const char categoria[]);

    void setPrecio (float precio);

    void setCantidad (int cantidad);

    void setCuit (int cuit);
/*
    ///Seters fecha
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    */





// Getters
    const char* getnombreMarca () const;

    int getCodigo() const;

    const char* getCategoria () const;

    float getPrecio () const;

    int getCantidad () const;

    int getCuit () const;

    /*
    ///Getters fecha
    int getDia();
    int getMes();
    int getAnio();
    */










};


