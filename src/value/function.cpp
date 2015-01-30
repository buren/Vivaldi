#include "function.h"

#include "gc.h"
#include "lang_utils.h"

using namespace il;

value::function::function(const std::vector<il::symbol>& args,
                          std::shared_ptr<ast::expression> body,
                          environment& outer_env)
  : m_args {args},
    m_body {body},
    m_env  {outer_env}
{ }

value::basic_type* value::function::type() const
{
  throw std::runtime_error{"not yet implemented"};
}

std::string value::function::value() const
{
  return "<function>";
}

value::base* value::function::call(const std::vector<base*>& args)
{
  check_size(m_args.size(), args.size());

  environment call_env{m_env};
  for (auto sz = args.size(); sz--;)
    call_env.assign(m_args[sz], args[sz]);

  return m_body->eval(call_env);
}

value::base* value::function::copy() const
{
  return gc::alloc<function>( m_args, m_body, m_env );
}

#include <iostream>