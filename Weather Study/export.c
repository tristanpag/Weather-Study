//
//  export.c
//  Weather Study
//
//  Created by Tristan Pageau on 2019-04-02.
//  Copyright © 2019 Poly MTL. All rights reserved.
//

#include "export.h"
#include "interpol.h"
#include <sys/stat.h>

void initOutFile(FILE *file,  char* valueName) {
    fprintf(file, "%s = [ ", valueName);
}

void finishOutFile(FILE *file) {
    fprintf(file, " ];");
    fclose(file);
}

void export(int nbGribFile, int preRange[], char valueType[], char valueInFileName[], char date[], double latitude) {
    printf("%s\t%s\tlatitude: %f\n", valueType, date, latitude);
    for (int i = 0; i < nbGribFile; i++) {
        double altitude = Pre2Alt_ISA((double) preRange[i] * 100.0);
        printf("\t%d: Pressure = %d hPa\tAltitude = %fm (%fft.)\n", i, preRange[i], altitude, altitude*3.28);
        
        FILE* file_in = NULL;
        FILE* file_value = NULL;
        char valueName[10];
        sprintf(valueName, "%c%d", valueType[0], preRange[i]);
        char f_in[100];
        sprintf(f_in, "/Users/tristan/Poly MTL/Weather Study/GRIB Files/%s/%s%d.csv", date, valueInFileName, preRange[i]);
        //printf("\t\t%s\n", f_in);
        
        char f_value[100];
        char path[100];
        sprintf(path, "/Users/tristan/Poly MTL/Weather Study/Weather Study/%s/%d", date, (int) latitude);
        mkdir(path, S_IRWXU);
        sprintf(f_value, "/Users/tristan/Poly MTL/Weather Study/Weather Study/%s/%d/%s%d.m", date, (int) latitude, valueType, preRange[i]);
        
        file_in = fopen(f_in, "r");
        //file_lat = fopen(f_lat, "w");    // à mettre dans la fonction
        //file_lon = fopen(f_lon, "w");    // exportDrawTemp()
        file_value = fopen(f_value, "w");
        
        if (file_in != NULL) {
            int x, y;
            double lat = 0, lon = 0, value = 0;
            initOutFile(file_value, valueName);
            char firstLine[50];
            
            fgets(firstLine, 100, file_in);
            while ((lat != +90.0) || (lon != -1.0)) {
                fscanf(file_in, "%d,\t%d,\t%lf,\t%lf,\t%lf", &x, &y , &lat, &lon, &value);
                //printf("HI\n");
                //printf("%lf  %lf  %lf\n", lat, lon, value);
                if (lat == latitude) {
                    //fprintf(file_lat, "%lf\n", lat);
                    //fprintf(file_lon, "%lf\n", (lon >= 0 ? lon : 360.0 + lon));
                    fprintf(file_value, "%lf\n", value);
                    //printf("%lf  %lf  %lf\n", lat, lon, value);
                }
            }
            finishOutFile(file_value);
        } else {
            printf("Impossible d'ouvrir le fichier file_in: %s\n", f_in);
        }
    }
}
