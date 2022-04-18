
#ifndef PROJECT_INCLUDE_SCANS_H_
#define PROJECT_INCLUDE_SCANS_H_

#include <stdio.h>
#include "utils.h"
#include "data_struct.h"

int get_data_record(Person *data);
int get_data_file(FILE *filename, Person *data);

#endif   // PROJECT_INCLUDE_SCANS_H_
