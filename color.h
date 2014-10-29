//Basic utilities for tryin out colormaps
#include <algorithm>

struct color
{
  double R, G, B;
};

color hot(double x)
{
  color c;
  double red_cutoff = 0.4;
  double green_cutoff = 0.8;
  c.R = (x < red_cutoff ?  (x/red_cutoff) : 1.0);
  c.G = (x < red_cutoff ? 0.0 : (x < green_cutoff ? (x-red_cutoff)/(green_cutoff-red_cutoff) : 1.0));
  c.B = (x < green_cutoff ? 0.0 : (x-green_cutoff)/(1.0-green_cutoff));
  
  c.R = std::max( 0.0, std::min(c.R, 1.0) );
  c.G = std::max( 0.0, std::min(c.G, 1.0) );
  c.B = std::max( 0.0, std::min(c.B, 1.0) );
  return c;
}
