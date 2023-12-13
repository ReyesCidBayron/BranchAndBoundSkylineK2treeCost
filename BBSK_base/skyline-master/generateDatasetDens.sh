#! /usr/bin/env bash
EXPERIMENTOS_POR_ID=10
NOMBRE_UN="inputDenUn"
NOMBRE_CL="inputDenCl"
RUTA="automatic_test"
RANGO=5000

echo "GENERACION DE LA ENTRADA DENSIDAD"
echo "================================="

RANGO=4096

#1% 167.772
ID=1
CANTIDAD=167772
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

#5% 838.861
ID=2
CANTIDAD=838861
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

#10% 1.677.722
ID=3
CANTIDAD=1677722
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

