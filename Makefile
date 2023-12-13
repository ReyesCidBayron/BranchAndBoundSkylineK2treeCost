CPP=g++

OBJECTS=libs/basic.o libs/bitrankw32int.o libs/kTree.o libs/BBSK.o libs/BBSKE.o
		
BINS=kt_info generateKtFromPointList getBBSKM getBBSKE getPoints getKtree generatePointList getBBSKEM
		
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

getBBSKM:
	g++ $(CPPFLAGS) -o $(DEST)/getBBSKM getBBSKM.cpp $(OBJECTS) -lm

getBBSKE:
	g++ $(CPPFLAGS) -o $(DEST)/getBBSKE getBBSKE.cpp $(OBJECTS) -lm
	
getKtree:
	g++ $(CPPFLAGS) -o $(DEST)/getKtree getKtree.cpp $(OBJECTS) -lm

generatePointList:
	g++ $(CPPFLAGS) -o $(DEST)/generatePointList generatePointList.cpp $(OBJECTS) -lm

getBBSKEM:
	G++ $(CPPFLAGS) -o $(DEST)/getBBSKEM getBBSKEM.cpp $(OBJECTS) -lm
	
clean:
	rm -f $(OBJECTS) $(BINS)
	cd $(DEST); rm -f *.a $(BINS)
