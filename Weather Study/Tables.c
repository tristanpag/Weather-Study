//
//  Tables.c
//  Weather Study
//
//  Created by Tristan Pageau on 2019-04-04.
//  Copyright © 2019 Poly MTL. All rights reserved.
//

#include "Tables.h"
#include <stdio.h>
#include <string.h>

void WriteTables(FILE* tableFile) {
    double alt[24];
    double pressure[24];

    alt[0] = 609.600000;
    pressure[0] = 94212.902031;
    alt[1] = 1219.200000;
    pressure[1] = 87510.539207;
    alt[2] = 1828.800000;
    pressure[2] = 81199.603167;
    alt[3] = 2438.400000;
    pressure[3] = 75262.360314;
    alt[4] = 3048.000000;
    pressure[4] = 69681.641624;
    alt[5] = 3657.600000;
    pressure[5] = 64440.832498;
    alt[6] = 4267.200000;
    pressure[6] = 59523.862648;
    alt[7] = 4876.800000;
    pressure[7] = 54915.196022;
    alt[8] = 5486.400000;
    pressure[8] = 50599.820768;
    alt[9] = 6096.000000;
    pressure[9] = 46563.239236;
    alt[10] = 6705.600000;
    pressure[10] = 42791.458022;
    alt[11] = 7315.200000;
    pressure[11] = 39270.978047;
    alt[12] = 7924.800000;
    pressure[12] = 35988.784683;
    alt[13] = 8534.400000;
    pressure[13] = 32932.337913;
    alt[14] = 9144.000000;
    pressure[14] = 30089.562537;
    alt[15] = 9753.600000;
    pressure[15] = 27448.838422;
    alt[16] = 10363.200000;
    pressure[16] = 24998.990784;
    alt[17] = 10972.800000;
    pressure[17] = 22729.280526;
    alt[18] = 11582.400000;
    pressure[18] = 20646.148921;
    alt[19] = 12192.000000;
    pressure[19] = 18753.902886;
    alt[20] = 12801.600000;
    pressure[20] = 17035.083628;
    alt[21] = 13411.200000;
    pressure[21] = 15473.796360;
    alt[22] = 14020.800000;
    pressure[22] = 14055.603073;
    alt[23] = 14630.400000;
    pressure[23] = 12767.389020;
    
    for (int i = 0; i < 24; i++) {
        fprintf(tableFile, "%f\t%f\n", pressure[i], alt[i]);
    }
}
