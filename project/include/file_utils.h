
#ifndef GITHUB_GIT_TEST_HW_PROJECT_INCLUDE_FILE_UTILS_H_ 
#define GITHUB_GIT_TEST_HW_PROJECT_INCLUDE_FILE_UTILS_H_ 

#include <stdio.h>
#include "utils.h"

void personal_data_write(FILE *of_p_inf);
void transaction_write(FILE *of_p_inf);
void update_transaction_data(FILE *of_p_inf, FILE  *of_transac, FILE *of_n_transac);

#endif  // GITHUB_GIT_TEST_HW_PROJECT_INCLUDE_FILE_UTILS_H_
