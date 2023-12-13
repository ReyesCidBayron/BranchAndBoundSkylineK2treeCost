#! /usr/bin/env bash
RUTA="real_dataset"

printf "\nMARTITA_Hospital_Locations  "
./mainGenerateRbfull $RUTA/MARTITA_Hospital_Locations 1
./mainGenerateKt $RUTA/MARTITA_Hospital_Locations
printf "\nMARTITA_VicFreeWiFiAPMapData20170724  "
./mainGenerateRbfull $RUTA/MARTITA_VicFreeWiFiAPMapData20170724 1
./mainGenerateKt $RUTA/MARTITA_VicFreeWiFiAPMapData20170724
printf "\nMARTITA_dv259-allschoolslist-2018  "
./mainGenerateRbfull $RUTA/MARTITA_dv259-allschoolslist-2018 1
./mainGenerateKt $RUTA/MARTITA_dv259-allschoolslist-2018
printf "\nMARTITA_SportandRec  "
./mainGenerateRbfull $RUTA/MARTITA_SportandRec 1
./mainGenerateKt $RUTA/MARTITA_SportandRec
printf "\nMARTITA_current_victorian_licences_by_location_august_2018  "
./mainGenerateRbfull $RUTA/MARTITA_current_victorian_licences_by_location_august_2018 1
./mainGenerateKt $RUTA/MARTITA_current_victorian_licences_by_location_august_2018
printf "\nMARTITA_Crashes_Last_Five_Years  "
./mainGenerateRbfull $RUTA/MARTITA_Crashes_Last_Five_Years 1
./mainGenerateKt $RUTA/MARTITA_Crashes_Last_Five_Years
printf "\nMARTITA_CaStream  "
./mainGenerateRbfull $RUTA/MARTITA_CaStream 1
./mainGenerateKt $RUTA/MARTITA_CaStream
printf "\nMARTITA_CaStreet  "
./mainGenerateRbfull $RUTA/MARTITA_CaStreet 1
./mainGenerateKt $RUTA/MARTITA_CaStreet
