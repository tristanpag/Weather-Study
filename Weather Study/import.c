//
//  import.c
//  Weather Study
//
//  Created by Tristan Pageau on 2019-04-02.
//  Copyright © 2019 Poly MTL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "import.h"



/*********************************************************/
/* Lecture d'une ligne dans un fichier ASCII (K&R p.165) */
/*********************************************************/

int getlineLoc(FILE *fp, char *line, int max)
{
    
    if ( fgets(line, max, fp) == NULL )
        return 0;
    else
        return strlen(line);
    
}

/****************************************************************************/
/* Lecture d'une ligne d'un fichier .csv et inscription dans la grille temp */
/* des champs retenus: lat , lon , valMeteo                                 */
/****************************************************************************/
void LectureLigneCSV(char *line, double *lat, double *lon, double *valMeteo){
    
    char nombcar[20];
    int i, j;
    
    i = 0;
    while(line[i++] != ','){} /* chercher indice X */
    while(line[i++] != ','){} /* chercher indice Y */
    
    i++; j = 0;
    nombcar[j] = line[i];
    while (line[i] != ','){nombcar[++j] = line[++i];} /* chercher latitude */
    nombcar[j+1] = '\0';
    *lat = atof(nombcar);
    
    i++; j = 0;
    nombcar[j] = line[i];
    while (line[i] != ','){nombcar[++j] = line[++i];} /* chercher longitude */
    nombcar[j+1] = '\0';
    *lon = atof(nombcar);
    
    i++; j = 0;
    nombcar[j] = line[i];
    while (line[i] != ',' && line[i] != '\0'){nombcar[++j] = line[++i];} /* chercher valeur meteo */
    nombcar[j+1] = '\0';
    *valMeteo = atof(nombcar);
    
}


