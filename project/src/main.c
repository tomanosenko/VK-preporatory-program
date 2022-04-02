
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "file_utils.h"
#include "main_module.h"

enum ACTIONS { ENTER_DATA_CLIENT = 1, ENTER_DATA_TRANSACTION, UPDATE_BASE, TESTING, EXIT = -1 };

int main(void) {
    int choice = 0;
    FILE *p_inf, *transac, *n_transac;
    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
        while (scanf("%d", &choice) != EXIT) {
            switch (choice) {
                case ENTER_DATA_CLIENT:
                    p_inf = fopen(origin, "r+");
                    if (p_inf == NULL) {
                        puts("Not acess");
                    } else {
                    pesonal_data_write(p_inf);
                    fclose(p_inf);
                    }
                    break;
                case ENTER_DATA_TRANSACTION:
                    p_inf = fopen(filename, "r+");
                    if (p_inf == NULL) {
                        puts("Not acess");
                    } else {
                        transaction_write(p_inf);
                    fclose(p_inf);
                    }
                    break;
                case UPDATE_BASE:
                    p_inf = fopen(origin, "r");
                    transac = fopen(filename, "r");
                    n_transac = fopen(b_record, "a+");
                    if (p_inf == NULL || transac == NULL || n_transac == NULL) {
                        puts("exit");
                    } else {
                        update_transaction_data(p_inf, transac, n_transac);
                        fclose(p_inf);
                        fclose(transac);
                        fclose(n_transac);
                    }
                    break;
                    case TESTING:
                    test_write_to_file();
                    break;
                    default:
                        puts("error");
                    break;
                }
        printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
    }
    return 0;
}


