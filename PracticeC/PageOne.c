//
//  PageOne.c
//  PracticeC
//
//  Created by Rimnesh Fernandez on 24/08/19.
//  Copyright © 2019 Rimnesh Fernandez. All rights reserved.
//
#include<stdlib.h>
#include <string.h>

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
    char *(*getName)(int id);
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
    char *ncopy = malloc(sizeof(n));
    printf("TEST sizeof(n): %d", sizeof(n));
    char nn[] = "Rimnesh Fernandez";
    char *nncopy = calloc(1, sizeof(nn));// Use calloc only if all blocks needs to be initialized with 0. Else use malloc
    strcpy(ncopy, n);
    copyString(nncopy, nn);
    printf("n %s \n", n);
    printf("ncopy %s \n", ncopy);
    printf("nn %s \n", nn);
    printf("nncopy %s \n", nncopy);
    char post[] = " is awesome!";
    realloc(nncopy, sizeof(nncopy) + sizeof(post));
    strcat(nncopy, post);
    printf("nncopy %s \n", nncopy);
    free(ncopy);
    free(nncopy);
    
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

void deleteArrayItem(int *sample, int length, int index) {
    printf("length of array : %d\n", length);
    printf("Item at index %d will be removed\n", index);
    for (int c = index - 1 ; c < length - 1 ; c++ )
        sample[c] = sample[c+1];
    
    printf("Resultant array is\n");
    
    for(int c = 0 ; c < length - 1 ; c++ )
        printf("item : %d\n", sample[c]);
}

int array[7] = {1, 2, 3, 101, 5, 99, 0}, n = 7;

void arraySort() {
    int c, d, t;
    
    for (c = 1 ; c <= n - 1; c++) {
        d = c;
        printf("\n d : %d", d);
        while ( d > 0 && array[d] < array[d-1]) {
            t = array[d];
            array[d]   = array[d-1];
            array[d-1] = t;
            d--;
        }
    }
    
    printf("\nSorted list in ascending order:\n");
    
    for (c = 0; c <= n - 1; c++) {
        printf("%d\n", array[c]);
    }
}

void findMaxMin() {
    int maxNum = array[0], minNum = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxNum) {
             maxNum = array[i];
        }
        if (array[i] < minNum) {
            minNum = array[i];
        }
    }
    printf("\n Greatest element is: %d", maxNum);
    printf("\n Lowest element is: %d", minNum);
}

void reverseArray() {
    int len = 5;
    int orgArray[5] = {1, 2, 3, 4, 5};
    int cop[len];
    
    int i = len-1, j = 0;
    while (i >= 0) {
        cop[j] = orgArray[i];
        
        i--;
        j++;
    }
    
    printf("\n Reversed array is: \n");
    for (i = 0; i < len; i++) {
        printf("%d\n", cop[i]);
    }
}

void mergeArray() {
    int n = 5, arrayN[5] = {1, 2, 4, 88, 100};
    int m = 5, arrayM[5] = {29, 30, 44, 120, 1};
    int sortedSize = n + m;
    int sortedArray[sortedSize];
    
    int j = 0, k = 0;
    for (int i = 0; i < sortedSize;) {
        if (j < n && k < m) {
            if (arrayN[j] < arrayM[k]) {
                sortedArray[i] = arrayN[j];
                j++;
            } else {
                sortedArray[i] = arrayM[k];
                k++;
            }
            i++;
        } else if (j == n) {
            sortedArray[i] = arrayM[k];
            k++;
            i++;
        } else {
            sortedArray[i] = arrayN[j];
            j++;
            i++;
        }
    }
    
    printf("\n Merged array is: \n");
    for (int i = 0; i < sortedSize; i++) {
        printf("%d\n", sortedArray[i]);
    }
}

void learnDynamicMemAllocation() {
    int arrayOne[4] = {22, 33, 12, 32};
    int length = sizeof(arrayOne) / sizeof(int);
    int *sizeOne = malloc(sizeof(arrayOne));
    printf("\n TEST sizeOne: %d", *sizeOne);
    printf("\n TEST sizeOne[0]: %d", sizeOne[0]);
    for (int i = 0; i < length; i++) {
        sizeOne[i] = arrayOne[i];
        printf("\n TEST sizeOne[i]: %d", sizeOne[i]);
    }
    
    int arrayTwo[4] = {222, 333, 122, 322};
    int *sizeTwo = calloc(1, sizeof(arrayTwo));
    int length2 = sizeof(arrayTwo) / sizeof(int);
    printf("\n TEST sizeTwo: %d", *sizeTwo);
    printf("\n TEST sizeTwo[0]: %d", sizeTwo[0]);
    for (int i = 0; i < length2; i++) {
        sizeTwo[i] = arrayOne[i];
        printf("\n TEST sizeTwo[i]: %d", sizeTwo[i]);
    }
    
    int *sizeThree = sizeTwo;
    int length3 = (sizeof(arrayOne) / sizeof(int)) + (sizeof(arrayTwo) / sizeof(int));
    sizeThree = realloc(sizeTwo, sizeof(arrayOne) + sizeof(arrayTwo));
    int a = 0, b = 0;
    for (int i = 0; i < length3; i++) {
        if (i < length) {
            sizeThree[i] = arrayOne[a];
            a++;
        }
        if (i >= length) {
            sizeThree[i] = arrayTwo[b];
            b++;
        }
        printf("\n TEST sizeThree[i]: %d", sizeThree[i]);
    }
}

void lower_string(char s[]) {
   int c = 0;
   
   while (s[c] != '\0') {
      if (s[c] >= 'A' && s[c] <= 'Z') {
         s[c] = s[c] + 32;
      }
      c++;
   }
}

void removeChar(char *s, int c){
  
    int j, n = strlen(s);
    for (int i=j=0; i<n; i++)
       if (s[i] != c)
          s[j++] = s[i];
      
    s[j] = '\0';
}

int valueInArray(char val, char arr[])
{
    int i;
    for(i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if(arr[i] == val)
            return 1;
    }
    return 0;
}

char *getRelationC(char *nameOne, char *nameTwo) {
    
    if (strlen(nameOne) == 0) {
        return "name one is empty";
    }
    if (strlen(nameTwo) == 0) {
        return "name two is empty";
    }
    
    lower_string(nameOne);
    lower_string(nameTwo);

    char *n1 = malloc(sizeof(nameOne)), (*n2) = malloc(sizeof(nameTwo));
    strcpy(n1, nameOne);
    strcpy(n2, nameTwo);
    
    for (int i = 0; i < strlen(nameOne); i++) {
        if (strchr(nameTwo, nameOne[i]) != NULL) {
            removeChar(n2, nameOne[i]);
            removeChar(n1, nameOne[i]);
        }
    }
    
    int fCount = strlen(n1) + strlen(n2);
    
    if (fCount == 0) {
        return "ALIENS!!";
    }
    
    char REL[] = {'F','L','A','M','E','S'};
    int FINAL_EXCLUDED_COUNT = (sizeof(REL) / sizeof(REL[0])) - 1;
    char *EXCLUDED;
    EXCLUDED = malloc(FINAL_EXCLUDED_COUNT);
    int EXCLUDED_COUNT = 0;

    int counter = 0;
    while (EXCLUDED_COUNT != FINAL_EXCLUDED_COUNT) {
        for (int index = 0; index <= FINAL_EXCLUDED_COUNT; index++) {
            if (!valueInArray(REL[index], EXCLUDED)) {
                counter += 1;
                if (counter == fCount) {
                    EXCLUDED_COUNT += 1;
                    EXCLUDED[index] = REL[index];
                    counter = 0;
                }
            }
            if (EXCLUDED_COUNT == FINAL_EXCLUDED_COUNT) {
                break;
            }
        }
    }
    
    char FOUND;
    for (int index = 0; index <= FINAL_EXCLUDED_COUNT; index++) {
        if (!valueInArray(REL[index], EXCLUDED)) {
            FOUND = REL[index];
        }
    }
    
    switch (FOUND) {
        case 'F':
            return "FRIENDS";
        case 'L':
            return "LOVERS";
        case 'A':
            return "AFFECTIONATE";
        case 'M':
            return "MARRIAGE";
        case 'E':
            return "ENEMIES";
        case 'S':
            return "SIBLINGS";
        default:
            return "ALIENS!!";
    }
}
