#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace maslevtsov
{
  struct Rectangle: Shape
  {
  public:
    Rectangle(rectangle_t rect);
    double getArea() override;
    rectangle_t getFrameRect() override;
    void move(point_t pnt) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    rectangle_t rect_;
  };
}

#endif