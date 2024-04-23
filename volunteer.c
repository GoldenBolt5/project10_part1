#include "volunteer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct volunteer *add_to_list(struct volunteer *list) {
    char first[NameLen + 1], last[NameLen + 1], email[EmailLen + 1];
    int GradeLvl;
    printf("Enter last name: ");
    read_line(last, NameLen);
    printf("Enter first name: ");
    read_line(first, NameLen);
    printf("Enter email address: ");
    read_line(email, EmailLen);
    printf("Enter grade level: ");
    scanf("%d", &GradeLvl);
    while (getchar() != '\n');
    
    // Check if volunteer already exists
    struct volunteer *current = list;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0 && strcmp(current->last, last) == 0) {
            printf("Volunteer already exists. ");
            return list;
        }
        current = current->next;
    }
    
    // Allocate memory for new volunteer
    struct volunteer *new_volunteer = malloc(sizeof(struct volunteer));
    if (new_volunteer == NULL) {
        printf("Memory allocation failed. ");
        exit(EXIT_FAILURE);
    }
    
    // Initialize new volunteer
    strcpy(new_volunteer->first, first);
    strcpy(new_volunteer->last, last);
    strcpy(new_volunteer->email, email);
    new_volunteer->GradeLvl = GradeLvl;
    new_volunteer->next = NULL;
    
    // Add new volunteer to the list
    if (list == NULL) {
        return new_volunteer;
    } else {
        struct volunteer *current = list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_volunteer;
        return list;
    }
}

void search_list(struct volunteer *list) {
    int GradeLvl;
    printf("Enter grade level: ");
    scanf("%d", &GradeLvl);
    while (getchar() != '\n');
    
    // Search for volunteers with the given grade level
    struct volunteer *current = list;
    int found = 0;
    while (current != NULL) {
        if (current->GradeLvl == GradeLvl) {
            // Print volunteer info
            printf("%-12s%-12s%-30s%5d\n", current->last, current->first, current->email, current->GradeLvl);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("Not found.\n");
    }
}

void print_list(struct volunteer *list) {
    struct volunteer *current = list;
    while (current != NULL) {
        // Print volunteer info
        printf("%-12s%-12s%-30s%5d\n", current->last, current->first, current->email, current->GradeLvl);
        current = current->next;
    }
}

void clear_list(struct volunteer *list) {
    struct volunteer *current = list;
    while (current != NULL) {
        struct volunteer *temp = current;
        current = current->next;
        free(temp);
    }
}

struct volunteer *delete_from_list(struct volunteer *list) {
    char first[NameLen + 1], last[NameLen + 1], email[EmailLen + 1];
    int GradeLvl;
    printf("Enter last name: ");
    read_line(last, NameLen);
    printf("Enter first name: ");
    read_line(first, NameLen);
    printf("Enter email address: ");
    read_line(email, EmailLen);
    printf("Enter grade level: ");
    scanf("%d", &GradeLvl);
    while (getchar() != '\n');
    
    struct volunteer *current = list;
    struct volunteer *prev = NULL;
    struct volunteer *temp;
    int found = 0;
    
    while (current != NULL) {
        if (strcmp(current->first, first) == 0 && strcmp(current->last, last) == 0 &&
            strcmp(current->email, email) == 0 && current->GradeLvl == GradeLvl) {
            found = 1;
            if (prev == NULL) { // Deleting the first node
                list = current->next;
            } else {
                prev->next = current->next;
            }
            temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    if (!found) {
        printf("Volunteer does not exist.\n");
    }
    
    return list;
}
