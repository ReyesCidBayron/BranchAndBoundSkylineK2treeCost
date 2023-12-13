#! /usr/bin/env bash

echo "Compilación: "
g++ peakRealSkyline.cpp -o peakRealSkyline
g++ peakRealEnumerating.cpp -o peakRealEnumerating
g++ peakRealConstrained.cpp -o peakRealConstrained
g++ timeRealConstrained.cpp -o timeRealConstrained

echo "Procesado de resultados: "
./peakRealSkyline peakRealSkyline.out
./peakRealEnumerating peakRealEnumerating.out
./peakRealConstrained peakRealConstrained.out
./timeRealConstrained timeRealConstrained.out

echo "Graficos: "
gnuplot < plot_peak_constrained
gnuplot < plot_time_constrained

echo "Hecho!"