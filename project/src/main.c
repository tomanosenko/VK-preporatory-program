
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "file_utils.h"
#include "main_module.h"

enum ACTIONS { ENTER_DATA_CLIENT = 1, ENTER_DATA_TRANSACTION, UPDATE_BASE, TESTING, EXIT = -1 };

int main(void) {
    int choice = 0;
    FILE *Ptr, *Ptr_2, *Ptr_3;
    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
        while (scanf("%d", &choice) != EXIT) {
            switch (choice) {
                case ENTER_DATA_CLIENT:
                    Ptr = fopen(origin, "r+");
                    if (Ptr == NULL) {
                        puts("Not acess");
                    } else {
                    pesonal_data_write(Ptr);
                    fclose(Ptr);
                    }
                    break;
                case ENTER_DATA_TRANSACTION:
                    Ptr = fopen(filename, "r+");
                    if (Ptr == NULL) {
                        puts("Not acess");
                    } else {
                        transaction_write(Ptr);
                    fclose(Ptr);
                    }
                    break;
                case UPDATE_BASE:
                    Ptr = fopen(origin, "r");
                    Ptr_2 = fopen(filename, "r");
                    Ptr_3 = fopen(b_record, "a+");
                    if (Ptr == NULL || Ptr_2 == NULL || Ptr_3 == NULL) {
                        puts("exit");
                    } else {
                        update_transaction_data(Ptr, Ptr_2 , Ptr_3);
                        fclose(Ptr);
                        fclose(Ptr_2);
                        fclose(Ptr_3);
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

