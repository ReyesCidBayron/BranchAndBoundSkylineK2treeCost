Skyline
=======

Para realizar pruebas de correctitud tras hacer alguna modificación al código:
./correctitudTest.sh
./mainCorrectitudTest

Para generar los datos sintéticos usados en la experimentación:
./generateDatasetCantPoints.sh
./generateDatasetDens.sh

Para compactar los datos generados:
./convertDatasetCantPoints.sh
./convertDatasetDens.sh
./convertRealDataset.sh

Para medir la memoria utilizada por los archivos generados:
./fileMemorySinteticCantPoints.sh
./fileMemorySinteticDens.sh
./fileMemoryRealDataset.sh

Para medir la memoria utilizada por los algoritmos:
./peakMemoryCountCantPoints.sh
./peakMemoryCountDens.sh
./peakMemoryEnumeratingCantPoints.sh
./peakMemoryEnumeratingDens.sh
./peakMemorySkylineCantPoints.sh
./peakMemorySkylineDens.sh
./peakMemoryRealDataset.sh

Para medir el tiempo utilizado por los algoritmos:
./timeTestCountCantPoints.sh
./timeTestCountDens.sh
./timeTestEnumeratingCantPoints.sh
./timeTestEnumeratingDens.sh
./timeTestSkylineCantPoints.sh
./timeTestSkylineDens.sh
./timeTestRealDataset.sh