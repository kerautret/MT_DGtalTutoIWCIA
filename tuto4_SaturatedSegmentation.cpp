#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/io/readers/PointListReader.h"
#include "DGtal/io/boards/Board2D.h"

// To compute the AlphaThickSegments
#include "DGtal/geometry/curves/AlphaThickSegmentComputer.h"
// For global tangential cover
#include "DGtal/geometry/curves/SaturatedSegmentation.h"


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
  // Define a SaturatedSegmentation object from the contour iterator





  // From an iterator on the resulting object display all the segments:  





  
  aBoard.saveEPS("resultTuto4.eps");  
  return 0;
}





