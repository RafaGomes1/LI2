#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.c"

//LEIPL7G04
//KPmLqcRq

int dollarAux(STACK *s, int n) {
    int r = 0;
    while(n>=0) {
        r = pop(s);
        n--;
    }
    return r;
}

void handle(STACK *s, char *token) {
    if (strcmp(token, "+") == 0) {
         int y = pop(s);
         int x = pop(s);
         push(s, x+y);
    }
    else 
    if (strcmp(token, "-") == 0) {
         int y = pop(s);
         int x = pop(s);
         push(s, x-y);
    }
    else
    if (strcmp(token, "*") == 0) {
         int y = pop(s);
         int x = pop(s);
         push(s, x*y);
    }
    else
    if (strcmp(token, "/") == 0) {
         int y = pop(s);
         int x = pop(s);
         push(s, x/y);
    }
    else 
    if (strcmp(token, "%") == 0) {
         int y = pop(s);
         int x = pop(s);
         push(s, x%y);
    }
    else
    if (strcmp(token, ")") == 0) {
         int y = pop(s);
         push(s, y+1);
    }
    else
    if (strcmp(token, "(") == 0) {
         int y = pop(s);
         push(s, y-1);
    }
    else
    if (strcmp(token, "#") == 0) {
         int exp = pop(s);
         int base = pop(s);
         int r = 1;
         while (exp != 0) {
             r*=base;
             exp--;
         }
         push(s, r);
    }
    else
    if (strcmp(token, "&") == 0) {
         int y = pop(s);
         int x = pop(s);
         push(s, x&y);
    }
    else
    if (strcmp(token, "~") == 0) {
         int y = pop(s);
         push(s, ~y);
    }
    else
    if (strcmp(token, "^") == 0) {
         int y = pop(s);
         int x = pop(s);
         push(s, x^y);
    }
    else
    if (strcmp(token, "|") == 0) {
         int y = pop(s);
         int x = pop(s);
         push(s, x|y);
    }
    else 
    if (strcmp(token, "@") == 0) {
         int z = pop(s);
         int y = pop(s);
         int x = pop(s);
         
         push(s, y);
         push(s, z);
         push(s, x);
    }
    else
    if (strcmp(token, "_") == 0) {
         int x = pop(s);
         
         push(s, x);
         push(s, x);
    }
    else
    if (strcmp(token, "$") == 0) {
         int r;
         int n = pop(s);
         STACK *d = new_stack();        
         *d = *s;
         
         r = dollarAux(d, n);
 
         push(s, r);
    }
    else
    if (strcmp(token, ";") == 0) {
         pop(s);
    }
    else
    if (strcmp(token, "\\") == 0) {
         int x = pop(s);
         int y = pop(s);
         
         push(s, x);
         push(s, y);
    }
    else
    if (strcmp(token, "c") == 0) {
         int x = pop(s);
         printf("%c", x);
    }
    else
    if (strcmp(token, "i") == 0) {
         char x = pop(s);
         int y = x;

         push(s,y);
    }
    else {
          int val;
          sscanf(token, "%d", &val);
          push(s, val);
    }
}

int main() {
    STACK *s = new_stack();
    char line[BUFSIZ];
    char token[BUFSIZ];

    if(fgets(line, BUFSIZ, stdin) != NULL) {
        while (sscanf(line, "%s%[^\n]", token, line) == 2) {
            handle(s,token);
        }
        handle(s,token);

        for (int i = 1; i<=s->sp; i++) printf ("%d", s->stack[i]);

            printf("\n");
    }
    
    return 0;
}
