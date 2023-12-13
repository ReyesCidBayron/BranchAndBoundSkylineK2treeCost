package libs;

import java.util.*;
import java.io.*;

public class GenMix
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
		
		int bolas = 2 + (int) (rand.nextDouble() * 8);
		
		long x_centro = 0;
		
		long i = 0;		
		while(i < numberOfObjects){
			if(i % (numberOfObjects / bolas) == 0){
				x_centro =  (long) (rand.nextDouble() * rango); 
			}
			
			long x = x_centro + (long) (rand.nextGaussian() * (rango / 10)); 
			long y = (long) (rand.nextDouble() * rango);
			
			if(x >= 0 && y >= 0 && x < rango && y < rango){
				
				Punto p = new Punto(x, y);
				long clave = Integer.MAX_VALUE * y + x;
				
				if(!puntos.containsKey(clave)){
					puntos.put(clave, p);
					if(i != 0)	System.out.println();
					System.out.print(x + " " + y);
					i++;
				}
				
			}
		}
		
    }


}

