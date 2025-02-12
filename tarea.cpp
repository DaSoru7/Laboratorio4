#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <conio.h>


using namespace std;

struct Producto
{
    int id, existencias;
    string nombre;
    double precio;
};

// Declaraciones de funciones
int obtener_id(vector<Producto> &);
int obtener_existencias();
double obtener_precio();
void agregar_Producto(vector<Producto> &);
Producto crear_producto(vector<Producto> &);
void inventario(vector<Producto> &);
void Buscar();
string Producto_nombre(); // Agregado



int main()
{
    int opcion;
    bool comprando = true;
    vector<Producto> lista_productos;

    while (comprando == true)
    {
    
        cout << "1. Agregar producto" << endl
             << "2. Inventario" << endl
             << "3. Buscar productos" << endl
             << "4. Comprar" << endl
             << "5. Salir" << endl;

        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregar_Producto(lista_productos);
            break;
        case 2:
            inventario(lista_productos); // Se pasa la lista de productos
            break;
        case 3:
            Buscar();
            break;
        case 4:
            // Código para comprar
            break;
        case 5:
            cout << "Saliendo..." << endl;
            comprando = false;
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
        }
    }
    return 0;
}

void agregar_Producto(vector<Producto> &lista_productos)
{
    cout << "AGREGAR PRODUCTO" << endl;
    lista_productos.push_back(crear_producto(lista_productos));
    cout << "PRODUCTO AGREGADO EXITOSAMENTE" << endl;
    getch();
    system("cls");
}

Producto crear_producto(vector<Producto> &lista_productos)
{
    Producto producto;
    producto.nombre = Producto_nombre();
    producto.id = obtener_id(lista_productos);
    producto.existencias = obtener_existencias();
    producto.precio = obtener_precio();
    return producto;
}

int obtener_existencias()
{
    int existencias;
    cout << "Ingrese la cantidad: ";
    cin >> existencias;
    return existencias;
}

double obtener_precio()
{
    double precio;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    return precio;
}

string Producto_nombre()
{
    string nombre_producto;
    cin.ignore(); // Se agrega para evitar problemas con getline()
    while (true)
    {
        cout << "Ingrese el nombre del producto: ";
        getline(cin, nombre_producto);
        if (nombre_producto.empty())
        {
            cout << "Ingrese un nombre válido." << endl;
        }
        else
        {
            break;
        }
    }
    return nombre_producto;
}

int obtener_id(vector<Producto> &lista_productos)
{
    if (lista_productos.empty())
    {
        return 1;
    }
    else
    {
        return lista_productos.back().id + 1;
    }
}

void inventario(vector<Producto> &lista_productos)
{
    cout << setw(7) << left << "ID"
         << setw(15) << left << "NOMBRE"
         << setw(10) << left << "CANTIDAD"
         << setw(10) << left << "PRECIO" << endl;

    for(const Producto &producto : lista_productos){
        cout << setw(7) << left << producto.id
         << setw(15) << left << producto.nombre
         << setw(10) << left << producto.existencias
         << setw(10) << left << "Q" << producto.precio << endl;
    }
}

void Buscar()
{
    cout << "Función de búsqueda en desarrollo." << endl;
}


