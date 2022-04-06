
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

#define ERROR "Not access"

enum ACTIONS { ENTER_DATA_CLIENT = 1, ENTER_DATA_TRANSACTION, UPDATE_BASE, EXIT = -1};

int main(void) {
    int choice = 0;
    FILE *p_inf, *transac, *n_transac;
    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
        while (scanf("%d", &choice) != EXIT) {
            switch (choice) {
                case ENTER_DATA_CLIENT:
                    p_inf = fopen(p_information, "r+");
                    if (p_inf == NULL) {
                        fprintf(stderr, ERROR);
                    } else {
                    personal_data_write(p_inf);
                    fclose(p_inf);
                    }
                    break;
                case ENTER_DATA_TRANSACTION:
                    p_inf = fopen(transaction, "r+");
                    if (p_inf == NULL) {
                        fprintf(stderr, ERROR);
                    } else {
                    transaction_write(p_inf);
                    fclose(p_inf);
                    }
                    break;
                case UPDATE_BASE:
                    p_inf = fopen(p_information, "r");
                    transac = fopen(transaction, "r");
                    n_transac = fopen(n_transaction, "a+");
                    if (p_inf == NULL || transac == NULL || n_transac == NULL) {
                        puts("exit");
                    } else {
                        update_transaction_data(p_inf, transac, n_transac);
                        fclose(p_inf);
                        fclose(transac);
                        fclose(n_transac);
                    }
                    break;
                    default:
                        puts("error");
                    break;
                }
        printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
    }
    return 0;
}
