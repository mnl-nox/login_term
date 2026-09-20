#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdbool.h>

#define PRODUCT_NAME_MAX 100
#define PRODUCT_TYPE_MAX 32
#define PRODUCT_REFERENCE_MAX 64

typedef struct {
    unsigned int id;
    unsigned int user_id;
    char name[PRODUCT_NAME_MAX];
    char type[PRODUCT_TYPE_MAX];
    char reference[PRODUCT_REFERENCE_MAX];
    bool active;
} Product;

void product_init(Product *product);
bool product_validate(const Product *product);
bool product_set_active(Product *product, bool active);

#endif
