#include <utils.h>
#include "print.h"
#include "scans.h"
#include <stdlib.h>

void personal_data_write(const char *inf) {
    print_data_fields();
    FILE *new_record_ptr = fopen(inf, "r+");
    if (new_record_ptr == NULL) {
        puts("Not acess");
    }
    Person *Client = malloc(sizeof(Person));
    if (!Client) {
        free(Client);
        puts("Not acess");
    } else {
    while (get_data_record(Client) >0) {
        fprintf_update_transaction(new_record_ptr, *Client);
        print_data_fields();
    }
    }
    if (EOF) {
        fclose(new_record_ptr);
    }
    free(Client);
}

