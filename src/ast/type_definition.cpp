#include "type_definition.h"

#include "gc.h"
#include "value/custom_type.h"

using namespace il;

ast::type_definition::type_definition(
    symbol name,
    symbol parent,
    const std::vector<symbol>& public_mems,
    const std::unordered_map<
              il::symbol,
              std::shared_ptr<ast::function_definition>>& m_methods)

  : m_name    {name},
    m_parent  {parent},
    m_members {public_mems},
    m_methods {m_methods}
{ }

value::base* ast::type_definition::eval(environment& env) const
{
  return env.assign(m_name,
                    gc::alloc<value::custom_type>( m_members, m_methods, env ));
}