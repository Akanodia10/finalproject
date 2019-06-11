#include <sdlgraph.h>

int main()
{
  Graph myGraph;
  
  myGraph.xMin = -10.0;
  myGraph.xMax = 10.0;
  myGraph.yMin = 0.0;
  myGraph.yMax = 100.0;
  myGraph.xScale = 1.0;
  myGraph.yScale = 1.0;
  myGraph.height = 800;
  myGraph.width = 800;

  init_graph(&myGraph);
  draw_grid(&myGraph, 0, 2);
  update_screen(&myGraph);

  float x, y;
  set_color(&myGraph, 255, 0, 0);
  for ( x = -10.0; (int)x < 10; x += 0.01 )
{
  y = x*x;
  print_pixel ( &myGraph, x, y );
  update_screen(&myGraph);
}

idle();
quit();
return 0;
}
