#include "member.h"

#include "vm/instruction.h"

using namespace il;

ast::member::member(std::unique_ptr<ast::expression>&& object, il::symbol name)
  : m_object {move(object)},
    m_name   {name}
{ }

std::vector<vm::command> ast::member::generate() const
{
  auto vec = m_object->generate();
  vec.emplace_back(vm::instruction::mem, m_name);
  return vec;
}
