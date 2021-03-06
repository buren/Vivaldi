#include "lang_utils.h"

#include "builtins.h"
#include "gc.h"
#include "value/boolean.h"

bool vv::truthy(const value::base* val)
{
  if (val->type == &builtin::type::nil)
    return false;
  else if (val->type == &builtin::type::boolean)
    return static_cast<const value::boolean*>(val)->val;
  return true;
}

vv::value::base* vv::throw_exception(const std::string& value, vm::machine& vm)
{
  vm.push_str(value);
  vm.except();
  return vm.retval;
}

vv::value::base* vv::throw_exception(value::base* value, vm::machine& vm)
{
  vm.retval = value;
  vm.except();
  return vm.retval;
}

vv::value::base* vv::get_arg(vm::machine& vm, size_t idx)
{
  return *(end(vm.frame->parent->pushed) - vm.frame->args + idx);
}

vv::value::base* vv::find_method(value::type* type, symbol name)
{
  while (&type->parent != type && !type->methods.count(name))
    type = static_cast<value::type*>(&type->parent);
  if (type->methods.count(name))
    return type->methods[name];

  return nullptr;
}

int to_int(const std::string& str);
