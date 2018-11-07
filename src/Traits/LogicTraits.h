#ifndef __LOGIC_TRAITS_H__
#define __LOGIC_TRAITS_H__

class LogicTraits {
public:
  static const int FREE;
  static const int BLOCKED;
  static const int PATH;
};

const int LogicTraits::FREE = 0;
const int LogicTraits::BLOCKED = 1;
const int LogicTraits::PATH = 2;

#endif
