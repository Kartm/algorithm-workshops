#include <iostream>
#include <cstdlib>

typedef struct{
    int x[A][B];
    long y;
} str1;

typedef struct{
    char array[B];
    int t;
    short s[A];
    long u;
} str2;

void set_val(str1* p, str2* q){
    long u1 = q -> t;
    long u2 = q -> u;
    p -> y = u1 + u2;
}

int main()
    ///jakie wartosci ma A i B
}

/*
set_val:
    mouslq 8(%rsi), %rax
