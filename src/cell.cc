#include "cell.h"

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
  switch (cell.cellType_) {
    case CellType::None:
      os << "?";
      break;
    case CellType::Start:
      os << "X";
      break;
    case CellType::End:
      os << "O";
      break;
    case CellType::Path:
      os << "*";
      break;
    case CellType::Empty:
      os << ".";
      break;
    case CellType::Wall:
      os << "#";
      break;
  }
  return os;
}