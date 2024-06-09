from abc import ABC, abstractmethod

class Producto(ABC):
    def __init__(self, nombre, precio, cantidad):
        self.nombre = nombre
        self.precio = precio
        self.cantidad = cantidad

    @abstractmethod
    def calcular_total(self):
        pass

    @abstractmethod
    def aplicar_descuento(self, porcentaje):
        pass

    @abstractmethod
    def mostrar_informacion(self):
        pass

class Electronico(Producto):
    def __init__(self, nombre, precio, cantidad, garantia):
        super().__init__(nombre, precio, cantidad)
        self.garantia = garantia

    def mostrar_informacion(self):
        print(f"Nombre: {self.nombre}, Precio: {self.precio}, Cantidad: {self.cantidad}, Garantía: {self.garantia} meses")

    @property
    def calcular_total(self):
        return self.precio * self.cantidad

    def aplicar_descuento(self, porcentaje):
        self.precio -= self.precio * porcentaje / 100

class Ropa(Producto):
    def __init__(self, nombre, precio, cantidad, talla):
        super().__init__(nombre, precio, cantidad)
        self.talla = talla

    def mostrar_informacion(self):
        print(f"Nombre: {self.nombre}, Precio: {self.precio}, Cantidad: {self.cantidad}, Talla: {self.talla}")

    @property
    def calcular_total(self):
        return self.precio * self.cantidad

    def aplicar_descuento(self, porcentaje):
        self.precio -= self.precio * porcentaje / 100

class Alimento(Producto):
    def __init__(self, nombre, precio, cantidad, fecha_expiracion):
        super().__init__(nombre, precio, cantidad)
        self.fecha_expiracion = fecha_expiracion

    def mostrar_informacion(self):
        print(f"Nombre: {self.nombre}, Precio: {self.precio}, Cantidad: {self.cantidad}, Fecha de Expiración: {self.fecha_expiracion}")

    @property
    def calcular_total(self):
        return self.precio * self.cantidad

    def aplicar_descuento(self, porcentaje):
        self.precio -= self.precio * porcentaje / 100

def calcular_valor_inventario(inventario):
    valor_total = sum(producto.calcular_total for producto in inventario)
    return valor_total

def aplicar_descuento_inventario(inventario, porcentaje):
    for producto in inventario:
        producto.aplicar_descuento(porcentaje)

inventario = [
    Electronico("Laptop", 1000, 10, 12),
    Ropa("Camiseta", 20, 50, "M"),
    Alimento("Manzanas", 1, 100, "2024-12-31")
]

print("Inventario Inicial:")
for producto in inventario:
    producto.mostrar_informacion()
print()

valor_total = calcular_valor_inventario(inventario)
print(f"Valor total del inventario: S/{valor_total}")

print("Aplicando un descuento del 10% a todo el inventario...")
aplicar_descuento_inventario(inventario, 10)

print("Inventario después de aplicar el descuento:")
for producto in inventario:
    producto.mostrar_informacion()
print()

valor_total = calcular_valor_inventario(inventario)
print(f"Valor total del inventario después del descuento: S/{valor_total}")
