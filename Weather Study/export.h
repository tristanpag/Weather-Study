//
//  export.h
//  Weather Study
//
//  Created by Tristan Pageau on 2019-04-02.
//  Copyright © 2019 Poly MTL. All rights reserved.
//

#ifndef export_h
#define export_h

#include <stdio.h>

void initOutFiles(FILE *file_lat, FILE *file_lon, FILE *file_value, char* valueName);
void finishOutFiles(FILE *file_lat, FILE *file_lon, FILE *file_value);

void export(int nbGribFile, int preRange[], char valueType[], char valueInFileName[], char date[], double latitude);

#endif /* export_h */
