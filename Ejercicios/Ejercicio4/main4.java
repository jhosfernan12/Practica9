import java.util.ArrayList;
import java.util.List;

abstract class Personaje 
{
    protected String nombre;
    protected int vida;

    public Personaje(String nombre, int vida) 
    {
        this.nombre = nombre;
        this.vida = vida;
    }

    public abstract void atacar();
    public abstract void defender();
    public abstract void usarHabilidadEspecial();

    public String getNombre() 
    {
        return nombre;
    }

    public int getVida() 
    {
        return vida;
    }

    public void setVida(int nuevaVida)
     {
        this.vida = nuevaVida;
    }
}

class Guerrero extends Personaje 
{
    public Guerrero(String nombre, int vida) 
    {
        super(nombre, vida);
    }

    @Override
    public void atacar()
     {
        System.out.println(nombre + " ataca con su espada");
    }

    @Override
    public void defender() 
    {
        System.out.println(nombre + " bloquea el ataque con su escudo");
    }

    @Override
    public void usarHabilidadEspecial() 
    {
        System.out.println(nombre + " usa Furia Poderosa");
    }
}

class Mago extends Personaje
 {
    public Mago(String nombre, int vida)
    {
        super(nombre, vida);
    }

    @Override
    public void atacar() 
    {
        System.out.println(nombre + " lanza un hechizo de Fuego");
    }

    @Override
    public void defender() 
    {
        System.out.println(nombre + " crea un escudo mágico");
    }

    @Override
    public void usarHabilidadEspecial() 
    {
        System.out.println(nombre + " usa Bola de Fuego");
    }
}

class Arquero extends Personaje
{
    public Arquero(String nombre, int vida) 
    {
        super(nombre, vida);
    }

    @Override
    public void atacar() 
    {
        System.out.println(nombre + " dispara una flecha");
    }

    @Override
    public void defender()
    {
        System.out.println(nombre + " esquiva el ataque");
    }

    @Override
    public void usarHabilidadEspecial()
    {
        System.out.println(nombre + " usa Lluvia de Flechas");
    }
}

public class main4 
{
    public static void main(String[] args) 
    {
        List<Personaje> personajes = new ArrayList<>();
        personajes.add(new Guerrero("Artas", 100));
        personajes.add(new Mago("Merlin", 80));
        personajes.add(new Arquero("Legolas", 90));

        for (Personaje personaje : personajes) 
        {
            personaje.atacar();
            personaje.defender();
            personaje.usarHabilidadEspecial();
            System.out.println();
        }
    }
}
