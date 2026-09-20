#ifndef USER_H
#define USER_H

#include <stdbool.h>

#define USER_NAME_MAX 100
#define USER_PHONE_MAX 32
#define USER_LOGIN_MAX 64

typedef struct {
    unsigned int id;
    char name[USER_NAME_MAX];
    char phone[USER_PHONE_MAX];
    char username[USER_LOGIN_MAX];
    bool active;
} User;

void user_init(User *user);
bool user_validate(const User *user);
bool user_set_active(User *user, bool active);

#endif
