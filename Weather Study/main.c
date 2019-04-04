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
#define LAT 45.0


int main(int argc, const char * argv[]) {
    
    char valueType[] = "Hum";
    char valueInFileName[] = "RH_";
    int altRange[5 * sizeof(int)];
    altRange[0] = 10000;
    altRange[1] = 15000;
    altRange[2] = 20000;
    altRange[3] = 25000;
    altRange[4] = 30000;
    char f_lat[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/lat.m";
    char f_lon[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/lon.m";
    printf("ALTITUDE RANGE\n");
    for (int i = 0; i < 5; i++) {
        printf("\t%d : %d\n", i, altRange[i]);
    
        FILE* file_in = NULL;
        FILE* file_lat = NULL;
        FILE* file_lon = NULL;
        FILE* file_value = NULL;
        char valueName[10];
        sprintf(valueName, "%c%d", valueType[0], altRange[i]);
        char f_in[100];
        sprintf(f_in, "/Users/tristan/Poly MTL/Weather Study/Weather Study/Grib/%s%d.txt", valueInFileName, altRange[i]);
        printf("\t\t%s\n", f_in);

        char f_value[100];
        sprintf(f_value, "/Users/tristan/Poly MTL/Weather Study/Weather Study/%s%d.m", valueType, altRange[i]);
        
        file_in = fopen(f_in, "r");
        file_lat = fopen(f_lat, "w");
        file_lon = fopen(f_lon, "w");
        file_value = fopen(f_value, "w");
        
        if (file_in != NULL) {
            int x, y;
            double lat = 0, lon = 0, value =0;
            initOutFiles(file_lat, file_lon, file_value, valueName);
            while ((lat != +90.0) || (lon != -0.5)) {
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
