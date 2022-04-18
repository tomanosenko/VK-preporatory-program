#include "data_struct.h"
#include "print.h"

void show_options() {
    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
}

void print_data_fields() {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
        "1 Number account: ",
        "2 Client name: ",
        "3 Surname: ",
        "4 Addres client: ",
        "5 Client Telnum: ",
        "6 Client indebtedness: ",
        "7 Client credit limit: ",
        "8 Client cash payments: ");
}

void print_data_transact_fields() {
    printf("%s\n%s\n",
          "1 Number account: ",
          "2 Client cash payments: ");
}

int fprintf_update_transaction(FILE *transaction_ptr, Person client_data) {
    return fprintf(transaction_ptr, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
        client_data.number,
        client_data.name,
        client_data.surname,
        client_data.addres,
        client_data.tel_number,
        client_data.indebtedness,
        client_data.credit_limit,
        client_data.cash_payments);
}

