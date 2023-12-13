#! /usr/bin/env bash

# Dont forget
# javac libs/*.java
# make

# Generacion .txt
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	java libs.GenM 100000 65536 > dataset/cant_uni_01_$E.txt
	java libs.GenG 100000 65536 > dataset/cant_clu_01_$E.txt
	java libs.GenMix 100000 65536 > dataset/cant_mix_01_$E.txt
done
# 500.000
for ((E=1;E<=10;E++));
do
	java libs.GenM 500000 65536 > dataset/cant_uni_05_$E.txt
	java libs.GenG 500000 65536 > dataset/cant_clu_05_$E.txt
	java libs.GenMix 500000 65536 > dataset/cant_mix_05_$E.txt
done
# 1.000.000
for ((E=1;E<=10;E++));
do
	java libs.GenM 1000000 65536 > dataset/cant_uni_1_$E.txt
	java libs.GenG 1000000 65536 > dataset/cant_clu_1_$E.txt
	java libs.GenMix 1000000 65536 > dataset/cant_mix_1_$E.txt
done
# 5.000.000
for ((E=1;E<=10;E++));
do
	java libs.GenM 5000000 65536 > dataset/cant_uni_5_$E.txt
	java libs.GenG 5000000 65536 > dataset/cant_clu_5_$E.txt
	java libs.GenMix 5000000 65536 > dataset/cant_mix_5_$E.txt
done
# 10.000.000
for ((E=1;E<=10;E++));
do
	java libs.GenM 10000000 65536 > dataset/cant_uni_10_$E.txt
	java libs.GenG 10000000 65536 > dataset/cant_clu_10_$E.txt
	java libs.GenMix 10000000 65536 > dataset/cant_mix_10_$E.txt
done
# 50.000.000
for ((E=1;E<=10;E++));
do
	java libs.GenM 50000000 65536 > dataset/cant_uni_50_$E.txt
	java libs.GenG 50000000 65536 > dataset/cant_clu_50_$E.txt
	java libs.GenMix 50000000 65536 > dataset/cant_mix_50_$E.txt
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	java libs.GenM 4999606 22360 > dataset/dens_uni_1_$E.txt
	java libs.GenG 50000000 22360 > dataset/dens_clu_1_$E.txt
	java libs.GenMix 50000000 22360 > dataset/dens_mix_1_$E.txt
done
# 5%
for ((E=1;E<=10;E++));
do
	java libs.GenM 24998480 22360 > dataset/dens_uni_5_$E.txt
	java libs.GenG 24998480 22360 > dataset/dens_clu_5_$E.txt
	java libs.GenMix 24998480 22360 > dataset/dens_mix_5_$E.txt
done
# 10%
for ((E=1;E<=10;E++));
do
	java libs.GenM 49996960 22360 > dataset/dens_uni_10_$E.txt
	java libs.GenG 49996960 22360 > dataset/dens_clu_10_$E.txt
	java libs.GenMix 49996960 22360 > dataset/dens_mix_10_$E.txt
done

# Matriz
# 2^13
for ((E=1;E<=10;E++));
do
	java libs.GenM 1000000 8192 > dataset/matr_uni_13_$E.txt
	java libs.GenG 1000000 8192 > dataset/matr_clu_13_$E.txt
	java libs.GenMix 1000000 8192 > dataset/matr_mix_13_$E.txt
done
# 2^14
for ((E=1;E<=10;E++));
do
	java libs.GenM 1000000 16384 > dataset/matr_uni_14_$E.txt
	java libs.GenG 1000000 16384 > dataset/matr_clu_14_$E.txt
	java libs.GenMix 1000000 16384 > dataset/matr_mix_14_$E.txt
done
# 2^15
for ((E=1;E<=10;E++));
do
	java libs.GenM 1000000 32768 > dataset/matr_uni_15_$E.txt
	java libs.GenG 1000000 32768 > dataset/matr_clu_15_$E.txt
	java libs.GenMix 1000000 32768 > dataset/matr_mix_15_$E.txt
done
# 2^16
for ((E=1;E<=10;E++));
do
	java libs.GenM 1000000 65536 > dataset/matr_uni_16_$E.txt
	java libs.GenG 1000000 65536 > dataset/matr_clu_16_$E.txt
	java libs.GenMix 1000000 65536 > dataset/matr_mix_16_$E.txt
done

# Generacion .kt
# Cantidad de puntos
# 100.000
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/cant_uni_01_$E
	./generateKtFromPointList dataset/cant_clu_01_$E
	./generateKtFromPointList dataset/cant_mix_01_$E
done
# 500.000
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/cant_uni_05_$E
	./generateKtFromPointList dataset/cant_clu_05_$E
	./generateKtFromPointList dataset/cant_mix_05_$E
done
# 1.000.000
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/cant_uni_1_$E
	./generateKtFromPointList dataset/cant_clu_1_$E
	./generateKtFromPointList dataset/cant_mix_1_$E
done
# 5.000.000
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/cant_uni_5_$E
	./generateKtFromPointList dataset/cant_clu_5_$E
	./generateKtFromPointList dataset/cant_mix_5_$E
done
# 10.000.000
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/cant_uni_10_$E
	./generateKtFromPointList dataset/cant_clu_10_$E
	./generateKtFromPointList dataset/cant_mix_10_$E
done
# 50.000.000
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/cant_uni_50_$E
	./generateKtFromPointList dataset/cant_clu_50_$E
	./generateKtFromPointList dataset/cant_mix_50_$E
done

# Densidad
# 1%
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/dens_uni_1_$E
	./generateKtFromPointList dataset/dens_clu_1_$E
	./generateKtFromPointList dataset/dens_mix_1_$E
done
# 5%
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/dens_uni_5_$E
	./generateKtFromPointList dataset/dens_clu_5_$E
	./generateKtFromPointList dataset/dens_mix_5_$E
done
# 10%
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/dens_uni_10_$E
	./generateKtFromPointList dataset/dens_clu_10_$E
	./generateKtFromPointList dataset/dens_mix_10_$E
done

# Matriz
# 2^13
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/matr_uni_13_$E
	./generateKtFromPointList dataset/matr_clu_13_$E
	./generateKtFromPointList dataset/matr_mix_13_$E
done
# 2^14
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/matr_uni_14_$E
	./generateKtFromPointList dataset/matr_clu_14_$E
	./generateKtFromPointList dataset/matr_mix_14_$E
done
# 2^15
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/matr_uni_15_$E
	./generateKtFromPointList dataset/matr_clu_15_$E
	./generateKtFromPointList dataset/matr_mix_15_$E
done
# 2^16
for ((E=1;E<=10;E++));
do
	./generateKtFromPointList dataset/matr_uni_16_$E
	./generateKtFromPointList dataset/matr_clu_16_$E
	./generateKtFromPointList dataset/matr_mix_16_$E
done