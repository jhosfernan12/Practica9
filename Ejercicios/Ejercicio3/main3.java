import java.util.Scanner;

abstract class Empleado 
{
    String nombre;
    int edad;

    Empleado(String nombre, int edad) 
    {
        this.nombre = nombre;
        this.edad = edad;
    }

    abstract double calcularSalario();
}

class Asalariado extends Empleado 
{
    private int salario;

    Asalariado(String nombre, int edad, int salario) 
    {
        super(nombre, edad);
        this.salario = salario;
    }

    @Override
    double calcularSalario() 
    {
        return salario;
    }
}

class PorHora extends Empleado 
{
    private int horas;
    private double dineroPorHora;

    PorHora(String nombre, int edad, int horas, double dineroPorHora) 
    {
        super(nombre, edad);
        this.horas = horas;
        this.dineroPorHora = dineroPorHora;
    }

    @Override
    double calcularSalario() 
    {
        return horas * dineroPorHora;
    }
}

class Comisionista extends Empleado 
{
    private int trabajo;
    private float comision;

    Comisionista(String nombre, int edad, float comision, int trabajo) 
    {
        super(nombre, edad);
        this.comision = comision;
        this.trabajo = trabajo;
    }

    @Override
    double calcularSalario() 
    {
        return trabajo * comision;
    }
}

public class main3 
{
    public static void agregarAsalariado(Empleado[] empleados, Scanner scanner, int indice) 
    {
        System.out.println("Ingrese el Nombre:");
        String nombre = scanner.next();
        System.out.println("Ingrese la Edad:");
        int edad = scanner.nextInt();
        System.out.println("Ingrese el Salario:");
        int salario = scanner.nextInt();
        empleados[indice++] = new Asalariado(nombre, edad, salario);
    }

    public static void agregarPorHora(Empleado[] empleados, Scanner scanner, int indice) 
    {
        System.out.println("Ingrese el Nombre:");
        String nombre = scanner.next();
        System.out.println("Ingrese la Edad:");
        int edad = scanner.nextInt();
        System.out.println("Ingrese las horas trabajadas:");
        int horas = scanner.nextInt();
        System.out.println("Ingrese la Tarifa de dinero por hora:");
        double dineroPorHora = scanner.nextDouble();
        empleados[indice++] = new PorHora(nombre, edad, horas, dineroPorHora);
    }

    public static void agregarComisionista(Empleado[] empleados, Scanner scanner, int indice) 
    {
        System.out.println("Ingrese el Nombre:");
        String nombre = scanner.next();
        System.out.println("Ingrese la Edad:");
        int edad = scanner.nextInt();
        System.out.println("Ingrese la Meta de trabajo:");
        int trabajo = scanner.nextInt();
        System.out.println("Ingrese la Comision:");
        float comision = scanner.nextFloat();
        empleados[indice++] = new Comisionista(nombre, edad, comision, trabajo);
    }

    public static boolean hayEmpleadosAgregados(Empleado[] empleados) 
    {
        for (Empleado empleado : empleados) 
        {
            if (empleado != null) 
            {
                return true;
            }
        }
        return false;
    }

    public static void mostrarInformacion(Empleado[] empleados) 
    {
        if (!hayEmpleadosAgregados(empleados)) 
        {
            System.out.println("Todavía no hay empleados registrados");
        } 
        else 
        {
            for (Empleado empleado : empleados) 
            {
                if (empleado != null) 
                {
                    System.out.println("Información del Empleado:");
                    System.out.println("Nombre: " + empleado.nombre);
                    System.out.println("Edad: " + empleado.edad);
                    System.out.println("Salario: " + empleado.calcularSalario());
                }
            }
        }
    }

    public static void borrarEmpleados(Empleado[] empleados) 
    {
        for (int i = 0; i < empleados.length; i++) 
        {
            empleados[i] = null;
        }
        System.out.println("Empleados Borrados Exitosamente");
    }

    public static void gestionarEmpleados() 
    {
        Scanner scanner = new Scanner(System.in);
        Empleado[] empleados = new Empleado[100];
        int cantidadEmpleados = 0;
        int opcion;

        do 
        {
            System.out.println("\nMenu de opciones:");
            System.out.println("1) Agregar Asalariado");
            System.out.println("2) Agregar PorHora");
            System.out.println("3) Agregar Comisionista");
            System.out.println("4) Mostrar informacion de todos los empleados");
            System.out.println("5) Borrar Empleados");
            System.out.println("6) Salir");
            System.out.print("Seleccione una opcion: ");
            opcion = scanner.nextInt();

            switch (opcion)
             {
                case 1:
                    agregarAsalariado(empleados, scanner, cantidadEmpleados);
                    cantidadEmpleados++;
                    break;
                case 2:
                    agregarPorHora(empleados, scanner, cantidadEmpleados);
                    cantidadEmpleados++;
                    break;
                case 3:
                    agregarComisionista(empleados, scanner, cantidadEmpleados);
                    cantidadEmpleados++;
                    break;
                case 4:
                    mostrarInformacion(empleados);
                    break;
                case 5:
                    borrarEmpleados(empleados);
                    cantidadEmpleados = 0; // Reiniciamos el contador
                    break;
                case 6:
                    borrarEmpleados(empleados); 
                    break;
                default:
                    System.out.println("Opcion no valida");
            }

        } while (opcion != 6);
    }

    public static void main(String[] args) 
    {
        gestionarEmpleados();
    }
}
