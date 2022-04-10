#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_
#include <stdio.h>
#include "data_struct.h"

#define PERSONAL_INFORMATION "record.dat"
#define TRANSACTION "transaction.dat"
#define UPDATED_TRANSACTION "blackrecord.dat"

void personal_data_write(const char *inf);
void transaction_write(const char *inf);
void update_transaction_data(const char *record_filename, const char *transaction_filename,
const char *transact_record_filename);

#endif  // PROJECT_INCLUDE_UTILS_H_
