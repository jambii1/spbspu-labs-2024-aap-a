#include <iostream>
#include <stdexcept>
#include "destroy.hpp"
#include "printResult.hpp"
#include "createCommand.hpp"

int main()
{
  using namespace duhanina;
  Shape* shapes[10000] = {};
  size_t shapeCount = 0;
  std::string shapeType;
  while (std::cin >> shapeType)
  {
    try
    {
      createShape(shapeType, shapes, shapeCount);
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << "\n";
      destroy(shapes, shapeCount);
      return 1;
    }
    if (shapeType == "SCALE")
    {
      break;
    }
  }
  if (std::cin.eof())
  {
    std::cerr << "No scale\n";
    destroy(shapes, shapeCount);
    return 1;
  }
  try
  {
    printFiguresInfo(std::cout, shapes, shapeCount);
    createScale(std::cin, shapes, shapeCount);
    printFiguresInfo(std::cout, shapes, shapeCount);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    destroy(shapes, shapeCount);
    return 1;
  }
  destroy(shapes, shapeCount);
  return 0;
}
