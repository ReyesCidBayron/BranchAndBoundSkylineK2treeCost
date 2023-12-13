#! /usr/bin/env bash
NOMBRE="CorrectitudTest"
CANTIDAD_PUNTOS=50000
RANGO=100000
VUELTAS=30
RUTA="automatic_test"

javac automatic_test/*.java

for ((I=0;I<$VUELTAS;I++));
do
	java automatic_test.GenM $CANTIDAD_PUNTOS $RANGO > $RUTA/$NOMBRE$I.txt
	echo "$NOMBRE$I.txt Listo"
	
done

for ((I=0;I<$VUELTAS;I++));
do
	./mainGenerateRbfull $RUTA/$NOMBRE$I 0
	echo "$NOMBRE$I.rbfull Listo"
done

for ((I=0;I<$VUELTAS;I++));
do
	
	./mainGenerateKt $RUTA/$NOMBRE$I
	echo "$NOMBRE$I.kt Listo"
done

