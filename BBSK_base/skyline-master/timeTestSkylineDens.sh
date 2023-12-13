#! /usr/bin/env bash
ID_INICIAL=1
ID_FINAL=3
EXPERIMENTOS_POR_ID=10
NOMBRE_UN="inputDenUn"
NOMBRE_CL="inputDenCl"
RUTA="automatic_test"

for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_UN-$ID-$E
		./mainTestTimeSkyline $RUTA/$NOMBRE 0
	done
done

for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_CL-$ID-$E
		./mainTestTimeSkyline $RUTA/$NOMBRE 0
	done
done

