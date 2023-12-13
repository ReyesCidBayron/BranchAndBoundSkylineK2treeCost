#! /usr/bin/env bash

# Dont forget
# javac libs/*.java
# make

# 0.01%
for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap00.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap00.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap00.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap01.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap01.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap01.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap02.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap02.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap02.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap03.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap03.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap03.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap04.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap04.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap04.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap05.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap05.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap05.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap06.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap06.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap06.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap07.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap07.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap07.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap08.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap08.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap08.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap09.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap09.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap09.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap10.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap10.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap10.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap11.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap11.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap11.1m 495000 505000 495000 505000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done


# 0.1%
for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap00.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap00.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap00.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap01.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap01.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap01.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap02.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap02.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap02.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap03.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap03.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap03.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap04.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap04.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap04.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap05.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap05.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap05.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap06.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap06.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap06.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap07.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap07.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap07.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap08.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap08.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap08.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap09.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap09.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap09.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap10.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap10.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap10.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap11.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap11.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap11.1m 484189 515812 484189 515812
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done

# 1%
for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap00.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap00.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap00.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap01.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap01.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap01.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap02.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap02.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap02.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap03.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap03.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap03.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap04.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap04.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap04.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap05.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap05.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap05.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap06.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap06.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap06.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap07.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap07.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap07.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap08.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap08.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap08.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap09.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap09.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap09.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap10.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap10.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap10.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap11.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap11.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap11.1m 450000 550000 450000 550000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done

# 10%
for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap00.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap00.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap00.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap01.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap01.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap01.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap02.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap02.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap02.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap03.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap03.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap03.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap04.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap04.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap04.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap05.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap05.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap05.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap06.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap06.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap06.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap07.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap07.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap07.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap08.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap08.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap08.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap09.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap09.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap09.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap10.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap10.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap10.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap11.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap11.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap11.1m 341886 658114 341886 658114
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done

# 25%
for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap00.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap00.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap00.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap01.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap01.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap01.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap02.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap02.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap02.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap03.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap03.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap03.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap04.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap04.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap04.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap05.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap05.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap05.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap06.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap06.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap06.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap07.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap07.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap07.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap08.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap08.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap08.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap09.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap09.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap09.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap10.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap10.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap10.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap11.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap11.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap11.1m 250000 750000 250000 750000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done

# 50%
for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap00.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap00.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap00.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap01.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap01.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap01.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap02.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap02.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap02.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap03.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap03.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap03.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap04.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap04.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap04.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap05.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap05.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap05.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap06.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap06.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap06.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap07.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap07.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap07.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap08.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap08.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap08.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap09.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap09.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap09.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap10.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap10.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap10.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap11.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap11.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap11.1m 146447 853554 146447 853554
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done

# 99%
for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap00.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap00.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap00.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap01.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap01.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap01.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap02.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap02.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap02.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap03.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap03.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap03.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap04.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap04.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap04.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap05.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap05.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap05.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap06.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap06.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap06.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap07.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap07.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap07.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap08.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap08.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap08.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap09.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap09.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap09.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap10.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap10.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap10.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap11.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap11.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap11.1m 2507 997494 2507 997494
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done

# 100%
for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap00.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap00.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap00.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap01.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap01.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap01.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap02.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap02.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap02.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap03.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap03.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap03.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap04.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap04.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap04.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap05.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap05.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap05.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap06.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap06.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap06.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap07.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap07.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap07.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap08.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap08.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap08.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap09.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap09.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap09.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap10.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap10.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap10.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getConstrainedBBSKM dataset-real/snap11.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedBBSKE dataset-real/snap11.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getConstrainedX dataset-real/snap11.1m 0 1000000 0 1000000
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done