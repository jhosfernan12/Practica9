from abc import ABC, abstractmethod

class Animal(ABC):
    def __init__(self, especie):
        self.especie = especie

    @abstractmethod
    def comer(self):
        pass

    @abstractmethod
    def dormir(self):
        pass

    @abstractmethod
    def moverse(self):
        pass

class Mamifero(Animal):
    def __init__(self, especie):
        super().__init__(especie)

    def Comer(self):
        print(f"El Mamifero {self.especie} come")

    def Dormir(self):
        print(f"El Mamifero {self.especie} duerme")

    def Moverse(self):
        print(f"El Mamifero {self.especie} se mueve")

class Ave(Animal):
    def __init__(self, especie):
        super().__init__(especie)
        self.numeroalas = 2
        self.pico = 1

    def Comer(self):
        print(f"El Ave con {self.numeroalas} alas y pico, de especie {self.especie} come")

    def Dormir(self):
        print(f"El Ave con {self.numeroalas} alas y pico, de especie {self.especie} duerme")

    def Moverse(self):
        print(f"El Ave con {self.numeroalas} alas y pico, de especie {self.especie} se mueve")

class Reptil(Animal):
    def __init__(self, especie):
        super().__init__(especie)

    def Comer(self):
        print(f"El Reptil con escamas de especie {self.especie} come")

    def Dormir(self):
        print(f"El Reptil con escamas de especie {self.especie} duerme")

    def Moverse(self):
        print(f"El Reptil con escamas de especie {self.especie} se mueve")

def AgregarMamifero(animales):
    especie = input("Ingrese la especie: ")
    animales.append(Mamifero(especie))

def AgregarAve(animales):
    especie = input("Ingrese la especie: ")
    animales.append(Ave(especie))

def AgregarReptil(animales):
    especie = input("Ingrese la especie: ")
    animales.append(Reptil(especie))

def HayAnimalesAgregados(animales):
    return len(animales) > 0

def mostrarInformacion(animales):
    if not HayAnimalesAgregados(animales):
        print("Todavia no hay animales agregados")
    else:
        for i, animal in enumerate(animales):
            print(f"Informacion del animal {i + 1}:")
            animal.Comer()
            animal.Dormir()
            animal.Moverse()

def BorrarAnimales(animales):
    if HayAnimalesAgregados(animales):
        animales.clear()
        print("Animales Borrados Exitosamente")
    else:
        print("No hay todavia animales agregados")

def GestionarAnimales():
    animales = []
    while True:
        print("\nMenu de opciones:")
        print("1) Agregar Mamifero")
        print("2) Agregar Ave")
        print("3) Agregar Reptil")
        print("4) Mostrar informacion de todos los animales")
        print("5) Borrar Animales")
        print("6) Salir")
        opcion = int(input("Seleccione una opcion: "))

        if opcion == 1:
            AgregarMamifero(animales)
        elif opcion == 2:
            AgregarAve(animales)
        elif opcion == 3:
            AgregarReptil(animales)
        elif opcion == 4:
            mostrarInformacion(animales)
        elif opcion == 5:
            BorrarAnimales(animales)
        elif opcion == 6:
            break
        else:
            print("Opcion no valida")

GestionarAnimales()
