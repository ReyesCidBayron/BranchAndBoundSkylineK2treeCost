package automatic_test;

import java.util.*;
import java.io.*;


public class GenM
{
	public static void main(String[] args)
	{
		if (args.length != 2)
		{
			System.err.println("Usage: Generator number_of_data");
			System.exit(-1);
		}

		Random rand = new Random();

		long numberOfObjects = new Long(args[0]).longValue();
		 
		long rango = new Long(args[1]).longValue();
		
		if(rango * rango < numberOfObjects){
			System.err.println("No se pueden generar la cantidad de puntos solicitados\n");
			System.err.println(numberOfObjects + " puntos en una matriz de " + rango +" x " +rango + "= " + rango * rango);
			System.exit(-1);
		}
		
		Map<Long, Punto> puntos = new HashMap<Long, Punto>();
		long i = 0;
		while(i < numberOfObjects){
			long x =  (long) (rand.nextDouble() * rango); 
			long y =  (long) (rand.nextDouble() * rango);
			
			Punto p = new Punto(x, y);
			long clave = Integer.MAX_VALUE * y + x;
			
			if(!puntos.containsKey(clave)){
				puntos.put(clave, p);
				System.out.println(x + " " + y);
				i++;
			}
			
		}

    }


}
