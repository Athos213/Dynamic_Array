# Integer/String Dynamic Array Implementation
**Author:** Stan Lyakhov

## Acknowledgments
 - [Andrew Quach](https://github.com/Aqcurate/) for inspiration and makefile assistance.

## Dynamic Array Implementation
In this project, I attempt to create a resizable structure similar to java's ArrayList that would support both integer and string entries. 
The dynamic array uses a union and an enumeration to handle both types of input:
```c
//Determines the type the list supports
typedef enum Type {INTEGER, STRING} Type;

//The elements of the list could either be integers or strings
typedef union element {
    char** string;
    int integer;
} element;
```
The different handling of string and integers throughout the program is achieved through the use of switch statements. This is one example from the new_element function.
```c
//el represents the newly created element
switch (type) {
    case INTEGER: el->integer = *((int*)value); break;
    case STRING: el->string = strdup((char*)value); break;
}
```
The resizing of the list is done by creating another list with a larger size, copying over the values from the old list to the new list, and swapping the pointers to the element arrays between the two lists. The new list is always double the size of the previous one.
```c
dy_array* new_da = new_array(new_size, da->type);
... //Copy over the elements to the new array

const int temp_size = new_da->size;
new_da->size = da->size;
da->size = temp_size;

const element** temp_arr = new_da->arr;
new_da->arr = da->arr;
da->arr = temp_arr;

delete_dy(new_da);
```

## Not Implemented(yet):
- The list does not resize down when elements are removed.

## Usage
A test function can be found in the source directory. To execute the test file, run the following in the root directory of the repository:

    $ make
    $ bin/dy_array.out

To remove the binaries:

    $ make clean

