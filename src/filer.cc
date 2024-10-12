#include "filer.h"

std::vector<std::string> Lines(const std::string &input_file) {
  std::fstream file;
  file.open(input_file, std::ios_base::in);
  std::string line;
  std::vector<std::string> lines;

  while (getline(file, line)) {
    lines.push_back(line);
  }
  lines.erase(lines.begin(), lines.begin() + 2);

  return lines;
}

Vector2 Dimensions(const std::string &input_file) {
  std::fstream file;
  file.open(input_file, std::ios_base::in);
  std::string line;
  Vector2 dimensions = {0, 0};
  int counter = 0;
  while (getline(file, line)) {
    if (counter == 0) {
      dimensions.x = std::stoi(line);
      ++counter;
    } else {
      dimensions.y = std::stoi(line);
      break;
    }
  }
  return dimensions;
}