#include "grid.h"

Grid::Grid(const std::vector<std::string> &maze, const Vector2 &dimensions) {
  maze_info_ = maze;
  dimension_ = dimensions;
  int n = dimension_.x;
  int m = dimension_.y;
  grid_ = new Cell *[n + 2];
  for (int x = -1; x < n + 1; ++x) {
    grid_[x] = new Cell[m + 2];
    for (int y = -1; y < m + 1; ++y) {
      Vector2 pos = {x, y};
      grid_[x][y] = Cell(pos);
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
