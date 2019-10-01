//
//  PageOne.c
//  PracticeC
//
//  Created by Rimnesh Fernandez on 24/08/19.
//  Copyright © 2019 Rimnesh Fernandez. All rights reserved.
//
#include<stdlib.h>

#include "PageOne.h"

long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n-1);
}

_Bool isEven(int n) {
    return n % 2 == 0;
}

int testLoopPostInc(int n) {
    int data [20];
    int i;
    for(i = 0; i < n; i++) {
        data[i] = i;
        printf("TEST post %d \n", i);
        printf("TEST post data[i] %d \n", data[i]);
    }
    return 0;
}

int testLoopPreInc(int n) {
    int data [20];
    int i;
    for(i = 0; i < n; ++i) {
        data[i] = i;
        printf("TEST pre %d \n", i);
        printf("TEST pre data[i] %d \n", data[i]);
    }
    return 0;
}

#define MACRO_ONE(n, m) n * m
#define MACRO_TWO(n, m) (n) * (m)
int testMacros(int n) {
    printf("MACRO_ONE %d \n", MACRO_ONE(4 + 4, 2 + 6));
    printf("MACRO_TWO %d \n", MACRO_TWO(4 + 4, 2 + 6));
    return 1;
}

int callbackFunctionC() {
    printf("inside callbackFunctionC \n");
    return 0;
}

int triggerCallbackInC(void (* callbackC) (void)) {
    printf("inside triggerCallbackInC \n");
    callbackC();
    return 0;
}

int triggerCallback(void (* callbackInSwift) (void)) {
    printf("inside triggerCallback \n");
    callbackInSwift();
    triggerCallbackInC(callbackFunctionC);
    return 0;
}

typedef struct {
    void (*setId)(int id);
    void (*setName)(int id, char name[30]);
    char * (*getName)(int id);
} StudentRecord;

int insertStudentRecord (char *name) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    printf("inside insertStudentRecord name %s\n", name);
    rc = sqlite3_open(name, &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

void testStatic() {
    static int count = 0;
    int autoVariable = 0;
    count++;
    autoVariable++;
    char postscript1[] = "time";
    char postscript2[] = "times";
    char *ps = count == 1 ? malloc(sizeof(postscript1)) : malloc(sizeof(postscript2));
    strcpy(ps, count == 1 ? postscript1 : postscript2);
    printf("[static]: testStatic is called %d %s \n", count, ps);
    printf("[auto]: testStatic is called %d %s \n", autoVariable, postscript1);
}

int callByValue(int x) {
    return x*=2;;
}

int callByReference(int *x) {
    return *x*=2;
}
void copyString (char *target, char *source);
void testPointers() {
    char n[] = "Rimnesh Fernandez";
    char ncopy[20];
    char nn[] = "Rimnesh Fernandez";
    char nncopy[20];
    strcpy(ncopy, n);
    copyString(nncopy, nn);
    printf("n %s \n", n);
    printf("ncopy %s \n", ncopy);
    printf("nn %s \n", nn);
    printf("nncopy %s \n", nncopy);
    
}

void copyString(char *target, char *source)
{
    while(*source)
    {
        *target = *source;
        source++;
        target++;
    }
    *target = '\0';
}
