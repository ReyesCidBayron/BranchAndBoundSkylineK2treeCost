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
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_uni_01_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_uni_01_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_uni_01_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_01_$E
	done
done

# 500.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_uni_05_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_uni_05_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_uni_05_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_05_$E
	done
done

# 1.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_uni_1_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_uni_1_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_uni_1_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_1_$E
	done
done

# 5.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_uni_5_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_uni_5_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_uni_5_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_5_$E
	done
done

# 10.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_uni_10_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_uni_10_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_uni_10_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_10_$E
	done
done

# 50.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_uni_50_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_uni_50_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_uni_50_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_uni_50_$E
	done
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/dens_uni_1_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/dens_uni_1_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/dens_uni_1_$E
		/usr/bin/time -f "%M" ./getKtree dataset/dens_uni_1_$E
	done
done

# 5%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/dens_uni_5_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/dens_uni_5_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/dens_uni_5_$E
		/usr/bin/time -f "%M" ./getKtree dataset/dens_uni_5_$E
	done
done

# 10%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/dens_uni_10_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/dens_uni_10_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/dens_uni_10_$E
		/usr/bin/time -f "%M" ./getKtree dataset/dens_uni_10_$E
	done
done

# Datos clusterizados
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_clu_01_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_clu_01_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_clu_01_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_01_$E
	done
done

# 500.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_clu_05_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_clu_05_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_clu_05_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_05_$E
	done
done

# 1.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_clu_1_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_clu_1_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_clu_1_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_1_$E
	done
done

# 5.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_clu_5_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_clu_5_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_clu_5_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_5_$E
	done
done

# 10.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_clu_10_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_clu_10_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_clu_10_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_10_$E
	done
done

# 50.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_clu_50_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_clu_50_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_clu_50_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_clu_50_$E
	done
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/dens_clu_1_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/dens_clu_1_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/dens_clu_1_$E
		/usr/bin/time -f "%M" ./getKtree dataset/dens_clu_1_$E
	done
done

# 5%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/dens_clu_5_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/dens_clu_5_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/dens_clu_5_$E
		/usr/bin/time -f "%M" ./getKtree dataset/dens_clu_5_$E
	done
done

# 10%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/dens_clu_10_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/dens_clu_10_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/dens_clu_10_$E
		/usr/bin/time -f "%M" ./getKtree dataset/dens_clu_10_$E
	done
done

# Datos Mixtos
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_mix_01_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_mix_01_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_mix_01_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_01_$E
	done
done

# 500.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_mix_05_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_mix_05_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_mix_05_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_05_$E
	done
done

# 1.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_mix_1_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_mix_1_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_mix_1_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_1_$E
	done
done

# 5.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_mix_5_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_mix_5_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_mix_5_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_5_$E
	done
done

# 10.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_mix_10_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_mix_10_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_mix_10_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_10_$E
	done
done

# 50.000.000
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/cant_mix_50_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/cant_mix_50_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/cant_mix_50_$E
		/usr/bin/time -f "%M" ./getKtree dataset/cant_mix_50_$E
	done
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/dens_mix_1_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/dens_mix_1_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/dens_mix_1_$E
		/usr/bin/time -f "%M" ./getKtree dataset/dens_mix_1_$E
	done
done

# 5%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/dens_mix_5_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/dens_mix_5_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/dens_mix_5_$E
		/usr/bin/time -f "%M" ./getKtree dataset/dens_mix_5_$E
	done
done

# 10%
for ((E=1;E<=10;E++));
do
	for ((J=1;J<=10;J++));
	do
		/usr/bin/time -f "%M" ./getRangeEnumerating dataset/dens_mix_10_$E
		/usr/bin/time -f "%M" ./getRangeCompactEnumerating dataset/dens_mix_10_$E
		/usr/bin/time -f "%M" ./getEnumeratingCompact dataset/dens_mix_10_$E
		/usr/bin/time -f "%M" ./getKtree dataset/dens_mix_10_$E
	done
done