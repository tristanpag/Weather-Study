//
//  main.c
//  Weather Study
//
//  Created by Tristan Pageau on 2019-04-02.
//  Copyright © 2019 Poly MTL. All rights reserved.
//

#include <stdio.h>
#include "export.h"


int main(int argc, const char * argv[]) {
    
    FILE* file_in = NULL;
    FILE* file_lat = NULL;
    FILE* file_lon = NULL;
    FILE* file_value = NULL;
    char valueName[4] = "val";
    char f_in[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/TMP_10000.txt";
    char f_lat[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/lat.m";
    char f_lon[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/lon.m";
    char f_value[] = "/Users/tristan/Poly MTL/Weather Study/Weather Study/value.m";
    
    file_in = fopen(f_in, "r");
    file_lat = fopen(f_lat, "w");
    file_lon = fopen(f_lon, "w");
    file_value = fopen(f_value, "w");
    
    if (file_in != NULL) {
        int x, y;
        double lat = 0, lon = 0, value =0;
        initOutFiles(file_lat, file_lon, file_value, valueName);
        while (lat != 90.0 && lon != -0.5) {
            fscanf(file_in, "%d,\t%d,\t%lf,\t%lf,\t%lf", &x, &y , &lat, &lon, &value);
            fprintf(file_lat, "%lf\n", lat);
            fprintf(file_lon, "%lf\n", lon);
            fprintf(file_value, "%lf\n", value);
        }
        
        finishOutFiles(file_lat, file_lon, file_value);
    } else {
        printf("Impossible d'ouvrir le fichier file_in\n");
    }
    return 0;
}
