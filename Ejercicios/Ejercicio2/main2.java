import java.util.Scanner;

abstract class Animal 
{
    protected String especie;

    public Animal(String especie)
     {
        this.especie = especie;
    }

    public abstract void Comer();
    public abstract void Dormir();
    public abstract void Moverse();
}

class Mamifero extends Animal 
{
    public Mamifero(String especie) 
    {
        super(especie);
    }

    @Override
    public void Comer()
     {
        System.out.println("El Mamifero " + especie + " come");
    }

    @Override
    public void Dormir()
     {
        System.out.println("El Mamifero " + especie + " duerme");
    }

    @Override
    public void Moverse() 
    {
        System.out.println("El Mamifero " + especie + " se mueve");
    }
}

class Ave extends Animal 
{
    private final int numeroalas = 2;
    private final int pico = 1;

    public Ave(String especie) 
    {
        super(especie);
    }

    @Override
    public void Comer() 
    {
        System.out.println("El Ave con " + numeroalas + " alas y pico, de especie " + especie + " come");
    }

    @Override
    public void Dormir() 
    {
        System.out.println("El Ave con " + numeroalas + " alas y pico, de especie " + especie + " duerme");
    }

    @Override
    public void Moverse() 
    {
        System.out.println("El Ave con " + numeroalas + " alas y pico, de especie " + especie + " se mueve");
    }
}

class Reptil extends Animal 
{
    public Reptil(String especie) {
        super(especie);
    }

    @Override
    public void Comer() 
    {
        System.out.println("El Reptil con escamas de especie " + especie + " come");
    }

    @Override
    public void Dormir() 
    {
        System.out.println("El Reptil con escamas de especie " + especie + " duerme");
    }

    @Override
    public void Moverse() 
    {
        System.out.println("El Reptil con escamas de especie " + especie + " se mueve");
    }
}

public class main2 
{
    private static void agregarMamifero(Animal[] animales, int[] indice)
     {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese la especie: ");
        String especie = scanner.nextLine();
        animales[indice[0]++] = new Mamifero(especie);
    }

    private static void agregarAve(Animal[] animales, int[] indice) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese la especie: ");
        String especie = scanner.nextLine();
        animales[indice[0]++] = new Ave(especie);
    }

    private static void agregarReptil(Animal[] animales, int[] indice)
     {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese la especie: ");
        String especie = scanner.nextLine();
        animales[indice[0]++] = new Reptil(especie);
    }

    private static boolean hayAnimalesAgregados(Animal[] animales, int cantidad) 
    {
        for (int i = 0; i < cantidad; i++) 
        {
            if (animales[i] != null) 
            {
                return true;
            }
        }
        return false;
    }

    private static void mostrarInformacion(Animal[] animales, int cantidad) 
    {
        if (!hayAnimalesAgregados(animales, cantidad)) 
        {
            System.out.println("Todavia no hay animales agregados");
        } else 
        {
            for (int i = 0; i < cantidad; i++) 
            {
                if (animales[i] != null) 
                {
                    System.out.println("Informacion del animal " + (i + 1) + ":");
                    animales[i].Comer();
                    animales[i].Dormir();
                    animales[i].Moverse();
                }
            }
        }
    }

    private static void borrarAnimales(Animal[] animales, int cantidad)
    {
        if (hayAnimalesAgregados(animales, cantidad)) {
            for (int i = 0; i < cantidad; i++) 
            {
                animales[i] = null;
            }
            System.out.println("Animales Borrados Exitosamente");
        } else {
            System.out.println("No hay todavia animales agregados");
        }
    }

    private static void gestionarAnimales() 
    {
        Animal[] animales = new Animal[100];
        int[] cantidadAnimales = {0};
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do
         {
            System.out.println("\nMenu de opciones:");
            System.out.println("1) Agregar Mamifero");
            System.out.println("2) Agregar Ave");
            System.out.println("3) Agregar Reptil");
            System.out.println("4) Mostrar informacion de todos los animales");
            System.out.println("5) Borrar Animales");
            System.out.println("6) Salir");
            System.out.print("Seleccione una opcion: ");
            opcion = scanner.nextInt();
            scanner.nextLine();

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
                    mostrarInformacion(animales, cantidadAnimales[0]);
                    break;
                case 5:
                    borrarAnimales(animales, cantidadAnimales[0]);
                    cantidadAnimales[0] = 0;
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
        gestionarAnimales();
    }
}
