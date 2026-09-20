#ifndef USER_STORE_H
#define USER_STORE_H

#include <stdbool.h>
#include <stddef.h>

#include "user.h"

#define USER_STORE_MAX_USERS 1024

typedef struct {
    User users[USER_STORE_MAX_USERS];
    size_t count;
    unsigned int next_id;
} UserStore;

void user_store_init(UserStore *store);
bool user_store_add(UserStore *store, User *user);
User *user_store_find_by_id(UserStore *store, unsigned int id);
const User *user_store_find_by_id_const(const UserStore *store, unsigned int id);
bool user_store_deactivate(UserStore *store, unsigned int id);
bool user_store_reactivate(UserStore *store, unsigned int id);
size_t user_store_list_active(const UserStore *store, User *out, size_t capacity);

#endif
