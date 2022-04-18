
#ifndef PROJECT_INCLUDE_PRINT_H_
#define PROJECT_INCLUDE_PRINT_H_

#include <stdio.h>
#include "data_struct.h"

void show_options();
void print_data_fields();
void print_data_transact_fields();
int fprintf_update_transaction(FILE *transaction_ptr, Person client_data);

#endif   // PROJECT_INCLUDE_PRINT_H_
