#include <iostream>
#include <string>
using namespace std;

class Empleado
{
public:
    string nombre;
    int edad;

    Empleado(string _nombre, int _edad) : nombre(_nombre), edad(_edad) {}
    virtual double CalcularSalario() const = 0;
    virtual ~Empleado() = default;
};

class Asalariado : public Empleado
{
private:
    int salario;

public:
    Asalariado(string _nombre, int _edad, int _salario) : Empleado(_nombre, _edad), salario(_salario) {}

    double CalcularSalario() const override // Polimorfismo
    {
        return salario;
    }
};

class PorHora : public Empleado
{
private:
    int horas;
    double dineroxhora;

public:
    PorHora(string _nombre, int _edad, int _horas, double _dineroxhora) : Empleado(_nombre, _edad), horas(_horas), dineroxhora(_dineroxhora) {}

    double CalcularSalario() const override // Polimorfismo
    {
        return horas * dineroxhora;
    }
};

class Comisionista : public Empleado
{
private:
    int trabajo;
    float comision;

public:
    Comisionista(string _nombre, int _edad, float _comision, int _trabajo) : Empleado(_nombre, _edad), comision(_comision), trabajo(_trabajo) {}

    double CalcularSalario() const override // Polimorfismo
    {
        return trabajo * comision;
    }
};

void AgregarAsalariado(Empleado* empleados[], int& indice)
{
    string nombre;
    int edad, salario;
    cout << "Ingrese el Nombre: " << endl;
    cin >> nombre;
    cout << "Ingrese la Edad: " << endl;
    cin >> edad;
    cout << "Ingrese el Salario: " << endl;
    cin >> salario;
    empleados[indice++] = new Asalariado(nombre, edad, salario);
}

void AgregarPorHora(Empleado* empleados[], int& indice)
{
    string nombre;
    int edad, horas;
    double dineroxhora;
    cout << "Ingrese el Nombre: " << endl;
    cin >> nombre;
    cout << "Ingrese la Edad: " << endl;
    cin >> edad;
    cout << "Ingrese las horas trabajadas: " << endl;
    cin >> horas;
    cout << "Ingrese la Tarifa de dinero por hora: " << endl;
    cin >> dineroxhora;
    empleados[indice++] = new PorHora(nombre, edad, horas, dineroxhora);
}

void AgregarComisionista(Empleado* empleados[], int& indice)
{
    string nombre;
    int edad, trabajo;
    float comision;
    cout << "Ingrese el Nombre: " << endl;
    cin >> nombre;
    cout << "Ingrese la Edad: " << endl;
    cin >> edad;
    cout << "Ingrese la Meta de trabajo: " << endl;
    cin >> trabajo;
    cout << "Ingrese la Comision: " << endl;
    cin >> comision;
    empleados[indice++] = new Comisionista(nombre, edad, comision, trabajo);
}

bool hayEmpleadosAgregados(Empleado* empleados[], int cantidad) // Verificamos si existen empleados en el arreglo
{
    for (int i = 0; i < cantidad; ++i)
    {
        if (empleados[i] != nullptr)
        {
            return true;
        }
    }
    return false;
}

void mostrarInformacion(Empleado* empleados[], int cantidad)
{
    if (!hayEmpleadosAgregados(empleados, cantidad))
    {
        cout << "Todavia no hay empleados registrados" << endl;
    }
    else
    {
        for (int i = 0; i < cantidad; ++i)
        {
            if (empleados[i] != nullptr)
            {
                cout << "Informacion del Empleado " << i + 1 << ":" << endl;
                cout << "Nombre: " << empleados[i]->nombre << endl;
                cout << "Edad: " << empleados[i]->edad << endl;
                cout << "Salario: " << empleados[i]->CalcularSalario() << endl;
            }
        }
    }
}

void borrarEmpleados(Empleado* empleados[], int cantidad)
{
    if (hayEmpleadosAgregados(empleados, cantidad))
    {
        for (int i = 0; i < cantidad; ++i)
        {
            delete empleados[i];
            empleados[i] = nullptr;
        }
        cout << "Empleados Borrados Exitosamente" << endl;
    }
    else
    {
        cout << "No hay todavia empleados agregados" << endl;
    }
}

void gestionarEmpleados()
{
    Empleado* empleados[100] = { nullptr }; // Inicializamos todos los punteros a nullptr
    int cantidadEmpleados = 0;
    int opcion;

    do
    {
        cout << "\nMenu de opciones:\n";
        cout << "1) Agregar Asalariado\n";
        cout << "2) Agregar PorHora\n";
        cout << "3) Agregar Comisionista\n";
        cout << "4) Mostrar informacion de todos los empleados\n";
        cout << "5) Borrar Empleados\n";
        cout << "6) Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            AgregarAsalariado(empleados, cantidadEmpleados);
            break;
        case 2:
            AgregarPorHora(empleados, cantidadEmpleados);
            break;
        case 3:
            AgregarComisionista(empleados, cantidadEmpleados);
            break;
        case 4:
            mostrarInformacion(empleados, cantidadEmpleados);
            break;
        case 5:
            borrarEmpleados(empleados, cantidadEmpleados);
            cantidadEmpleados = 0; // Reiniciamos el contador
            break;
        case 6:
            borrarEmpleados(empleados, cantidadEmpleados); // Asegurarse de liberar memoria antes de salir
            break;
        default:
            cout << "Opcion no valida\n";
        }

    } while (opcion != 6);
}

int main()
{
    gestionarEmpleados();

    return 0;
}
