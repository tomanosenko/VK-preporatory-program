#include <stdio.h>
#include "file_utils.h"

void masterWrite(FILE *ofPTR, Data Client) {
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",  
		"1 Number account: ",
		"2 Client name: ",
		"3 Surname: ",
		"4 Addres client: ",
		"5 Client telnum: ",
		"6 Client indebtedness: ",
		"7 Client credit limit: ",
		"8 Client cash payments: " );
	while( 
        scanf("%d%s%s%s%s%lf%lf%lf",
            &Client.number, 
            Client.name, 
            Client.surname, 
            Client.addres, 
            Client.tel_number, 
            &Client.indebtedness,	
            &Client.credit_limit ,	
            &Client.cash_payments) != -1) {
		        fprintf( ofPTR, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n", 
                    Client.number, 
                    Client.name, 
                    Client.surname, 
                    Client.addres, 
                    Client.tel_number, 
                    Client.indebtedness,	
                    Client.credit_limit ,		 	
                    Client.cash_payments) ;
		        printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",  
				    "1 Number account: ",
				    "2 Client name: ",
				    "3 Surname: ",
				    "4 Addres client: ",
				    "5 Client telnum: ",
				    "6 Client indebtedness: ",
				    "7 Client credit limit: ",
				    "9 Client cash payments:");
	}
}