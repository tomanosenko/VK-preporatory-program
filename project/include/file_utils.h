
#ifndef FILE_UTILS_H_
#define FILE_UTILS_H_

#include "utils.h"

void masterWrite(FILE *ofPTR, Data Client);
void transactionWrite(FILE *ofPtr, Data transfer);
void update_record(FILE *ofPTR_1, FILE  *ofPTR_2, FILE *updatedrecord, Data client_data, Data transfer);

#endif //FILE_UTILS_H_
