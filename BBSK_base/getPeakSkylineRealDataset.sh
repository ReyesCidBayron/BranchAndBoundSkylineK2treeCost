#! /usr/bin/env bash

# Dont forget
# javac libs/*.java
# make

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap00.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap00.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap00.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap01.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap01.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap01.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap02.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap02.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap02.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap03.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap03.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap03.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap04.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap04.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap04.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap05.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap05.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap05.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap06.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap06.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap06.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap07.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap07.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap07.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap08.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap08.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap08.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap09.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap09.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap09.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap10.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap10.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap10.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getBBSKM dataset-real/snap11.1m
	/usr/bin/time -f "%M" ./getBBSKE dataset-real/snap11.1m
	/usr/bin/time -f "%M" ./getSkylineX dataset-real/snap11.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done