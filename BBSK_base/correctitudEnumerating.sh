# Dont forget
# javac libs/*.java
# make

TEST="test-"

for ((E=1;E<=100;E++));
do
	java libs.GenM 1000 1000 > dataset/$TEST$E.txt
	./generateKtFromPointList dataset/$TEST$E
	./getCorrectitudeEnumerating dataset/$TEST$E
done