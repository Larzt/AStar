#include "lib/filer.h"
#include "lib/grid.h"
#include "lib/utility.h"

int main(int argc, char const *argv[]) {
  std::string file_name = argv[1];
  std::vector<std::string> maze = Lines(file_name);
  Vector2 dimensions = Dimensions(file_name);
  Grid grid(maze, dimensions);
  std::cout << grid << std::endl;
  return 0;
}