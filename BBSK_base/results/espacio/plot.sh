#! /usr/bin/env bash

echo "Compilación: "
g++ peakSkyline.cpp -o peakSkyline
g++ peakCount.cpp -o peakCount
g++ peakEnumerating.cpp -o peakEnumerating
g++ peakConstrained.cpp -o peakConstrained

echo "Procesado de resultados: "
./peakSkyline peakSkyline.out
./peakCount peakCount.out
./peakEnumerating peakEnumerating.out
./peakConstrained peakConstrained.out

echo "Graficos: "
echo "Skyline: "
gnuplot < plot_skyline_cant_uni
gnuplot < plot_skyline_cant_clu
gnuplot < plot_skyline_cant_mix

gnuplot < plot_skyline_dens_uni
gnuplot < plot_skyline_dens_clu
gnuplot < plot_skyline_dens_mix

echo "Count: "
gnuplot < plot_count_cant_uni
gnuplot < plot_count_cant_clu
gnuplot < plot_count_cant_mix
gnuplot < plot_count_cant

gnuplot < plot_count_dens_uni
gnuplot < plot_count_dens_clu
gnuplot < plot_count_dens_mix
gnuplot < plot_count_dens

gnuplot < plot_count_matr_uni
gnuplot < plot_count_matr_clu
gnuplot < plot_count_matr_mix
gnuplot < plot_count_matr

gnuplot < plot_count_rang_uni
gnuplot < plot_count_rang_clu
gnuplot < plot_count_rang_mix
gnuplot < plot_count_rang

echo "Enumerating: "
gnuplot < plot_enumerating_cant_uni
gnuplot < plot_enumerating_cant_clu
gnuplot < plot_enumerating_cant_mix

gnuplot < plot_enumerating_dens_uni
gnuplot < plot_enumerating_dens_clu
gnuplot < plot_enumerating_dens_mix

gnuplot < plot_enumerating_cant_uni_b
gnuplot < plot_enumerating_cant_clu_b
gnuplot < plot_enumerating_cant_mix_b

gnuplot < plot_enumerating_dens_uni_b
gnuplot < plot_enumerating_dens_clu_b
gnuplot < plot_enumerating_dens_mix_b

echo "Constrained: "
gnuplot < plot_constrained_cant_uni
gnuplot < plot_constrained_cant_clu
gnuplot < plot_constrained_cant_mix

gnuplot < plot_constrained_dens_uni
gnuplot < plot_constrained_dens_clu
gnuplot < plot_constrained_dens_mix

gnuplot < plot_constrained_matr_uni
gnuplot < plot_constrained_matr_clu
gnuplot < plot_constrained_matr_mix

gnuplot < plot_constrained_rang_uni
gnuplot < plot_constrained_rang_clu
gnuplot < plot_constrained_rang_mix

echo "Hecho!"