#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include "data_struct.h"

#define p_information "record.dat"
#define transaction "transaction.dat"
#define n_transaction "blackrecord.dat"

void personal_data_write(FILE *of_p_inf);
void transaction_write(FILE *of_p_inf);
void update_transaction_data(FILE *of_p_inf, FILE  *of_transac, FILE *of_n_transac);

#endif  //  PROJECT_INCLUDE_UTILS_H_
