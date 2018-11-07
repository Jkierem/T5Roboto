#ifndef __LOGIC_TRAITS_H__
#define __LOGIC_TRAITS_H__

class LogicTraits {
public:
  static const int FREE;
  static const int PATH;
  static const int BLOCKED;

  static const int ERROR;
  static const int SUCCESS;
};

const int LogicTraits::FREE = 0;
const int LogicTraits::PATH = 1;
const int LogicTraits::BLOCKED = 2;
const int LogicTraits::ERROR = 3;
const int LogicTraits::SUCCESS = 4;

#endif
