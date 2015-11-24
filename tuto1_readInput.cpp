#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"

// To use the reading of input points:
#include "DGtal/io/readers/PointListReader.h"

// To display the points in 2D:
#include "DGtal/io/boards/Board2D.h"

using namespace DGtal;

int 
main(int argc, char ** argv){
  trace.info() << "First programm in DGtal" << std::endl;
  typedef Z2i::Point Point;
  // Use the PointListReader class to get the set points contained in the file ../Samples/contourS.sdp
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile("../Samples/contourS.sdp");
  
  
  Board2D aBoard;
  // For all points of the contours display it using the stream operator << and the Board2D object:
  

  //  From the board object save the resulting file in eps format:
  

  return 0;
}





