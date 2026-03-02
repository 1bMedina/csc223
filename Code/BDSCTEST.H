#include <stdio.h>

unsigned t;
unsigned pT;
unsigned fT;

unsigned a;
unsigned pA;
unsigned fA;

unsigned curA;
unsigned fCurT;

unsigned first;

START_TESTING(file)
char* file;
{
    t = 0;
    pT = 0;
    fT = 0;

    a = 0;
    pA = 0;
    fA = 0;

    fCurT = 0;
    curA = 0;
    first = 1;

    printf("\n\n--- %s ---\n", file);
}

incPass(){
    if(!fCurT){
        if(t != 0){
            pT++;
        }
    }
}

#define TEST_CASE(d) printf("\n%s\n", d); t++; incPass(); curA = 0; fCurT = 0;

ASSERT(x)
int x;
{
    if(x){
        PASS();
    } else {
        FAIL();
    }
}

#define ASSERT_EQU(x,y) if(x==y) PASS(); else FAIL();

ASSERT_STR(x,y)
char *x[], *y[];
{
    if(strcmp(x,y)==0){
        PASS();
    } else {
        FAIL();
    }
}

PASS(){
    a++;
    curA++;
    pA++;
    printf("assert %d ok\n", curA);
}

FAIL(){
    a++;
    curA++;
    if(!fCurT){
        fCurT = 1;
        fT++;
    }
    fA++;
    printf("assert %d not ok\n", curA);
}

END_TESTING(){
    incPass();

    printf("\n======\n");
    printf("%d tests\n", t);
    printf("%d passed %d failed\n", pT, fT);
    printf("%d asserts\n", a);
    printf("%d passed %d failed\n", pA, fA);
    printf("======\n");
}