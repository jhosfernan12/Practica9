from abc import ABC, abstractmethod

class Empleado(ABC):
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    @abstractmethod
    def calcular_salario(self):
        pass

class Asalariado(Empleado):
    def __init__(self, nombre, edad, salario):
        super().__init__(nombre, edad)
        self.salario = salario

    def calcular_salario(self):
        return self.salario

class PorHora(Empleado):
    def __init__(self, nombre, edad, horas, dinero_por_hora):
        super().__init__(nombre, edad)
        self.horas = horas
        self.dinero_por_hora = dinero_por_hora

    def calcular_salario(self):
        return self.horas * self.dinero_por_hora

class Comisionista(Empleado):
    def __init__(self, nombre, edad, comision, trabajo):
        super().__init__(nombre, edad)
        self.comision = comision
        self.trabajo = trabajo

    def calcular_salario(self):
        return self.trabajo * self.comision

def AgregarAsalariado(empleados, indice):
    nombre = input("Ingrese el Nombre: ")
    edad = int(input("Ingrese la Edad: "))
    salario = int(input("Ingrese el Salario: "))
    empleados.append(Asalariado(nombre, edad, salario))

def AgregarPorHora(empleados, indice):
    nombre = input("Ingrese el Nombre: ")
    edad = int(input("Ingrese la Edad: "))
    horas = int(input("Ingrese las horas trabajadas: "))
    dineroxhora = float(input("Ingrese la Tarifa de dinero por hora: "))
    empleados.append(PorHora(nombre, edad, horas, dineroxhora))

def AgregarComisionista(empleados, indice):
    nombre = input("Ingrese el Nombre: ")
    edad = int(input("Ingrese la Edad: "))
    comision = float(input("Ingrese la Comision: "))
    trabajo = int(input("Ingrese la Meta de trabajo: "))
    empleados.append(Comisionista(nombre, edad, comision, trabajo))

def hayEmpleadosAgregados(empleados):
    return len(empleados) > 0

def mostrarInformacion(empleados):
    if not hayEmpleadosAgregados(empleados):
        print("Todavía no hay empleados registrados")
    else:
        for idx, empleado in enumerate(empleados, start=1):
            print(f"Información del Empleado {idx}:")
            print(f"Nombre: {empleado.nombre}")
            print(f"Edad: {empleado.edad}")
            print(f"Salario: {empleado.calcular_salario()}")

def BorrarEmpleados(empleados):
    if hayEmpleadosAgregados(empleados):
        empleados.clear()
        print("Empleados Borrados Exitosamente")
    else:
        print("No hay todavía empleados agregados")

def GestionarEmpleados():
    empleados = []
    while True:
        print("\nMenu de opciones:")
        print("1) Agregar Asalariado")
        print("2) Agregar Por Hora")
        print("3) Agregar Comisionista")
        print("4) Mostrar información de todos los empleados")
        print("5) Borrar Empleados")
        print("6) Salir")
        opcion = int(input("Seleccione una opción: "))

        if opcion == 1:
            AgregarAsalariado(empleados, len(empleados))
        elif opcion == 2:
            AgregarPorHora(empleados, len(empleados))
        elif opcion == 3:
            AgregarComisionista(empleados, len(empleados))
        elif opcion == 4:
            mostrarInformacion(empleados)
        elif opcion == 5:
            BorrarEmpleados(empleados)
        elif opcion == 6:
            break
        else:
            print("Opción no válida")

GestionarEmpleados()
