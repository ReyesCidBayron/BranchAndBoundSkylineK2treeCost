CPP=g++

OBJECTS=libs/basic.o libs/bitrankw32int.o libs/kTree.o libs/BBSK.o libs/SkylineX.o\
		libs/NaiveSkyline.o libs/NaiveCount.o libs/Count.o libs/NaiveEnumerating.o\
		libs/EnumeratingRange.o libs/EnumeratingCompact.o libs/NaiveConstrained.o\
		libs/ConstrainedBBSK.o libs/ConstrainedX.o
		
BINS=kt_info generateKtFromPointList getNaiveSkyline getSkyline getTimeSkyline\
		getBBSKM getBBSKE getSkylineX getPoints getKtree getCorrectitudeSkyline\
		getCount getCorrectitudeCount getTimeCount getNaiveCount\
		getRangeCount getCompactCount getEnumerating getNaiveEnumerating getRangeEnumerating\
		getRangeCompactEnumerating getEnumeratingCompact getCorrectitudeEnumerating\
		getTimeEnumerating getConstrained getNaiveConstrained getConstrainedBBSKM\
		getConstrainedBBSKE getConstrainedX getCorrectitudeConstrained getTimeConstrained
		
CPPFLAGS=-std=c++11 -O3 -DNDEBUG
DEST=.

%.o: %.c
	$(CPP) $(CPPFLAGS) -c $< -o $@

all: clean bin

bin: $(OBJECTS) $(BINS)

kt_info:
	g++ $(CPPFLAGS) -o $(DEST)/kt_info kt_info.c $(OBJECTS) -lm

generateKtFromPointList:
	g++ $(CPPFLAGS) -o $(DEST)/generateKtFromPointList generateKtFromPointList.cpp $(OBJECTS) -lm
	
getNaiveSkyline:
	g++ $(CPPFLAGS) -o $(DEST)/getNaiveSkyline getNaiveSkyline.cpp $(OBJECTS) -lm

getSkyline:
	g++ $(CPPFLAGS) -o $(DEST)/getSkyline getSkyline.cpp $(OBJECTS) -lm
	
getTimeSkyline:
	g++ $(CPPFLAGS) -o $(DEST)/getTimeSkyline getTimeSkyline.cpp $(OBJECTS) -lm
	
getBBSKM:
	g++ $(CPPFLAGS) -o $(DEST)/getBBSKM getBBSKM.cpp $(OBJECTS) -lm

getBBSKE:
	g++ $(CPPFLAGS) -o $(DEST)/getBBSKE getBBSKE.cpp $(OBJECTS) -lm
	
getSkylineX:
	g++ $(CPPFLAGS) -o $(DEST)/getSkylineX getSkylineX.cpp $(OBJECTS) -lm
	
getKtree:
	g++ $(CPPFLAGS) -o $(DEST)/getKtree getKtree.cpp $(OBJECTS) -lm
	
getCorrectitudeSkyline:
	g++ $(CPPFLAGS) -o $(DEST)/getCorrectitudeSkyline getCorrectitudeSkyline.cpp $(OBJECTS) -lm

getCount:
	g++ $(CPPFLAGS) -o $(DEST)/getCount getCount.cpp $(OBJECTS) -lm
	
getCorrectitudeCount:
	g++ $(CPPFLAGS) -o $(DEST)/getCorrectitudeCount getCorrectitudeCount.cpp $(OBJECTS) -lm
	
getTimeCount:
	g++ $(CPPFLAGS) -o $(DEST)/getTimeCount getTimeCount.cpp $(OBJECTS) -lm
	
getNaiveCount:
	g++ $(CPPFLAGS) -o $(DEST)/getNaiveCount getNaiveCount.cpp $(OBJECTS) -lm
	
getRangeCount:
	g++ $(CPPFLAGS) -o $(DEST)/getRangeCount getRangeCount.cpp $(OBJECTS) -lm
	
getCompactCount:
	g++ $(CPPFLAGS) -o $(DEST)/getCompactCount getCompactCount.cpp $(OBJECTS) -lm
	
getEnumerating:
	g++ $(CPPFLAGS) -o $(DEST)/getEnumerating getEnumerating.cpp $(OBJECTS) -lm
	
getNaiveEnumerating:
	g++ $(CPPFLAGS) -o $(DEST)/getNaiveEnumerating getNaiveEnumerating.cpp $(OBJECTS) -lm
	
getRangeEnumerating:
	g++ $(CPPFLAGS) -o $(DEST)/getRangeEnumerating getRangeEnumerating.cpp $(OBJECTS) -lm
	
getRangeCompactEnumerating:
	g++ $(CPPFLAGS) -o $(DEST)/getRangeCompactEnumerating getRangeCompactEnumerating.cpp $(OBJECTS) -lm
	
getEnumeratingCompact:
	g++ $(CPPFLAGS) -o $(DEST)/getEnumeratingCompact getEnumeratingCompact.cpp $(OBJECTS) -lm
	
getCorrectitudeEnumerating:
	g++ $(CPPFLAGS) -o $(DEST)/getCorrectitudeEnumerating getCorrectitudeEnumerating.cpp $(OBJECTS) -lm
	
getTimeEnumerating:
	g++ $(CPPFLAGS) -o $(DEST)/getTimeEnumerating getTimeEnumerating.cpp $(OBJECTS) -lm
	
getConstrained:
	g++ $(CPPFLAGS) -o $(DEST)/getConstrained getConstrained.cpp $(OBJECTS) -lm
	
getNaiveConstrained:
	g++ $(CPPFLAGS) -o $(DEST)/getNaiveConstrained getNaiveConstrained.cpp $(OBJECTS) -lm
	
getConstrainedBBSKM:
	g++ $(CPPFLAGS) -o $(DEST)/getConstrainedBBSKM getConstrainedBBSKM.cpp $(OBJECTS) -lm
	
getConstrainedBBSKE:
	g++ $(CPPFLAGS) -o $(DEST)/getConstrainedBBSKE getConstrainedBBSKE.cpp $(OBJECTS) -lm
	
getConstrainedX:
	g++ $(CPPFLAGS) -o $(DEST)/getConstrainedX getConstrainedX.cpp $(OBJECTS) -lm
	
getCorrectitudeConstrained:
	g++ $(CPPFLAGS) -o $(DEST)/getCorrectitudeConstrained getCorrectitudeConstrained.cpp $(OBJECTS) -lm
	
getTimeConstrained:
	g++ $(CPPFLAGS) -o $(DEST)/getTimeConstrained getTimeConstrained.cpp $(OBJECTS) -lm
	
clean:
	rm -f $(OBJECTS) $(BINS)
	cd $(DEST); rm -f *.a $(BINS)
