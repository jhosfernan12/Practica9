import java.util.Scanner;

abstract class Forma 
{
    public abstract double calcularArea();
    public abstract double calcularPerimetro();
    public abstract void mostrarInformacion();
}

class Circulo extends Forma 
{
    private double radio;

    public Circulo(double radio) 
    {
        this.radio = radio;
    }

    @Override
    public double calcularArea() 
    {
        return Math.PI * radio * radio;
    }

    @Override
    public double calcularPerimetro() 
    {
        return 2 * Math.PI * radio;
    }

    @Override
    public void mostrarInformacion() 
    {
        System.out.println("Circulo: radio = " + radio + ", area = " + calcularArea() + ", perimetro = " + calcularPerimetro());
    }
}

class Rectangulo extends Forma 
{
    private double ancho, alto;

    public Rectangulo(double ancho, double alto) 
    {
        this.ancho = ancho;
        this.alto = alto;
    }

    @Override
    public double calcularArea() 
    {
        return ancho * alto;
    }

    @Override
    public double calcularPerimetro() 
    {
        return 2 * (ancho + alto);
    }

    @Override
    public void mostrarInformacion() 
    {
        System.out.println("Rectangulo: ancho = " + ancho + ", alto = " + alto + ", area = " + calcularArea() + ", perimetro = " + calcularPerimetro());
    }
}

class Triangulo extends Forma 
{
    private double base, altura;

    public Triangulo(double base, double altura) 
    {
        this.base = base;
        this.altura = altura;
    }

    @Override
    public double calcularArea() 
    {
        return 0.5 * base * altura;
    }

    @Override
    public double calcularPerimetro()
     {
        return 3 * base;
    }

    @Override
    public void mostrarInformacion() 
    {
        System.out.println("Triangulo: base = " + base + ", altura = " + altura + ", area = " + calcularArea() + ", perimetro = " + calcularPerimetro());
    }
}

public class main1
{
    private static void agregarCirculo(Forma[] formas, int[] indice) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese el radio del circulo: ");
        double radio = scanner.nextDouble();
        formas[indice[0]++] = new Circulo(radio);
    }

    private static void agregarRectangulo(Forma[] formas, int[] indice) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese el ancho y el alto del rectangulo: ");
        double ancho = scanner.nextDouble();
        double alto = scanner.nextDouble();
        formas[indice[0]++] = new Rectangulo(ancho, alto);
    }

    private static void agregarTriangulo(Forma[] formas, int[] indice) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese la base y la altura del triangulo: ");
        double base = scanner.nextDouble();
        double altura = scanner.nextDouble();
        formas[indice[0]++] = new Triangulo(base, altura);
    }

    private static boolean hayFormasAgregadas(Forma[] formas, int cantidad)
     {
        for (int i = 0; i < cantidad; i++) 
        {
            if (formas[i] != null) 
            {
                return true;
            }
        }
        return false;
    }

    private static void mostrarInformacion(Forma[] formas, int cantidad)
     {
        if (!hayFormasAgregadas(formas, cantidad)) 
        {
            System.out.println("Todavia no hay formas agregadas");
        } 
        else 
        {
            for (int i = 0; i < cantidad; i++) 
            {
                formas[i].mostrarInformacion();
            }
        }
    }

    private static void borrarFormas(Forma[] formas, int cantidad)
     {
        if (hayFormasAgregadas(formas, cantidad)) 
        {
            for (int i = 0; i < cantidad; i++) 
            {
                formas[i] = null;
            }
            System.out.println("Formas Borradas Exitosamente");
        } 
        else 
        {
            System.out.println("No hay todavia Formas agregadas");
        }
    }

    private static void gestionarFormas() 
    {
        Forma[] formas = new Forma[100];
        int[] cantidadFormas = {0};
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do
         {
            System.out.println("\nMenu de opciones:");
            System.out.println("1) Agregar circulo");
            System.out.println("2) Agregar rectangulo");
            System.out.println("3) Agregar triangulo");
            System.out.println("4) Mostrar informacion de todas las formas");
            System.out.println("5) Borrar Formas");
            System.out.println("6) Salir");
            System.out.print("Seleccione una opcion: ");
            opcion = scanner.nextInt();

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
                    mostrarInformacion(formas, cantidadFormas[0]);
                    break;
                case 5:
                    borrarFormas(formas, cantidadFormas[0]);
                    cantidadFormas[0] = 0;
                    break;
                case 6:
                    break;
                default:
                    System.out.println("Opcion no valida");
            }

        } while (opcion != 6);
    }

    public static void main(String[] args) 
    {
        gestionarFormas();
    }
}
