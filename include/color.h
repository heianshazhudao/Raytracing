#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

inline double liner_to_gamma(double liner_component) {
  return sqrt(liner_component);
}

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {

  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  // divide by the number of samples
  auto scale = 1.0 / samples_per_pixel;
  r *= scale;
  g *= scale;
  b *= scale;

  // apply the linear to gamma transfo
  r = liner_to_gamma(r);
  g = liner_to_gamma(g);
  b = liner_to_gamma(b);

  // 写入颜色值(分量范围在[0,255])
  static const interval intensitiy(0.000, 0.999);
  out << static_cast<int>(256 * intensitiy.clamp(r)) << ' '
      << static_cast<int>(256 * intensitiy.clamp(g)) << ' '
      << static_cast<int>(256 * intensitiy.clamp(b)) << '\n';
}

#endif