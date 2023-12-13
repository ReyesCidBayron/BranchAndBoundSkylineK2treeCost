#! /usr/bin/env bash
ID_INICIAL=1
ID_FINAL=14
EXPERIMENTOS_POR_ID=10
NOMBRE_UN="inputUn"
NOMBRE_CL="inputCl"
RUTA="automatic_test"

for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_UN-$ID-$E
		printf "$NOMBRE\n"
		/usr/bin/time -f "%M" ./mainSkylineIngenuo $RUTA/$NOMBRE 0
		/usr/bin/time -f "%M" ./mainSkylineBBSk $RUTA/$NOMBRE 0
		/usr/bin/time -f "%M" ./mainSkylineBBSk $RUTA/$NOMBRE 1
		/usr/bin/time -f "%M" ./mainSkylineX $RUTA/$NOMBRE
		/usr/bin/time -f "%M" ./mainCargarDataset $RUTA/$NOMBRE 0
		/usr/bin/time -f "%M" ./mainCargarKtree $RUTA/$NOMBRE			
	done
done
for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_CL-$ID-$E
		printf "$NOMBRE\n"
		/usr/bin/time -f "%M" ./mainSkylineIngenuo $RUTA/$NOMBRE 0
		/usr/bin/time -f "%M" ./mainSkylineBBSk $RUTA/$NOMBRE 0
		/usr/bin/time -f "%M" ./mainSkylineBBSk $RUTA/$NOMBRE 1
		/usr/bin/time -f "%M" ./mainSkylineX $RUTA/$NOMBRE
		/usr/bin/time -f "%M" ./mainCargarDataset $RUTA/$NOMBRE 0
		/usr/bin/time -f "%M" ./mainCargarKtree $RUTA/$NOMBRE		
	done
done

