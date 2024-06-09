import math
from abc import ABC, abstractmethod

class Forma(ABC):
    @abstractmethod
    def calcular_area(self):
        pass

    @abstractmethod
    def calcular_perimetro(self):
        pass

    @abstractmethod
    def mostrar_informacion(self):
        pass
    
class Circulo(Forma):
    def __init__(self, radio):
        self.radio = radio

    def calcular_area(self):
        return math.pi * self.radio * self.radio

    def calcular_perimetro(self):
        return 2 * math.pi * self.radio

    def mostrar_informacion(self):
        print(f"Circulo: radio = {self.radio}, area = {self.calcular_area()}, perimetro = {self.calcular_perimetro()}")

class Rectangulo(Forma):
    def __init__(self, ancho, alto):
        self.ancho = ancho
        self.alto = alto

    def calcular_area(self):
        return self.ancho * self.alto

    def calcular_perimetro(self):
        return 2 * (self.ancho + self.alto)

    def mostrar_informacion(self):
        print(f"Rectangulo: ancho = {self.ancho}, alto = {self.alto}, area = {self.calcular_area()}, perimetro = {self.calcular_perimetro()}")

class Triangulo(Forma):
    def __init__(self, base, altura):
        self.base = base
        self.altura = altura

    def CalcularArea(self):
        return 0.5 * self.base * self.altura

    def CalcularPerimetro(self):
        return 3 * self.base

    def MostrarInformacion(self):
        print(f"Triangulo: base = {self.base}, altura = {self.altura}, area = {self.calcular_area()}, perimetro = {self.calcular_perimetro()}")

def AgregarCirculo(formas):
    radio = float(input("Ingrese el radio del circulo: "))
    formas.append(Circulo(radio))

def AgregarRectangulo(formas):
    ancho = float(input("Ingrese el ancho del rectangulo: "))
    alto = float(input("Ingrese el alto del rectangulo: "))
    formas.append(Rectangulo(ancho, alto))

def AgregarTriangulo(formas):
    base = float(input("Ingrese la base del triangulo: "))
    altura = float(input("Ingrese la altura del triangulo: "))
    formas.append(Triangulo(base, altura))

def hayFormasAgregadas(formas):
    return len(formas) > 0

def MostrarInformacion(formas):
    if not hayFormasAgregadas(formas):
        print("Todavia no hay formas agregadas")
    else:
        for forma in formas:
            forma.mostrarInformacion()

def BorrarFormas(formas):
    if hayFormasAgregadas(formas):
        formas.clear()
        print("Formas Borradas Exitosamente")
    else:
        print("No hay todavia Formas agregadas")

def GestionarFormas():
    formas = []
    while True:
        print("\nMenu de opciones:")
        print("1) Agregar circulo")
        print("2) Agregar rectangulo")
        print("3) Agregar triangulo")
        print("4) Mostrar informacion de todas las formas")
        print("5) Borrar Formas")
        print("6) Salir")
        opcion = int(input("Seleccione una opcion: "))

        if opcion == 1:
            AgregarCirculo(formas)
        elif opcion == 2:
            AgregarRectangulo(formas)
        elif opcion == 3:
            AgregarTriangulo(formas)
        elif opcion == 4:
            MostrarInformacion(formas)
        elif opcion == 5:
            BorrarFormas(formas)
        elif opcion == 6:
            break
        else:
            print("Opcion no valida")


GestionarFormas()
