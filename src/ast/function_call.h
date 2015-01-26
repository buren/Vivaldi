#ifndef IL_AST_FUNCTION_CALL_H
#define IL_AST_FUNCTION_CALL_H

#include "expression.h"

namespace il {

namespace ast {

class function_call : public expression {
public:
  function_call(symbol name,
                std::vector<std::unique_ptr<ast::expression>>&& args);

  value::base* eval(environment& env) const override;

private:
  symbol m_function_name;
  std::vector<std::unique_ptr<ast::expression>> m_args;
};

}

}

#endif
