#! /usr/bin/env bash
ID_INICIAL=1
ID_FINAL=14
EXPERIMENTOS_POR_ID=10
NOMBRE_UN="inputUn"
NOMBRE_CL="inputCl"
RUTA="automatic_test"

echo "CONVERSION DE LA ENTRADA POR PUNTOS"
echo "==================================="


for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_UN-$ID-$E
		./mainGenerateRbfull $RUTA/$NOMBRE 0
		echo "$NOMBRE.rbfull Listo  "
		./mainGenerateKt $RUTA/$NOMBRE
		echo "$NOMBRE.kt Listo  "
	done
done

for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_CL-$ID-$E
		./mainGenerateRbfull $RUTA/$NOMBRE 0
		echo "$NOMBRE.rbfull Listo  "
		./mainGenerateKt $RUTA/$NOMBRE
		echo "$NOMBRE.kt Listo  "
	done
done
