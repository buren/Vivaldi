#ifndef IL_EXPRESSION_H
#define IL_EXPRESSION_H

#include "value.h"
#include "environment.h"

namespace il {

namespace ast {

class expression {
public:
  virtual value::base* eval(environment& env) const = 0;

  virtual ~expression() { }
};

class function_definition;
class function_call;
class method_call;
class variable;
class literal;
class type_definition;
class cond_statement;
class while_loop;
class for_loop;
class assignment;
class variable_declaration;
class block;

}

}

#endif