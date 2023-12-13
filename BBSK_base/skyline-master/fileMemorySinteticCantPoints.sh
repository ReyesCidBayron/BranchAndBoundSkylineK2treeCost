#! /usr/bin/env bash
ID_INICIAL=1
ID_FINAL=14
EXPERIMENTOS_POR_ID=10
NOMBRE_UN="inputUn"
NOMBRE_CL="inputCl"

cd automatic_test/

for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_UN-$ID-$E
		TXT=$(stat -c %s $NOMBRE".txt")
		RBFULL=$(stat -c %s $NOMBRE".rbfull")
		KT=$(stat -c %s $NOMBRE".kt")
		printf "$NOMBRE \t $TXT \t $RBFULL \t $KT\n"
		
	done
	
done
for ((ID=$ID_INICIAL;ID<=$ID_FINAL;ID++));
do
	for ((E=1;E<=$EXPERIMENTOS_POR_ID;E++));
	do
		NOMBRE=$NOMBRE_CL-$ID-$E
		TXT=$(stat -c %s $NOMBRE".txt")
		RBFULL=$(stat -c %s $NOMBRE".rbfull")
		KT=$(stat -c %s $NOMBRE".kt")
		printf "$NOMBRE \t $TXT \t $RBFULL \t $KT\n"
	done
	
done



cd ..
