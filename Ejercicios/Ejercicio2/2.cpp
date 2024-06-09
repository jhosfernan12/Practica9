#include <iostream>
using namespace std;

class Animal
{
    protected:
        string especie;

    public:
        Animal(string _especie) : especie(_especie) {}

        virtual void Comer() const = 0;
        virtual void Dormir() const = 0;
        virtual void Moverse() const = 0;
        virtual ~Animal() = default;
};

class Mamifero : public Animal
{
    public:
        Mamifero(string _especie) : Animal(_especie) {}

        void Comer() const override //Polimorfismo
        {
            cout << "El Mamifero " << especie << " come " << endl;
        }

        void Dormir() const override 
        {
            cout << "El Mamifero " << especie << " duerme " << endl;
        }

        void Moverse() const override 
        {
            cout << "El Mamifero " << especie << " se mueve " << endl;
        }
};

class Ave : public Animal
{
    private:
        const int numeroalas = 2;
        const int pico = 1;

    public:
        Ave(string _especie) : Animal(_especie) {}

        void Comer() const override //Polimorfismo
        {
            cout << "El Ave con " << numeroalas << " alas y pico, de especie " << especie << " come " << endl;
        }

        void Dormir() const override 
        {
            cout << "El Ave con " << numeroalas << " alas y pico, de especie " << especie << " duerme " << endl;
        }

        void Moverse() const override 
        {
            cout << "El Ave con " << numeroalas << " alas y pico, de especie " << especie << " se mueve " << endl;
        }
};

class Reptil : public Animal
{
    public:
        Reptil(string _especie) : Animal(_especie) {}

        void Comer() const override //Polimorfismo
        {
            cout << "El Reptil con escamas de especie " << especie << " come " << endl;
        }

        void Dormir() const override 
        {
            cout << "El Reptil con escamas de especie " << especie << " duerme " << endl;
        }

        void Moverse() const override
        {
            cout << "El Reptil con escamas de especie " << especie << " se mueve " << endl;
        }
};

void agregarMamifero(Animal* animales[], int& indice)
{
    string espe;
    cout << "Ingrese la especie: ";
    cin >> espe;
    animales[indice++] = new Mamifero(espe);
}

void agregarAve(Animal* animales[], int& indice)
{
    string espe;
    cout << "Ingrese la especie: ";
    cin >> espe;
    animales[indice++] = new Ave(espe);
}

void agregarReptil(Animal* animales[], int& indice)
{
    string espe;
    cout << "Ingrese la especie: ";
    cin >> espe;
    animales[indice++] = new Reptil(espe);
}

bool hayAnimalesAgregados(Animal* animales[], int cantidad) //Verficamos si existen animales en el arreglo
{
    for (int i = 0; i < cantidad; ++i)
    {
        if (animales[i] != nullptr)
        {
            return true;
        }
    }
    return false;
}

void mostrarInformacion(Animal* animales[], int cantidad)
{
    if (!hayAnimalesAgregados(animales, cantidad))
    {
        cout << "Todavia no hay animales agregados" << endl;
    }
    else
    {
        for (int i = 0; i < cantidad; ++i)
        {
            if (animales[i] != nullptr)
            {
                cout << "Informacion del animal " << i + 1 << ":" << endl;
                animales[i]->Comer();
                animales[i]->Dormir();
                animales[i]->Moverse();
            }
        }
    }
}

void borrarAnimales(Animal* animales[], int cantidad)
{
    if (hayAnimalesAgregados(animales, cantidad))
    {
        for (int i = 0; i < cantidad; ++i)
        {
            delete animales[i];
            animales[i] = nullptr; 
        }
        cout << "Animales Borrados Exitosamente" << endl;
    }
    else
    {
        cout << "No hay todavia animales agregados" << endl;
    }
}

void gestionarAnimales()
{
    Animal* animales[100] = {nullptr}; // Inicializamos todos los punteros a nullptr
    int cantidadAnimales = 0;
    int opcion;

    do
    {
        cout << "\nMenu de opciones:\n";
        cout << "1) Agregar Mamifero\n";
        cout << "2) Agregar Ave\n";
        cout << "3) Agregar Reptil\n";
        cout << "4) Mostrar informacion de todos los animales\n";
        cout << "5) Borrar Animales\n";
        cout << "6) Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                agregarMamifero(animales, cantidadAnimales);
                break;
            case 2:
                agregarAve(animales, cantidadAnimales);
                break;
            case 3:
                agregarReptil(animales, cantidadAnimales);
                break;
            case 4:
                mostrarInformacion(animales, cantidadAnimales);
                break;
            case 5:
                borrarAnimales(animales, cantidadAnimales);
                cantidadAnimales = 0; //Reiniciamos el contador
                break;
            case 6:
                break;
            default:
                cout << "Opcion no valida\n";
        }

    } while (opcion != 6);
}


int main()
{
    gestionarAnimales();

    return 0;
}
