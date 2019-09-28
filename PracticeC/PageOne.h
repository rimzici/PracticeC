//
//  PageOne.h
//  PracticeC
//
//  Created by Rimnesh Fernandez on 24/08/19.
//  Copyright © 2019 Rimnesh Fernandez. All rights reserved.
//

#ifndef PageOne_h
#define PageOne_h

#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

long factorial(int n);
_Bool isEven(int n);
int testLoopPostInc(int n);
int testLoopPreInc(int n);
int testMacros(int n);
int triggerCallback(void (* callback) (void));
int insertStudentRecord(char *name);

#endif /* PageOne_h */
