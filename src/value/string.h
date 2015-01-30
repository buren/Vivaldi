#ifndef IL_VALUE_STRING_H
#define IL_VALUE_STRING_H

#include "value.h"

#include <string>

namespace il {

namespace value {

class string : public base {
public:
  string(const std::string& val) : m_val{val} { }

  basic_type* type() const override;
  std::string value() const override;

  std::string& str() { return m_val; }
  const std::string& str() const { return m_val; }

  base* copy() const override;

private:
  std::string m_val;
};

}

}

#endif