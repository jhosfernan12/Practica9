#include <iostream>
#include <string>

using namespace std;

class Personaje 
{
    public:
        Personaje(const string& nombre, int vida) : nombre(nombre), vida(vida) {}

        virtual void atacar() = 0;
        virtual void defender() = 0;
        virtual void usarHabilidadEspecial() = 0;
        virtual ~Personaje() = default;


        string getNombre() const 
        { 
            return nombre; 
        }
        int getVida() const 
        { 
            return vida; 
        }
        void setVida(int nuevaVida) 
        { 
            vida = nuevaVida; 
        }

    protected:
        string nombre;
        int vida;
};

class Guerrero : public Personaje 
{
public:
    Guerrero(const string& nombre, int vida) : Personaje(nombre, vida) {}

    void atacar() override 
    {
        cout << nombre << " Ataca con su espada" << endl;
    }

    void defender() override 
    {
        cout << nombre << " Bloquea el ataque con su escudo" << endl;
    }

    void usarHabilidadEspecial() override
     {
        cout << nombre << " usa Furia Poderosa " << endl;
    }
};

class Mago : public Personaje 
{
public:
    Mago(const string& nombre, int vida) : Personaje(nombre, vida) {}

    void atacar() override 
    {
        cout << nombre << " lanza un hechizo de Fuego" << endl;
    }

    void defender() override
     {
        cout << nombre << " crea un escudo magico" << endl;
    }

    void usarHabilidadEspecial() override 
    {
        cout << nombre << " usa Bola de Fuego" << endl;
    }
};

class Arquero : public Personaje 
{
public:
    Arquero(const string& nombre, int vida) : Personaje(nombre, vida) {}

    void atacar() override 
    {
        cout << nombre << " dispara una flecha" << endl;
    }

    void defender() override 
    {
        cout << nombre << " esquiva el ataque" << endl;
    }

    void usarHabilidadEspecial() override 
    {
        cout << nombre << " usa Lluvia de Flechas" << endl;
    }
};

int main() 
{
    const int numPersonajes = 3;
    Personaje* personajes[numPersonajes];

    personajes[0] = new Guerrero("Artas", 100);
    personajes[1] = new Mago("Merlin", 80);
    personajes[2] = new Arquero("Legolas", 90);

    for (int i = 0; i < numPersonajes; ++i) 
    {
        personajes[i]->atacar();
        personajes[i]->defender();
        personajes[i]->usarHabilidadEspecial();
        cout << endl;
    }


    for (int i = 0; i < numPersonajes; ++i) //Liberamos la memoria
     {
        delete personajes[i];
    }

    return 0;
}
