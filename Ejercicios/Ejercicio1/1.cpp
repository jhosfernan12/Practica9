#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

class Forma 
{
public:
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual void mostrarInformacion() const = 0;
    virtual ~Forma() = default;
};

class Circulo : public Forma 
{
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    double calcularArea() const override  //Polimorfismo
    {
        return PI * radio * radio;
    }
    double calcularPerimetro() const override 
    {
        return 2 * PI * radio;
    }
    void mostrarInformacion() const override 
    {
        cout << "Circulo: radio = " << radio << ", area = " << calcularArea() << ", perimetro = " << calcularPerimetro() << endl;
    }
};

class Rectangulo : public Forma 
{
private:
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}

    double calcularArea() const override  //Polimorfismo
    {
        return ancho * alto;
    }
    double calcularPerimetro() const override 
    {
        return 2 * (ancho + alto);
    }
    void mostrarInformacion() const override 
    {
        cout << "Rectangulo: ancho = " << ancho << ", alto = " << alto << ", area = " << calcularArea() << ", perimetro = " << calcularPerimetro() << endl;
    }
};

class Triangulo : public Forma 
{
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const override  //Polimorfismo
    {
        return 0.5 * base * altura;
    }
    double calcularPerimetro() const override 
    {
        return 3 * base;
    }
    void mostrarInformacion() const override 
    {
        cout << "Triangulo: base = " << base << ", altura = " << altura << ", area = " << calcularArea() << ", perimetro = " << calcularPerimetro() << endl;
    }
};

void agregarCirculo(Forma* formas[], int& indice) 
{
    double radio;
    cout << "Ingrese el radio del circulo: ";
    cin >> radio;
    formas[indice++] = new Circulo(radio);
}

void agregarRectangulo(Forma* formas[], int& indice) 
{
    double ancho, alto;
    cout << "Ingrese el ancho y el alto del rectangulo: ";
    cin >> ancho >> alto;
    formas[indice++] = new Rectangulo(ancho, alto);
}

void agregarTriangulo(Forma* formas[], int& indice) 
{
    double base, altura;
    cout << "Ingrese la base y la altura del triangulo: ";
    cin >> base >> altura;
    formas[indice++] = new Triangulo(base, altura);
}

bool hayFormasAgregadas(Forma* formas[], int cantidad) //Verificamos si existen formas en el arreglo
{
    for (int i = 0; i < cantidad; ++i) 
    {
        if (formas[i] != nullptr) 
        {
            return true;
        }
    }
    return false;
}

void mostrarInformacion(Forma* formas[], int cantidad) 
{
    if (!hayFormasAgregadas(formas, cantidad)) 
    {
        cout << "Todavia no hay formas agregadas" << endl;
    } 
    else 
    {
        for (int i = 0; i < cantidad; ++i) 
        {
            formas[i]->mostrarInformacion();
        }
    }
}

void borrarFormas(Forma* formas[], int cantidad)
{
    if (hayFormasAgregadas(formas, cantidad))
    {
        for (int i = 0; i < cantidad; ++i)
        {
            delete formas[i];
            formas[i] = nullptr; 
        }
        cout << "Formas Borradas Exitosamente" << endl;
    }
    else
    {
        cout << "No hay todavia Formas agregadas" << endl;
    }
}

void gestionarFormas() 
{
    Forma* formas[100] = { nullptr };  // Inicializar todos los punteros a nullptr
    int cantidadFormas = 0;
    int opcion;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1) Agregar circulo\n";
        cout << "2) Agregar rectangulo\n";
        cout << "3) Agregar triangulo\n";
        cout << "4) Mostrar informacion de todas las formas\n";
        cout << "5) Borrar Formas\n";
        cout << "6) Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

         switch (opcion)
        {
            case 1:
                agregarCirculo(formas, cantidadFormas);
                break;
            case 2:
                agregarRectangulo(formas, cantidadFormas);
                break;
            case 3:
                agregarTriangulo(formas, cantidadFormas);
                break;
            case 4:
                mostrarInformacion(formas, cantidadFormas);
                break;
            case 5:
                borrarFormas(formas, cantidadFormas);
                cantidadFormas = 0; //Reiniciamos el contador
                break;
            case 6:
                break;
            default:
                cout << "Opcion no valida\n";
        }

    } while (opcion != 6);

    for (int i = 0; i < cantidadFormas; ++i)  // Liberar memoria
    {
        delete formas[i];
    }
}

int main() 
{
    gestionarFormas();
    return 0;
}
