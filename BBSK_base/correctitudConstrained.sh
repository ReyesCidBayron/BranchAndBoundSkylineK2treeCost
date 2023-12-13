# Dont forget
# javac libs/*.java
# make

TEST="test-"

for ((E=1;E<=100;E++));
do
	java libs.GenM 1000 1000 > dataset/$TEST$E.txt
	./generateKtFromPointList dataset/$TEST$E
	./getCorrectitudeConstrained dataset/$TEST$E 250 750 250 750
done