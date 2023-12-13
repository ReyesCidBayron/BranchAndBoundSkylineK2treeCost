#! /usr/bin/env bash

# Dont forget
# javac libs/*.java
# make

# Datos uniformes
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_uni_01_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_uni_01_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_01_$E
	done
done

# 500.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_uni_05_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_uni_05_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_05_$E
	done
done

# 1.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_uni_1_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_uni_1_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_1_$E
	done
done

# 5.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_uni_5_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_uni_5_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_5_$E
	done
done

# 10.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_uni_10_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_uni_10_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_10_$E
	done
done

# 50.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_uni_50_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_uni_50_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_50_$E
	done
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/dens_uni_1_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getCompactCount dataset/dens_uni_1_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getKtree dataset/dens_uni_1_$E
	done
done

# 5%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/dens_uni_5_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getCompactCount dataset/dens_uni_5_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getKtree dataset/dens_uni_5_$E
	done
done

# 10%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/dens_uni_10_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getCompactCount dataset/dens_uni_10_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getKtree dataset/dens_uni_10_$E
	done
done

# Tamaño matriz
# 2^13
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_13_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_13_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_13_$E
	done
done

# 2^14
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_14_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_14_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_14_$E
	done
done

# 2^15
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_15_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_15_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_15_$E
	done
done

# 2^16
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_16_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_16_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_16_$E
	done
done

# Tamaño rango
# 0.01%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_16_$E 32440 33095 32440 33095
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_16_$E 32440 33095 32440 33095
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_16_$E
	done
done

# 0.1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_16_$E 31732 33803 31732 33803
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_16_$E 31732 33803 31732 33803
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_16_$E
	done
done

# 1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_16_$E 29491 36044 29491 36044
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_16_$E 29491 36044 29491 36044
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_16_$E
	done
done

# 10%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_16_$E 22406 43129 22406 43129
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_16_$E 22406 43129 22406 43129
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_16_$E
	done
done

# 25%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_16_$E 16384 49151 16384 49151
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_16_$E 16384 49151 16384 49151
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_16_$E
	done
done

# 50%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_16_$E 9598 55937 9598 55937
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_16_$E 9598 55937 9598 55937
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_16_$E
	done
done

# 99%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_16_$E 164 65371 164 65371
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_16_$E 164 65371 164 65371
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_16_$E
	done
done

# 100%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_uni_16_$E 0 65535 0 65535
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_uni_16_$E 0 65535 0 65535
		/usr/bin/time -f "%M" ./getKtree dataset/matr_uni_16_$E
	done
done

# Datos clusterizados
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_clu_01_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_clu_01_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_01_$E
	done
done

# 500.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_clu_05_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_clu_05_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_05_$E
	done
done

# 1.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_clu_1_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_clu_1_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_1_$E
	done
done

# 5.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_clu_5_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_clu_5_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_5_$E
	done
done

# 10.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_clu_10_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_clu_10_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_10_$E
	done
done

# 50.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_clu_50_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_clu_50_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_50_$E
	done
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/dens_clu_1_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getCompactCount dataset/dens_clu_1_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getKtree dataset/dens_clu_1_$E
	done
done

# 5%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/dens_clu_5_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getCompactCount dataset/dens_clu_5_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getKtree dataset/dens_clu_5_$E
	done
done

# 10%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/dens_clu_10_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getCompactCount dataset/dens_clu_10_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getKtree dataset/dens_clu_10_$E
	done
done

# Tamaño matriz
# 2^13
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_13_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_13_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_13_$E
	done
done

# 2^14
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_14_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_14_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_14_$E
	done
done

# 2^15
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_15_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_15_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_15_$E
	done
done

# 2^16
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_16_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_16_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_16_$E
	done
done

# Tamaño rango
# 0.01%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_16_$E 32440 33095 32440 33095
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_16_$E 32440 33095 32440 33095
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_16_$E
	done
done

# 0.1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_16_$E 31732 33803 31732 33803
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_16_$E 31732 33803 31732 33803
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_16_$E
	done
done

# 1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_16_$E 29491 36044 29491 36044
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_16_$E 29491 36044 29491 36044
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_16_$E
	done
done

# 10%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_16_$E 22406 43129 22406 43129
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_16_$E 22406 43129 22406 43129
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_16_$E
	done
done

# 25%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_16_$E 16384 49151 16384 49151
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_16_$E 16384 49151 16384 49151
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_16_$E
	done
done

# 50%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_16_$E 9598 55937 9598 55937
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_16_$E 9598 55937 9598 55937
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_16_$E
	done
done

# 99%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_16_$E 164 65371 164 65371
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_16_$E 164 65371 164 65371
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_16_$E
	done
done

# 100%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_clu_16_$E 0 65535 0 65535
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_clu_16_$E 0 65535 0 65535
		/usr/bin/time -f "%M" ./getKtree dataset/matr_clu_16_$E
	done
done

# Datos Mixtos
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_mix_01_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_mix_01_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_01_$E
	done
done

# 500.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_mix_05_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_mix_05_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_05_$E
	done
done

# 1.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_mix_1_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_mix_1_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_1_$E
	done
done

# 5.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_mix_5_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_mix_5_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_5_$E
	done
done

# 10.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_mix_10_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_mix_10_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_10_$E
	done
done

# 50.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/cant_mix_50_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getCompactCount dataset/cant_mix_50_$E 1 65534 1 65534
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_50_$E
	done
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/dens_mix_1_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getCompactCount dataset/dens_mix_1_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getKtree dataset/dens_mix_1_$E
	done
done

# 5%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/dens_mix_5_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getCompactCount dataset/dens_mix_5_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getKtree dataset/dens_mix_5_$E
	done
done

# 10%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/dens_mix_10_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getCompactCount dataset/dens_mix_10_$E 1 22358 1 22358
		/usr/bin/time -f "%M" ./getKtree dataset/dens_mix_10_$E
	done
done

# Tamaño matriz
# 2^13
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_13_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_13_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_13_$E
	done
done

# 2^14
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_14_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_14_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_14_$E
	done
done

# 2^15
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_15_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_15_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_15_$E
	done
done

# 2^16
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_16_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_16_$E 1 8190 1 8190
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_16_$E
	done
done

# Tamaño rango
# 0.01%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_16_$E 32440 33095 32440 33095
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_16_$E 32440 33095 32440 33095
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_16_$E
	done
done

# 0.1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_16_$E 31732 33803 31732 33803
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_16_$E 31732 33803 31732 33803
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_16_$E
	done
done

# 1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_16_$E 29491 36044 29491 36044
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_16_$E 29491 36044 29491 36044
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_16_$E
	done
done

# 10%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_16_$E 22406 43129 22406 43129
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_16_$E 22406 43129 22406 43129
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_16_$E
	done
done

# 25%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_16_$E 16384 49151 16384 49151
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_16_$E 16384 49151 16384 49151
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_16_$E
	done
done

# 50%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_16_$E 9598 55937 9598 55937
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_16_$E 9598 55937 9598 55937
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_16_$E
	done
done

# 99%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_16_$E 164 65371 164 65371
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_16_$E 164 65371 164 65371
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_16_$E
	done
done

# 100%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeCount dataset/matr_mix_16_$E 0 65535 0 65535
		/usr/bin/time -f "%M" ./getCompactCount dataset/matr_mix_16_$E 0 65535 0 65535
		/usr/bin/time -f "%M" ./getKtree dataset/matr_mix_16_$E
	done
done