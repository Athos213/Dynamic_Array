#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"dynamic_array.h"


int main(int argc, char** argv) {
    puts("Dynamic array of strings:");
    dy_array* dy = init_dy(STRING);
    for (int i = 1; i < 20; i++) {
        char buffer[16];
        char str[16] = {"value"};
        sprintf(buffer, "%d", i);
        dy_append(dy, strcat(str, buffer));
        printf("%s\n", dy_get(dy, i-1));
    }
    puts("\nDynamic array of integers:");

    dy_array* da = init_dy(INTEGER);
    for (int i = 1; i < 20; i++) {
        dy_append(da, &i);
        int* num = dy_get(da, i-1);
        printf("%d\n", *num);
    }
    printf("%d\n", dy->count);
    delete_dy(dy);
    delete_dy(da);
}
