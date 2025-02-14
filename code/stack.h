/// tamanho maximo para a Stack
#define MAX_STACK 100000
/// tamanho maximo para uma String
#define MAX_STRING 10000


///
/// Todos os tipos que podem ser guardados na Stack
/// @param typedef define uma estrutura
/// @param enum é o tipo de elemento do array
typedef enum {
    Char, 
    Int,
    Long,
    Float, 
    String, 
    Double,
    Array,
    Empty,
    Bloco
} TYPE;

struct STACK_Elem;

///
/// A Stack é composta por elementos da Stack e um pointer para o topo da Stack 
/// @param STAC_Elem é um elemento da Stack
///@param stack é um pointer para um elemento da Stack
/// @see STACK_Elem
/// @param int é um inteiro que indica o topo da Stack
/// @param sp é um pointer para o topo da Stack
/// @param struck define uma estrutura
typedef struct STACK{
    /// @param sp é um pointer para o topo da Stack
    /// @param struck define uma estrutura
    struct STACK_Elem *stack;
    int sp;
} STACK;

///
/// Um elemento da Stack tem
/// @param t Um tipo de TYPE @see TYPE
/// @param TYPE é o tipo de dado guardado na union
/// @param saved_value Um elemento da union que pode ser um dos tipos de informação de @see TYPE
typedef struct STACK_Elem{
    /// Tipo de STACK_Elem
    TYPE t;
    /// Union saved_value
    union saved_value {
        /// @param c é um unico caracter que pode ser guardado como elemento da Stack
        char c;
        /// @param str é (uma string) ou array de caracters que pode ser guardado como elemento da Stack
        char *str;
        /// @param d é um numero (floating-point 64bit) que pode ser guardado como elemento da Stack
        double d;
        /// @param l é um numero (64bits) que pode ser guardado como elemento da Stack
        long l;
        /// @param f é um numero (floating-point 32bit) que pode ser guardado como elemento da Stack
        float f;
        /// @param i é um numero (16bits) que pode ser guardado como elemento da Stack
        int i; 
        /// @param STACK o array é em si em Stack
        /// @param arr é um array de tipo Stack que pode ser guardado como elemento da Stack
        STACK* arr;
    } saved_value;
} STACK_Elem;

STACK *new_stack();
void push(STACK *s, STACK_Elem elem);
STACK_Elem pop(STACK *s);