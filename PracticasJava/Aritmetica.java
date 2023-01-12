package PracticasJava;
import java.util.*;

public class Aritmetica {
    public static void main(String[] args)
    {
        operacionesAritmeticas();
    }

    private static void operacionesAritmeticas()
    {
        Scanner entradaTeclado = new Scanner(System.in);
        String datosDeEntrada;
        System.out.println("Si quieres terminar la aplicacion ingrese exit");
        while(true)
        {
            datosDeEntrada = entradaTeclado.nextLine();
            if(datosDeEntrada.contains("exit")) break;
            procesarDatos(datosDeEntrada);
        }
        entradaTeclado.close();
    }

    private static void procesarDatos(String datosDeEntrada)
    {
        if(!datosDeEntrada.isEmpty())
        {
            String[] argumentos = datosDeEntrada.split(" ");
            System.out.println("= " + realizaOperacion(argumentos));
        } else {
            System.out.println("Ingresa datos validos");
        }
    }

    private static float realizaOperacion(String[] argumentos)
    {
        float numero1, numero2;
        try
        {
            numero1 = Float.parseFloat(argumentos[0]); 
            numero2 = Float.parseFloat(argumentos[2]);
        } catch(Exception e) {
            System.out.println(e);
            return 0;
        }
        if(argumentos[1].equals("+"))
        {
            return numero1 + numero2;
        } else if(argumentos[1].equals("-"))
        {
            return numero1 - numero2;
        } else if(argumentos[1].equals("*"))
        {
            return numero1 * numero2;
        } else if(argumentos[1].equals("/"))
        {
            if(numero2 == 0) return 0;
            return numero1 / numero2;
        } else {
            return 0;
        }
    }
}
