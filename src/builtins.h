#ifndef IL_BUILTINS_H
#define IL_BUILTINS_H

#include "environment.h"
#include "value.h"

namespace il {

namespace builtin {

namespace function {

extern value::builtin_function gets;
extern value::builtin_function puts;
extern value::builtin_function quit;
extern value::builtin_function make_array;
extern value::builtin_function size;
extern value::builtin_function type;

}

namespace type {

extern value::builtin_type string;
extern value::builtin_type integer;
extern value::builtin_type floating_point;
extern value::builtin_type boolean;
extern value::builtin_type array;
extern value::builtin_type dictionary;
extern value::builtin_type symbol;
extern value::builtin_type iterator;
extern value::builtin_type range;
extern value::builtin_type nil;
extern value::builtin_type custom_type;
extern value::builtin_type custom_object;

}

}

}

#endif