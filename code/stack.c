#include <stdlib.h>
#include "stack.h"
///
/// Função que cria uma nova Stack e reserva memoria para a mesma 
/// @param s é a nova Stack que é retornada
STACK *new_stack() {
    STACK *s = (STACK*)malloc(sizeof(STACK));
    s->stack = (STACK_Elem*)malloc(sizeof(STACK_Elem) * 100000);
    s->sp = 0;
    return s;
}

///
/// Funcão que colaca um novo elemento na Stack
/// @param s é a Stack onde vai ser colocado o novo elemento
/// @param elem é o elemento da Stack a ser colocado
void push(STACK *s, STACK_Elem elem) {
    s->sp++;
    s->stack[s->sp] = elem;
}

///
/// Funcão que retira um novo elemento na Stack
/// @param s é a Stack onde vai ser retirado o novo elemento
/// @param ret é o elemento da Stack que foi retirado e é devolvido
STACK_Elem pop(STACK *s) { 
    STACK_Elem ret;
    if (s->sp > 0) {
        ret = s->stack[s->sp];
        s->sp--;
    }
    return ret;
}