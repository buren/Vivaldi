#include "boolean.h"

#include "builtins.h"
#include "gc.h"
#include "lang_utils.h"
#include "value/builtin_type.h"

#include <string>

using namespace il;

value::basic_type* value::boolean::type() const
{
  return &builtin::type::boolean;
}

std::string value::boolean::value() const
{
  return m_val ? "true" : "false";
}

value::base* value::boolean::copy() const
{
  return gc::alloc<boolean>( m_val );
}