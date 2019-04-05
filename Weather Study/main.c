//
//  main.c
//  Weather Study
//
//  Created by Tristan Pageau on 2019-04-02.
//  Copyright © 2019 Poly MTL. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "export.h"
#include "interpol.h"
#include "Tables.h"
#define MIN_LAT -45.0
#define MAX_LAT 45.0
#define LAT_STEP 2
#define NBGRIBFILE 6
#define DATE "04020000"


int main(int argc, const char * argv[]) {
    
    FILE* altPressTable = NULL;
    
    //altPressTable = fopen("/Users/tristan/Poly MTL/Weather Study/Weather Study/AltPressTable", "w");
    if (altPressTable != NULL) {
        WriteTables(altPressTable);
        fclose(altPressTable);
    }
    
    char valueType[] = "Temp";
    char valueInFileName[] = "TMP_";
    int preRange[NBGRIBFILE] = {200, 300, 400, 500, 800, 1000};
    char f_lat[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/lat.m";
    char f_lon[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/lon.m";
    printf("PRESSURE RANGE\n");
    
    for (int latitude = MIN_LAT; latitude < MAX_LAT + 1; latitude += LAT_STEP) {
        export(NBGRIBFILE, preRange, valueType, valueInFileName, DATE, latitude);
    }
    
    
    return 0;
}
