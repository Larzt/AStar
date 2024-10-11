#pragma once
#include <iostream>
#include <vector>

#include "cell.h"
#include "utility.h"

class Grid {
 public:
  Grid(const std::vector<std::string>&, const Vector2&);
  ~Grid() {};
  void SetCellType();
  Cell** GetGrid() const { return grid_; }
  Vector2 GetDimension() const { return dimension_; }
  friend std::ostream& operator<<(std::ostream& os, const Grid& grid);

 private:
  std::vector<std::string> maze_info_;
  Vector2 dimension_;
  Cell** grid_;
};