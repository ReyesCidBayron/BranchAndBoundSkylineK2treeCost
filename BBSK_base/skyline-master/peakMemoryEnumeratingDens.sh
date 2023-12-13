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
		printf "$NOMBRE\n"
		/usr/bin/time -f "%M" ./mainEnumeratingRange $RUTA/$NOMBRE
		/usr/bin/time -f "%M" ./mainEnumeratingCompactRange $RUTA/$NOMBRE
		/usr/bin/time -f "%M" ./mainEnumeratingCompact $RUTA/$NOMBRE
		/usr/bin/time -f "%M" ./mainCargarKtree $RUTA/$NOMBRE			
	done
done
for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_CL-$ID-$E
		printf "$NOMBRE\n"
		/usr/bin/time -f "%M" ./mainEnumeratingRange $RUTA/$NOMBRE
		/usr/bin/time -f "%M" ./mainEnumeratingCompactRange $RUTA/$NOMBRE
		/usr/bin/time -f "%M" ./mainEnumeratingCompact $RUTA/$NOMBRE
		/usr/bin/time -f "%M" ./mainCargarKtree $RUTA/$NOMBRE		
	done
done