#include <stdio.h>

// take phone # in the form (xxx) xxx-xxxx and displays it in the form xxx.xxx.xxx:
// Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
// You entered 404.817.6900

int main() {
    int area_code, tel_prefix, line_num;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");

    if (scanf("(%d) %d-%d", &area_code, &tel_prefix, &line_num) != 3) {
        printf("invalid input!! enter valid phone number format (xxx) xxx-xxxx \n");
        return 1;
    }; 

    //scanf("(%d) %d-%d", &area_code, &tel_prefix, &line_num);

    printf("You entered %d.%d.%d\n", area_code, tel_prefix, line_num);

    return 0;
}