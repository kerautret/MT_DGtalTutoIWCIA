#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/io/readers/PointListReader.h"
#include "DGtal/io/boards/Board2D.h"

// To compute the AlphaThickSegments
#include "DGtal/geometry/curves/AlphaThickSegmentComputer.h"
// For tangential cover
#include "DGtal/geometry/curves/SegmentComputerUtils.h"

using namespace DGtal;


int 
main(int argc, char ** argv){
  typedef Z2i::Point Point;
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile("../Samples/contourS.sdp");
  Board2D aBoard;
  for (auto&& p :contour) {
    aBoard << p;
  }
  typedef AlphaThickSegmentComputer<Z2i::Point> AlphaThickSegmentComputer2D;

  AlphaThickSegmentComputer2D aComputer(5);

  // By using firstMaximalSegment() function, define a variable
  // "first" which will represent the first maximal segment convering
  // the point of index 200:


  // Same question with the last segment: 
  



  // By using function nextMaximalSegment() function display all the
  // segments given between the first and the last segment:
  



 

  aBoard.saveEPS("resultTuto3.eps");  
  return 0;
}





