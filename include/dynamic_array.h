#ifndef DYNAMIC_ARRAY_H

#define DYNAMIC_ARRAY_H

typedef enum Type {INTEGER, STRING} Type;

typedef union element {
    char** string;
    int integer;
} element;

typedef struct dy_array {
    int count;
    int size;
    Type type;
    element** arr;
} dy_array;

dy_array* init_dy(Type type);

void delete_dy(dy_array* da);

void dy_append(dy_array* da, const void* c);

void dy_insert(dy_array* da, const void* c, int index);

void dy_remove(dy_array* da, int index);

void dy_pop(dy_array* da);

void* dy_get(dy_array* da, const int index);

#endif
