//
//  export.c
//  Weather Study
//
//  Created by Tristan Pageau on 2019-04-02.
//  Copyright © 2019 Poly MTL. All rights reserved.
//

#include "export.h"

void initOutFiles(FILE *file_lat, FILE *file_lon, FILE *file_value, char* valueName) {
    fprintf(file_lat, "Lat = [ ");
    fprintf(file_lon, "Lon = [ ");
    fprintf(file_value, "%s = [ ", valueName);
}

void finishOutFiles(FILE *file_lat, FILE *file_lon, FILE *file_value) {
    fprintf(file_lat, " ];");
    fprintf(file_lon, " ];");
    fprintf(file_value, " ];");
    
    fclose(file_lat);
    fclose(file_lon);
    fclose(file_value);
}
