#! /usr/bin/env bash
ID_INICIAL=1
ID_FINAL=10
EXPERIMENTOS_POR_ID=10
NOMBRE_UN="inputUn"
NOMBRE_CL="inputCl"
RUTA="automatic_test"
CRECIMIENTO=100000
RANGO=10000000

javac automatic_test/*.java

echo "GENERACION DE LA ENTRADA POR PUNTOS"
echo "==================================="

#100.000 a 1.000.000

for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_UN-$ID-$E
		CANTIDAD=$((ID*CRECIMIENTO))
		java automatic_test.GenM $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
		echo "$NOMBRE.txt Listo  "
	done
done

for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_CL-$ID-$E
		CANTIDAD=$((ID*CRECIMIENTO))
		java automatic_test.GenG $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
		echo "$NOMBRE.txt Listo  "

	done
done

#2.000.000
ID=11
CANTIDAD=2000000
for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
do
	NOMBRE=$NOMBRE_UN-$ID-$E
	java automatic_test.GenM $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
	echo "$NOMBRE.txt Listo  "

done
for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
do
	NOMBRE=$NOMBRE_CL-$ID-$E
	java automatic_test.GenG $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
	echo "$NOMBRE.txt Listo  "

done

#5.000.000
ID=12
CANTIDAD=5000000
for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
do
	NOMBRE=$NOMBRE_UN-$ID-$E
	java automatic_test.GenM $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
	echo "$NOMBRE.txt Listo "
done
for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
do
	NOMBRE=$NOMBRE_CL-$ID-$E
	java automatic_test.GenG $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
	echo "$NOMBRE.txt Listo  "
done

#10.000.000
ID=13
CANTIDAD=10000000
for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
do
	NOMBRE=$NOMBRE_UN-$ID-$E
	java automatic_test.GenM $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
	echo "$NOMBRE.txt Listo  "
	./mainGenerateRbfull $RUTA/$NOMBRE 0
done
for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
do
	NOMBRE=$NOMBRE_CL-$ID-$E
	java automatic_test.GenG $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
	echo "$NOMBRE.txt Listo  "
done

#50.000.000
ID=14
CANTIDAD=50000000
for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
do
	NOMBRE=$NOMBRE_UN-$ID-$E
	java automatic_test.GenM $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
	echo "$NOMBRE.txt Listo  "
done
for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
do
	NOMBRE=$NOMBRE_CL-$ID-$E
	java automatic_test.GenG $CANTIDAD $RANGO > $RUTA/$NOMBRE.txt
	echo "$NOMBRE.txt Listo  "
done


