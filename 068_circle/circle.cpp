#include "circle.h"

#include <stdio.h>
#include <stdlib.h>

#include <cmath>
Circle::Circle(Point & c, double r) : center(c), radius(r) {}
void Circle::move(double dx, double dy) {
  center.move(dx, dy);
}

double Circle::intersectionArea(const Circle & otherCircle) {
  if (this == &otherCircle) {
    return M_PI * radius * radius;
  }
  double dis = center.distanceFrom(otherCircle.center);
  if (dis <= (std::abs(radius - otherCircle.radius))) {
    return (otherCircle.radius < radius) ? M_PI * pow(otherCircle.radius, 2)
                                         : M_PI * pow(radius, 2);
  }
  else if (dis >= (std::abs(radius + otherCircle.radius))) {
    return 0;
  }
  else {
    double r1 = radius;
    double r2 = otherCircle.radius;
    double angle1 = acos((dis * dis + r1 * r1 - r2 * r2) / (2 * dis * r1));
    double angle2 = acos((dis * dis + r2 * r2 - r1 * r1) / (2 * dis * r2));
    return r2 * r2 * angle2 + r1 * r1 * angle1 - r1 * dis * sin(angle1);
  }
}
