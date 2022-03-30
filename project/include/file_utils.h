
#ifndef FILE_UTILS_H_
#define FILE_UTILS_H_

#include "utils.h"

void masterWrite(FILE *ofPTR);
void transaction_write(FILE *ofPtr);
void update_record(FILE *ofPTR_1, FILE  *ofPTR_2, FILE *updatedrecord);

#endif //FILE_UTILS_H_
