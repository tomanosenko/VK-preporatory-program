
#include "utils.h"

void update_transaction_data(FILE *of_p_inf, FILE  *of_transac, FILE *of_n_transac) {
    Data client_data, transfer;
    while (
        fscanf(of_p_inf, "%d%10s%10s%10s%10s%lf%lf%lf",
                &client_data.number,
                client_data.name,
                client_data.surname,
                client_data.addres,
                client_data.tel_number,
                &client_data.indebtedness,
                &client_data.credit_limit,
                &client_data.cash_payments) != -1 ) {
            while (fscanf(of_transac, "%d %lf",  &transfer.number , &transfer.cash_payments) !=  -1) {
                if ((client_data.number == transfer.number) && (transfer.cash_payments) != 0) {
                    client_data.credit_limit += transfer.cash_payments;
                }
            }
            fprintf(of_n_transac, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                    client_data.number,
                    client_data.name,
                    client_data.surname,
                    client_data.addres,
                    client_data.tel_number,
                    client_data.indebtedness,
                    client_data.credit_limit,
                    client_data.cash_payments);
            rewind(of_transac);
            rewind(of_n_transac);
    }
}
