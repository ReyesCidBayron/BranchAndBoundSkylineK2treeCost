#! /usr/bin/env bash

# Dont forget
# javac libs/*.java
# make

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap00.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap00.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap00.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap00.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap01.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap01.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap01.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap01.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap02.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap02.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap02.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap02.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap03.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap03.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap03.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap03.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap04.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap04.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap04.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap04.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap05.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap05.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap05.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap05.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap06.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap06.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap06.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap06.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap07.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap07.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap07.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap07.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap08.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap08.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap08.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap08.1m
done

#for ((J=1;J<=100;J++));
#do
#	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap09.1m
#	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap09.1m
#	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap09.1m
#	/usr/bin/time -f "%M" ./getKtree dataset-real/snap09.1m
#done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap10.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap10.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap10.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap10.1m
done

for ((J=1;J<=100;J++));
do
	/usr/bin/time -f "%M" ./getRangeEnumerating dataset-real/snap11.1m
	/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset-real/snap11.1m
	/usr/bin/time -f "%M" ./getEnumeratingCompact dataset-real/snap11.1m
	/usr/bin/time -f "%M" ./getKtree dataset-real/snap11.1m
done