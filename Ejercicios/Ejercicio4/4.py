from abc import ABC, abstractmethod

class Personaje(ABC):
    def __init__(self, nombre, vida):
        self.nombre = nombre
        self.vida = vida

    @abstractmethod
    def atacar(self):
        pass

    @abstractmethod
    def defender(self):
        pass

    @abstractmethod
    def usar_habilidad_especial(self):
        pass

    def get_nombre(self):
        return self.nombre

    def get_vida(self):
        return self.vida

    def set_vida(self, nueva_vida):
        self.vida = nueva_vida

class Guerrero(Personaje):
    def atacar(self):
        print(f"{self.nombre} ataca con su espada")

    def defender(self):
        print(f"{self.nombre} bloquea el ataque con su escudo")

    def usar_habilidad_especial(self):
        print(f"{self.nombre} usa Furia Poderosa")

class Mago(Personaje):
    def atacar(self):
        print(f"{self.nombre} lanza un hechizo de Fuego")

    def defender(self):
        print(f"{self.nombre} crea un escudo mágico")

    def usar_habilidad_especial(self):
        print(f"{self.nombre} usa Bola de Fuego")

class Arquero(Personaje):
    def atacar(self):
        print(f"{self.nombre} dispara una flecha")

    def defender(self):
        print(f"{self.nombre} esquiva el ataque")

    def usar_habilidad_especial(self):
        print(f"{self.nombre} usa Lluvia de Flechas")

def main():
    personajes = [
        Guerrero("Artas", 100),
        Mago("Merlin", 80),
        Arquero("Legolas", 90)
    ]

    for personaje in personajes:
        personaje.atacar()
        personaje.defender()
        personaje.usar_habilidad_especial()
        print()

if __name__ == "__main__":
    main()
