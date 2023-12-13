#! /usr/bin/env bash
cd real_dataset/

NAME="MARTITA_Hospital_Locations"
TXT=$(stat -c %s $NAME".txt")
RBFULL=$(stat -c %s $NAME".rbfull")
KT=$(stat -c %s $NAME".kt")
printf "$NAME \t $TXT  \t $RBFULL  \t $KT  \n"
NAME="MARTITA_VicFreeWiFiAPMapData20170724"
TXT=$(stat -c %s $NAME".txt")
RBFULL=$(stat -c %s $NAME".rbfull")
KT=$(stat -c %s $NAME".kt")
printf "$NAME \t $TXT  \t $RBFULL  \t $KT  \n"
NAME="MARTITA_dv259-allschoolslist-2018"
TXT=$(stat -c %s $NAME".txt")
RBFULL=$(stat -c %s $NAME".rbfull")
KT=$(stat -c %s $NAME".kt")
printf "$NAME \t $TXT  \t $RBFULL  \t $KT  \n"
NAME="MARTITA_SportandRec"
TXT=$(stat -c %s $NAME".txt")
RBFULL=$(stat -c %s $NAME".rbfull")
KT=$(stat -c %s $NAME".kt")
printf "$NAME \t $TXT  \t $RBFULL  \t $KT  \n"
NAME="MARTITA_current_victorian_licences_by_location_august_2018"
TXT=$(stat -c %s $NAME".txt")
RBFULL=$(stat -c %s $NAME".rbfull")
KT=$(stat -c %s $NAME".kt")
printf "$NAME \t $TXT  \t $RBFULL  \t $KT  \n"
NAME="MARTITA_Crashes_Last_Five_Years"
TXT=$(stat -c %s $NAME".txt")
RBFULL=$(stat -c %s $NAME".rbfull")
KT=$(stat -c %s $NAME".kt")
printf "$NAME \t $TXT  \t $RBFULL  \t $KT  \n"
NAME="MARTITA_CaStream"
TXT=$(stat -c %s $NAME".txt")
RBFULL=$(stat -c %s $NAME".rbfull")
KT=$(stat -c %s $NAME".kt")
printf "$NAME \t $TXT  \t $RBFULL  \t $KT  \n"
NAME="MARTITA_CaStreet"
TXT=$(stat -c %s $NAME".txt")
RBFULL=$(stat -c %s $NAME".rbfull")
KT=$(stat -c %s $NAME".kt")
printf "$NAME \t $TXT  \t $RBFULL  \t $KT  \n"

cd ..