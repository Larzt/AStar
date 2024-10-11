#pragma once
#include <iostream>

#include "utility.h"

enum CellType { None, Wall, Empty, Path, Start, End };

class Cell {
 public:
  Cell() = default;
  Cell(Vector2 p) : position_{p}, cellType_{CellType::None} {};
  Vector2 GetPosition() { return position_; }
  CellType GetType() { return cellType_; }
  void SetType(const CellType& cellType) { cellType_ = cellType; }
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
  ~Cell() {};

 private:
  Vector2 position_;
  CellType cellType_;
};