#include "grid.h"

Grid::Grid(const std::vector<std::string> &maze, const Vector2 &dimensions) {
  maze_info_ = maze;
  dimension_ = dimensions;
  grid_ = new Cell *[dimension_.x + 2];         // x-dimension
  for (int x = 0; x < dimension_.x + 2; ++x) {  // Allocate y-dimension for each row
    grid_[x] = new Cell[dimension_.y + 2];

    for (int y = 0; y < dimension_.y + 2; ++y) {
      Vector2 pos = {x - 1, y - 1};  // Adjust for -1 offset in position
      grid_[x][y] = Cell(pos);       // Initialize Cell with adjusted position
    }
  }
  SetCellType();
}

void Grid::SetCellType() {
  for (int x = 0; x < dimension_.x; ++x) {
    for (int y = 0; y < dimension_.y; ++y) {
      int cell_type_readed = maze_info_[x][y] - '0';
      switch (cell_type_readed) {
        case 0:
          grid_[x][y].SetType(CellType::Empty);
          break;
        case 1:
          grid_[x][y].SetType(CellType::Wall);
          break;
        case 3:
          grid_[x][y].SetType(CellType::Start);
          break;
        case 4:
          grid_[x][y].SetType(CellType::End);
          break;
      }
    }
  }
}

std::ostream &operator<<(std::ostream &os, const Grid &grid) {
  Vector2 dimension = grid.GetDimension();
  for (int x = 0; x < dimension.x; ++x) {
    for (int y = 0; y < dimension.y; ++y) {
      os << grid.GetGrid()[x][y];
    }
    os << std::endl;
  }
  return os;
}
