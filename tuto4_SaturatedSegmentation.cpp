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
  typedef  SaturatedSegmentation<AlphaThickSegmentComputer2D> AlphaSegmentation;
  AlphaThickSegmentComputer2D aComputer(5);
  AlphaSegmentation segmentator(contour.begin(), contour.end(), aComputer);
  typename AlphaSegmentation::SegmentComputerIterator it = segmentator.begin();
  typename AlphaSegmentation::SegmentComputerIterator endSeg = segmentator.end();
  
  aBoard << SetMode(aComputer.className(), "BoundingBox");
  while(it != endSeg){
    aBoard << *it;
    ++it;
  }
  
  aBoard.saveEPS("resultTuto4.eps");  
  return 0;
}





