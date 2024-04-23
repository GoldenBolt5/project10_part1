// volunteer.h
#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#define EmailLen 100
#define NameLen 30

struct volunteer {
    char first[NameLen + 1];
    char last[NameLen + 1];
    char email[EmailLen + 1];
    int GradeLvl;
    struct volunteer *next;
};

// Function prototypes
struct volunteer *add_to_list(struct volunteer *list);
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
struct volunteer *delete_from_list(struct volunteer *list);

#endif // VOLUNTEER_H
