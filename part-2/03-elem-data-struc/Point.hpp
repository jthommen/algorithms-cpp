#include<cmath>
#include<iostream>

struct point {
    float x;
    float y;
};

float distance(point a, point b)
{
  std::cout << "a.x==" << a.x << std::endl;
  std::cout << "a.y==" << a.y << std::endl;
  std::cout << "b.x==" << b.x << std::endl;
  std::cout << "b.y==" << b.y << std::endl;
  float dx = a.x - b.x, dy = a.y - b.y;
  std::cout << "dx==" << dx << " dy==" << dy << std::endl;
  return sqrt(dx*dx + dy*dy);
}