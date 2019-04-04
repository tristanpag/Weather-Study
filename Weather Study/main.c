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
#define LAT 45.0
#define NBGRIBFILE 7


int main(int argc, const char * argv[]) {
    
    FILE* altPressTable = NULL;
    
    //altPressTable = fopen("/Users/tristan/Poly MTL/Weather Study/Weather Study/AltPressTable", "w");
    if (altPressTable != NULL) {
        WriteTables(altPressTable);
        fclose(altPressTable);
    }
    
    char valueType[] = "Temp";
    char valueInFileName[] = "TMP_";
    int preRange[NBGRIBFILE];
    preRange[0] = 100;
    preRange[1] = 200;
    preRange[2] = 300;
    preRange[3] = 400;
    preRange[4] = 500;
    preRange[5] = 800;
    preRange[6] = 1000;
    char f_lat[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/lat.m";
    char f_lon[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/lon.m";
    printf("PRESSURE RANGE\n");
    
    
    for (int i = 0; i < NBGRIBFILE; i++) {
        double altitude = Pre2Alt_ISA((double) preRange[i] * 100.0);
        printf("\t%d: Pressure = %d hPa\tAltitude = %fm (%fft.)\n", i, preRange[i], altitude, altitude*3.28);
    
        FILE* file_in = NULL;
        FILE* file_lat = NULL;
        FILE* file_lon = NULL;
        FILE* file_value = NULL;
        char valueName[10];
        sprintf(valueName, "%c%d", valueType[0], preRange[i]);
        char f_in[100];
        sprintf(f_in, "/Users/tristan/Poly MTL/Weather Study/GRIB Files/04020000/%s%d.csv", valueInFileName, preRange[i]);
        //printf("\t\t%s\n", f_in);

        char f_value[100];
        sprintf(f_value, "/Users/tristan/Poly MTL/Weather Study/Weather Study/%s%d.m", valueType, preRange[i]);
        
        file_in = fopen(f_in, "r");
        file_lat = fopen(f_lat, "w");
        file_lon = fopen(f_lon, "w");
        file_value = fopen(f_value, "w");
        
        if (file_in != NULL) {
            int x, y;
            double lat = 0, lon = 0, value = 0;
            initOutFiles(file_lat, file_lon, file_value, valueName);
            char firstLine[50];
            
            fgets(firstLine, 100, file_in);
            while ((lat != +90.0) || (lon != -1.0)) {
                fscanf(file_in, "%d,\t%d,\t%lf,\t%lf,\t%lf", &x, &y , &lat, &lon, &value);
                //printf("HI\n");
                //printf("%lf  %lf  %lf\n", lat, lon, value);
                if (lat == LAT) {
                    fprintf(file_lat, "%lf\n", lat);
                    fprintf(file_lon, "%lf\n", (lon >= 0 ? lon : 360.0 + lon));
                    fprintf(file_value, "%lf\n", value);
                    //printf("%lf  %lf  %lf\n", lat, lon, value);
                }
            }
            finishOutFiles(file_lat, file_lon, file_value);
        } else {
            printf("Impossible d'ouvrir le fichier file_in: %s\n", f_in);
        }
    }
    return 0;
}
