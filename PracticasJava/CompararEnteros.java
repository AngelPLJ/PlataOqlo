package PracticasJava;
import java.util.*;

public class CompararEnteros {
    public static void main(String[] args)
    {
        obtenerEnteros();
    }

    private static void obtenerEnteros()
    {
        Scanner entradaTeclado = new Scanner(System.in);
        String[] arregloDeEnteros = new String[100];
        String datosDeEntrada;
        int[] enteros = new int[100];
        int contador = 0;
        System.out.println("Ingrese los números que desee comparar separados por un espacio (solo acepta enteros)");
        datosDeEntrada = entradaTeclado.nextLine();
        arregloDeEnteros = datosDeEntrada.split(" ");
        for (String entero : arregloDeEnteros) {
            if(!entero.contains("."))
            {
                enteros[contador] = Integer.parseInt(entero);
                contador++;
            }
        }
        realizarComparacion(enteros, contador);
        entradaTeclado.close();
    }

    private static void realizarComparacion(int[] enteros, int contador)
    {
        int i, j;
        for(i = 0; i < contador; i++)
        {
            for(j = i+1; j < contador; j++)
            {
                if(enteros[i] == enteros[j]) System.out.println("enteros[" + i +"] = " +
                        enteros[i] + " es igual a: enteros[" + j + "] = " + enteros[j]);
            }
        }
    }
}
