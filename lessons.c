#include <stdio.h>

//we use typedef to define objects in terms of data member collections
typedef struct Structure {
    int data;
} Structure; //and this is the alias for the struct that allows us to avoid writing 'struct Structure' every time we reference it

//interfaces can be created using function pointers
typedef struct IOInterface {
    int (*readValue)(int address);
    void (*writeValue)(int addres, int value);
} IOInterface;

//function pointers can also be defined as types
typedef int (*FunctionPointerType)(int, char*);


//concept helper functions
int function1(int x, char* string) {
    return 0;
}

int read1(int address) {
    return 1;
}

int read2(int address) {
    return 2;
}

void write1(int address, int value) {
    return;
}

void write2(int address, int value) {
    return;
}



int lessons(char* parameter1, int* parameter2, int* errorCode) {
    //pointer parameter checks are essential in C, as we can't know if we have a valid address or not
    //and we want to start with which ever one we might need to access first
    if (errorCode == NULL) return 1;

    //if you functionr return void, then the function return can be used to handle error codes. If you need to return an object, a pointer to an errorCode is one way around this
    //here I use both to illustrate both ways
    if (parameter1 == NULL || parameter2 == NULL) {
        *errorCode = 1;
        return 1;
    }

    int array[] = { 10, 20, 30 }; //arrays can be initialized with lists
    int* pointer = array; //pointers point to a memmory address, which could represent any object you would like
    int** pointer2pointer = &pointer; //we use double pointers when we want to modify the value being pointed to and address where that value is being kept

    //we can build 2D arrays in these 2 ways
    //first way
    int matrix1[5][5];
    //second way
    int** matrix2 = malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++) {
        matrix2[i] = malloc(sizeof(int) * 5);
    }
    //but they can both be access like with either of these formats
    matrix1[3][3] = 0;
    *(*(matrix1 + 3) + 3) = 0;
    matrix2[3][3] = 0;
    *(*(matrix2 + 3) + 3) = 0;

    //Function Pointers
    //we then can declare and assign function pointers
    FunctionPointerType myFunctionPointer = function1;
    //then we can call it
    myFunctionPointer(10, "hi");

    //when we clear an object from memory
    free(*(*pointer2pointer));
    //we should set the address of the pointer to NULL
    *pointer2pointer = NULL;

    //Interface
    //We can make a interface by creating using a struct with function pointers
    //This how we can polymorphism in C
    IOInterface interface1 = { read1, write2 };
    IOInterface interface2 = { read2, write1 };

    *errorCode = 0;
    return 0;
}


