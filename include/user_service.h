#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <stdbool.h>

#include "user_store.h"

bool user_service_create(UserStore *store, User *user, unsigned int *created_id);
User *user_service_find(UserStore *store, unsigned int id);
bool user_service_update(UserStore *store, unsigned int id, const User *new_data);
bool user_service_deactivate(UserStore *store, unsigned int id);
bool user_service_reactivate(UserStore *store, unsigned int id);

#endif
