
#include "main_module.h"
#define openfile "Test_config.dat"
#define filename_gold "Test_config.dat.gold"

int main(void) {
    Person expected_data = {1, "Toma", "Nosenko", "Addres", "88005553535", 90, 165, 28};
    write_to_file(filename_gold, expected_data);
    write_to_file(openfile, expected_data);
    read_from_file(openfile,filename_gold);
    return 0;
}
