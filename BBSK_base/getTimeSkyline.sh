#! /usr/bin/env bash

# Dont forget
# javac libs/*.java
# make

# Datos uniformes
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_uni_01_$E 0
	 ./getTimeSkyline dataset/cant_uni_01_$E 1
done
# 500.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_uni_05_$E 0
	 ./getTimeSkyline dataset/cant_uni_05_$E 1
done
# 1.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_uni_1_$E 0
	 ./getTimeSkyline dataset/cant_uni_1_$E 1
done
# 5.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_uni_5_$E 0
	 ./getTimeSkyline dataset/cant_uni_5_$E 1
done
# 10.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_uni_10_$E 0
	 ./getTimeSkyline dataset/cant_uni_10_$E 1
done
# 50.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_uni_50_$E 0
	 ./getTimeSkyline dataset/cant_uni_50_$E 1
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/dens_uni_1_$E 0
	 ./getTimeSkyline dataset/dens_uni_1_$E 1
done
# 5%
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/dens_uni_5_$E 0
	 ./getTimeSkyline dataset/dens_uni_5_$E 1
done
# 10%
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/dens_uni_10_$E 0
	 ./getTimeSkyline dataset/dens_uni_10_$E 1
done

# Datos clusterizados
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_clu_01_$E 0
	 ./getTimeSkyline dataset/cant_clu_01_$E 1
done
# 500.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_clu_05_$E 0
	 ./getTimeSkyline dataset/cant_clu_05_$E 1
done
# 1.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_clu_1_$E 0
	 ./getTimeSkyline dataset/cant_clu_1_$E 1
done
# 5.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_clu_5_$E 0
	 ./getTimeSkyline dataset/cant_clu_5_$E 1
done
# 10.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_clu_10_$E 0
	 ./getTimeSkyline dataset/cant_clu_10_$E 1
done
# 50.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_clu_50_$E 0
	 ./getTimeSkyline dataset/cant_clu_50_$E 1
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/dens_clu_1_$E 0
	 ./getTimeSkyline dataset/dens_clu_1_$E 1
done
# 5%
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/dens_clu_5_$E 0
	 ./getTimeSkyline dataset/dens_clu_5_$E 1
done
# 10%
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/dens_clu_10_$E 0
	 ./getTimeSkyline dataset/dens_clu_10_$E 1
done

# Datos mixtos
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_mix_01_$E 0
	 ./getTimeSkyline dataset/cant_mix_01_$E 1
done
# 500.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_mix_05_$E 0
	 ./getTimeSkyline dataset/cant_mix_05_$E 1
done
# 1.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_mix_1_$E 0
	 ./getTimeSkyline dataset/cant_mix_1_$E 1
done
# 5.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_mix_5_$E 0
	 ./getTimeSkyline dataset/cant_mix_5_$E 1
done
# 10.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_mix_10_$E 0
	 ./getTimeSkyline dataset/cant_mix_10_$E 1
done
# 50.000.000
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/cant_mix_50_$E 0
	 ./getTimeSkyline dataset/cant_mix_50_$E 1
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/dens_mix_1_$E 0
	 ./getTimeSkyline dataset/dens_mix_1_$E 1
done
# 5%
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/dens_mix_5_$E 0
	 ./getTimeSkyline dataset/dens_mix_5_$E 1
done
# 10%
for ((E=1;E<=10;E++));
do
	# ./getTimeSkyline dataset/dens_mix_10_$E 0
	 ./getTimeSkyline dataset/dens_mix_10_$E 1
done