// project10_volunteer.c
#include "volunteer.h"
#include "read_line.h"
#include <stdio.h>

int main(void) {
    char code;
    struct volunteer *volunteer_list = NULL;
    printf("Operation Code: a for adding to the list, s for searching, d for deleting from the list, p for printing the list; q for quit.");
    
    while (1) {
        printf("\nEnter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');  // Clear the input buffer

        switch (code) {
            case 'a':
                volunteer_list = add_to_list(volunteer_list);
                break;
            case 's':
                search_list(volunteer_list);
                break;
            case 'p':
                print_list(volunteer_list);
                break;
            case 'd':
                volunteer_list = delete_from_list(volunteer_list);
                break;
            case 'q':
                clear_list(volunteer_list);
                return 0;
            default:
                printf("Illegal code ");
        }
    }
}
