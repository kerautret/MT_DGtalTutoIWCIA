#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/io/readers/PointListReader.h"
#include "DGtal/io/boards/Board2D.h"

// To compute the AlphaThickSegments
#include "DGtal/geometry/curves/AlphaThickSegmentComputer.h"



using namespace DGtal;

int 
main(int argc, char ** argv){
  typedef Z2i::Point Point;
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile("../Samples/contourS.sdp");
  Board2D aBoard;
  for (auto&& p :contour) {
    aBoard << p;
  }
  aBoard.setPenColor(DGtal::Color::Red);
  aBoard.setFillColor(DGtal::Color::Red);
  aBoard.drawCircle(contour[30][0], contour[30][1],1); 
  unsigned int startIndex = 30;
  
  typedef  AlphaThickSegmentComputer< Z2i::Point > AlphaThickSegmentComputer2D;
  // Define and initialise an AlphaThickSegmentComputer2D with thickness equals to 5 and extend it:
  

  
  // Display the AlphaThickSegmentComputer2D by using a CustomStyle object with CustomColors in blue:
  // (using the << operator)

  

  
  // Export it in vectorial format:
  aBoard.saveEPS("resultTuto2.eps");
  
  return 0;
}
