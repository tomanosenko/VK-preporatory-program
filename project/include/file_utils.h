
#ifndef PROJECT_INCLUDE_FILE_UTILS_H_
#define PROJECT_INCLUDE_FILE_UTILS_H_

#include "utils.h"

void pesonal_data_write(FILE *ofPTR);
void transaction_write(FILE *ofPtr);
void update_transaction_data(FILE *ofPTR_1, FILE  *ofPTR_2, FILE *updatedrecord);

#endif  // PROJECT_INCLUDE_FILE_UTILS_H_
