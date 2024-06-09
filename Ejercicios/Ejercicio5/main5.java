class Producto {
    protected String nombre;
    protected double precio;
    protected int cantidad;

    public Producto(String nombre, double precio, int cantidad) 
    {
        this.nombre = nombre;
        this.precio = precio;
        this.cantidad = cantidad;
    }

    public double calcularValorTotal() 
    {
        return precio * cantidad;
    }

    public void aplicarDescuento(double porcentaje) 
    {
        precio -= precio * porcentaje / 100;

    }
    public void mostrarInformacion() 
    {
        System.out.println("Nombre: " + nombre + ", Precio: " + precio + ", Cantidad: " + cantidad);
    }
}

class Electronico extends Producto 
{
    private int garantia;

    public Electronico(String nombre, double precio, int cantidad, int garantia) 
    {
        super(nombre, precio, cantidad);
        this.garantia = garantia;
    }

    @Override
    public void mostrarInformacion()
     {
        super.mostrarInformacion();
        System.out.println(", Garantia: " + garantia + " meses");
    }
}

class Ropa extends Producto 
{
    private String talla;

    public Ropa(String nombre, double precio, int cantidad, String talla) {
        super(nombre, precio, cantidad);
        this.talla = talla;
    }

    @Override
    public void mostrarInformacion() 
    {
        super.mostrarInformacion();
        System.out.println(", Talla: " + talla);
    }
}

class Alimento extends Producto 
{
    private String fechaExpiracion;

    public Alimento(String nombre, double precio, int cantidad, String fechaExpiracion) {
        super(nombre, precio, cantidad);
        this.fechaExpiracion = fechaExpiracion;
    }

    @Override
    public void mostrarInformacion() 
    {
        super.mostrarInformacion();
        System.out.println(", Fecha de Expiracion: " + fechaExpiracion);
    }
}

public class main5
 {
    public static double calcularValorInventario(Producto[] inventario) 
    {
        double valorTotal = 0.0;
        for (Producto producto : inventario)
        {
            valorTotal += producto.calcularValorTotal();
        }
        return valorTotal;
    }

    public static void aplicarDescuentoInventario(Producto[] inventario, double porcentaje) 
    {
        for (Producto producto : inventario)
        {
            producto.aplicarDescuento(porcentaje);
        }
    }

    public static void main(String[] args) 
    {
        final int tamanoInventario = 3;
        Producto[] inventario = new Producto[tamanoInventario];

        inventario[0] = new Electronico("Laptop", 1000, 10, 12);
        inventario[1] = new Ropa("Camiseta", 20, 50, "M");
        inventario[2] = new Alimento("Manzanas", 1, 100, "2024-12-31");

        System.out.println("Inventario Inicial:");
        for (Producto producto : inventario) 
        {
            producto.mostrarInformacion();
        }
        System.out.println();

        double valorTotal = calcularValorInventario(inventario);
        System.out.println("Valor total del inventario: S/" + valorTotal);

        System.out.println("Aplicando un descuento del 10% a todo el inventario...");
        aplicarDescuentoInventario(inventario, 10);

        System.out.println("Inventario después de aplicar el descuento:");
        for (Producto producto : inventario) 
        {
            producto.mostrarInformacion();
        }
        System.out.println();
    }
}
