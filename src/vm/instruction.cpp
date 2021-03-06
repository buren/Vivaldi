#include "instruction.h"

using namespace vv;

namespace {

vm::nil_t nil{};

}

vm::command::command(instruction new_instr, int new_arg)
  : instr {new_instr},
    arg   {new_arg}
{ }

vm::command::command(instruction new_instr, symbol new_arg)
  : instr {new_instr},
    arg   {new_arg}
{ }

vm::command::command(instruction new_instr, bool new_arg)
  : instr {new_instr},
    arg   {new_arg}
{ }

vm::command::command(instruction new_instr, const std::string& new_arg)
  : instr {new_instr},
    arg   {new_arg}
{ }

vm::command::command(instruction new_instr, double new_arg)
  : instr {new_instr},
    arg   {new_arg}
{ }

vm::command::command(instruction new_instr, const function_t& new_arg)
  : instr {new_instr},
    arg   {new_arg}
{ }

vm::command::command(instruction new_instr, const type_t& new_arg)
  : instr {new_instr},
    arg   {new_arg}
{ }

vm::command::command(instruction new_instr)
  : instr {new_instr},
    arg   {nil}
{ }
