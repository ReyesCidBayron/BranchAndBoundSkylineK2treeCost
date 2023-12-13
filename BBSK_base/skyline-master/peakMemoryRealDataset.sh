#! /usr/bin/env bash
RUTA="real_dataset"
NOMBRE="MARTITA_Hospital_Locations"
/usr/bin/time -f "$NOMBRE \t Ing \t %M KB" ./mainSkylineIngenuo $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t BBS \t %M KB" ./mainSkylineBBSk $RUTA/$NOMBRE 0
/usr/bin/time -f "$NOMBRE \t SKX \t %M KB" ./mainSkylineX $RUTA/$NOMBRE
/usr/bin/time -f "$NOMBRE \t CDs \t %M KB" ./mainCargarDataset $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t CKt %M KB" ./mainCargarKtree $RUTA/$NOMBRE	
NOMBRE="MARTITA_VicFreeWiFiAPMapData20170724"
/usr/bin/time -f "$NOMBRE \t Ing \t %M KB" ./mainSkylineIngenuo $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t BBS \t %M KB" ./mainSkylineBBSk $RUTA/$NOMBRE 0
/usr/bin/time -f "$NOMBRE \t SKX \t %M KB" ./mainSkylineX $RUTA/$NOMBRE
/usr/bin/time -f "$NOMBRE \t CDs \t %M KB" ./mainCargarDataset $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t CKt %M KB" ./mainCargarKtree $RUTA/$NOMBRE	
NOMBRE="MARTITA_dv259-allschoolslist-2018"
/usr/bin/time -f "$NOMBRE \t Ing \t %M KB" ./mainSkylineIngenuo $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t BBS \t %M KB" ./mainSkylineBBSk $RUTA/$NOMBRE 0
/usr/bin/time -f "$NOMBRE \t SKX \t %M KB" ./mainSkylineX $RUTA/$NOMBRE
/usr/bin/time -f "$NOMBRE \t CDs \t %M KB" ./mainCargarDataset $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t CKt %M KB" ./mainCargarKtree $RUTA/$NOMBRE	
NOMBRE="MARTITA_SportandRec"
/usr/bin/time -f "$NOMBRE \t Ing \t %M KB" ./mainSkylineIngenuo $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t BBS \t %M KB" ./mainSkylineBBSk $RUTA/$NOMBRE 0
/usr/bin/time -f "$NOMBRE \t SKX \t %M KB" ./mainSkylineX $RUTA/$NOMBRE
/usr/bin/time -f "$NOMBRE \t CDs \t %M KB" ./mainCargarDataset $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t CKt %M KB" ./mainCargarKtree $RUTA/$NOMBRE	
NOMBRE="MARTITA_current_victorian_licences_by_location_august_2018"
/usr/bin/time -f "$NOMBRE \t Ing \t %M KB" ./mainSkylineIngenuo $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t BBS \t %M KB" ./mainSkylineBBSk $RUTA/$NOMBRE 0
/usr/bin/time -f "$NOMBRE \t SKX \t %M KB" ./mainSkylineX $RUTA/$NOMBRE
/usr/bin/time -f "$NOMBRE \t CDs \t %M KB" ./mainCargarDataset $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t CKt %M KB" ./mainCargarKtree $RUTA/$NOMBRE	
NOMBRE="MARTITA_Crashes_Last_Five_Years"
/usr/bin/time -f "$NOMBRE \t Ing \t %M KB" ./mainSkylineIngenuo $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t BBS \t %M KB" ./mainSkylineBBSk $RUTA/$NOMBRE
/usr/bin/time -f "$NOMBRE \t SKX \t %M KB" ./mainSkylineX $RUTA/$NOMBRE
/usr/bin/time -f "$NOMBRE \t CDs \t %M KB" ./mainCargarDataset $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t CKt %M KB" ./mainCargarKtree $RUTA/$NOMBRE	
NOMBRE="MARTITA_CaStream"
/usr/bin/time -f "$NOMBRE \t Ing \t %M KB" ./mainSkylineIngenuo $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t BBS \t %M KB" ./mainSkylineBBSk $RUTA/$NOMBRE 0
/usr/bin/time -f "$NOMBRE \t SKX \t %M KB" ./mainSkylineX $RUTA/$NOMBRE
/usr/bin/time -f "$NOMBRE \t CDs \t %M KB" ./mainCargarDataset $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t CKt %M KB" ./mainCargarKtree $RUTA/$NOMBRE	
NOMBRE="MARTITA_CaStreet"
/usr/bin/time -f "$NOMBRE \t Ing \t %M KB" ./mainSkylineIngenuo $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t BBS \t %M KB" ./mainSkylineBBSk $RUTA/$NOMBRE 0
/usr/bin/time -f "$NOMBRE \t SKX \t %M KB" ./mainSkylineX $RUTA/$NOMBRE
/usr/bin/time -f "$NOMBRE \t CDs \t %M KB" ./mainCargarDataset $RUTA/$NOMBRE 1
/usr/bin/time -f "$NOMBRE \t CKt %M KB" ./mainCargarKtree $RUTA/$NOMBRE	
