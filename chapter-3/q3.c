#include <stdio.h>

// Enter ISBN: 978-0-393-97950-3
// GS1 prefix: 978
// Group identifier: 0
// Publisher code: 393
// Item number: 97950
// Check digit: 3
// Note: The number of digits in each group may vary

int main() {
    int gs1_prefix, group_identifier, publisher_code, item_number, check_digit;

    printf("Enter ISBN (13-digits in valid format): \n");

    if (scanf("%d-%d-%d-%d-%d", &gs1_prefix, &group_identifier, &publisher_code, &item_number, &check_digit) != 5) { // 5 means 5 values are expected to be read
        printf("invalid format, try again \n");
        return 1; 
    }
    //scanf("%d-%d-%d-%d-%d", &gs1_prefix, &group_identifier, &publisher_code, &item_number, &check_digit);

    printf("GS1 prefix: %d\n", gs1_prefix);
    printf("Group identifier: %d\n", group_identifier);
    printf("Publisher code: %d\n", publisher_code);
    printf("Item number: %d\n", item_number);
    printf("Check digit: %d\n", check_digit);

    return 0;
}