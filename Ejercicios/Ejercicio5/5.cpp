#include <iostream>
#include <string>

using namespace std;


class Producto 
{
    public:
        Producto(const string& nombre, double precio, int cantidad) : nombre(nombre), precio(precio), cantidad(cantidad) {}

        virtual double calcularValorTotal() const 
        {
            return precio * cantidad;
        }

        virtual void aplicarDescuento(double porcentaje) 
        {
            precio -= precio * porcentaje / 100;
        }

        virtual void mostrarInformacion() const 
        {
            cout << "Nombre: " << nombre << ", Precio: " << precio << ", Cantidad: " << cantidad;
        }
         virtual ~Producto() = default;
    protected:
        string nombre;
        double precio;
        int cantidad;
};


class Electronico : public Producto 
{
    public:
        Electronico(const string& nombre, double precio, int cantidad, int garantia) : Producto(nombre, precio, cantidad), garantia(garantia) {}

        void mostrarInformacion() const override 
        {
            Producto::mostrarInformacion();
            cout << ", Garantia: " << garantia << " meses" << endl;
        }

    private:
        int garantia;
};

class Ropa : public Producto 
{
    public:
        Ropa(const string& nombre, double precio, int cantidad, const string& talla) 
            : Producto(nombre, precio, cantidad), talla(talla) {}

        void mostrarInformacion() const override 
        {
            Producto::mostrarInformacion();
            cout << ", Talla: " << talla << endl;
        }

    private:
        string talla;
};


class Alimento : public Producto 
{
    public:
        Alimento(const string& nombre, double precio, int cantidad, const string& fechaExpiracion) : Producto(nombre, precio, cantidad), fechaExpiracion(fechaExpiracion) {}

        void mostrarInformacion() const override 
        {
            Producto::mostrarInformacion();
            cout << ", Fecha de Expiracion: " << fechaExpiracion << endl;
        }

private:
    string fechaExpiracion;
};


double calcularValorInventario(Producto** inventario, int tamano) //Calcular el valor total del inventario
{
    double valorTotal = 0.0;
    for (int i = 0; i < tamano; ++i) 
    {
        valorTotal += inventario[i]->calcularValorTotal();
    }
    return valorTotal;
}


void aplicarDescuentoInventario(Producto** inventario, int tamano, double porcentaje) //aplicar un descuento a todos los productos del inventario
{
    for (int i = 0; i < tamano; ++i) {
        inventario[i]->aplicarDescuento(porcentaje);
    }
}

int main() 
{
    const int tamanoInventario = 3;
    Producto* inventario[tamanoInventario];

    inventario[0] = new Electronico("Laptop", 1000, 10, 12);
    inventario[1] = new Ropa("Camiseta", 20, 50, "M");
    inventario[2] = new Alimento("Manzanas", 1, 100, "31-12-2025");

    cout << "Inventario Inicial:" << endl;
    for (int i = 0; i < tamanoInventario; ++i) 
    {
        inventario[i]->mostrarInformacion();
    }
    cout << endl;

    double valorTotal = calcularValorInventario(inventario, tamanoInventario);
    cout << "Valor total del inventario: S/" << valorTotal << endl;

    cout << "Aplicando un descuento del 10% a todo el inventario..." << endl;
    aplicarDescuentoInventario(inventario, tamanoInventario, 10);

    cout << "Inventario despues de aplicar el descuento:" << endl;
    for (int i = 0; i < tamanoInventario; ++i)
    {
        inventario[i]->mostrarInformacion();
    }
    cout << endl;

    valorTotal = calcularValorInventario(inventario, tamanoInventario);
    cout << "Valor total del inventario despues del descuento: S/" << valorTotal << endl;

    for (int i = 0; i < tamanoInventario; ++i) // Liberamps memoria
    {
        delete inventario[i];
    }

    return 0;
}
