#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/io/readers/PointListReader.h"
#include "DGtal/io/boards/Board2D.h"

// To compute the AlphaThickSegments
#include "DGtal/geometry/curves/AlphaThickSegmentComputer.h"
// For tangential cover
#include "DGtal/geometry/curves/SegmentComputerUtils.h"
// To represent the multiscale profile
#include "DGtal/geometry/helpers/ScaleProfile.h"


using namespace DGtal;

int 
main(int argc, char ** argv){
  typedef Z2i::Point Point;
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile("../Samples/contourS.sdp");
  Board2D  aBoards[5];
  aBoards[0] = Board2D();
  aBoards[1] = Board2D();
  aBoards[2] = Board2D();
  aBoards[3] = Board2D();
  aBoards[4] = Board2D();

  for(unsigned int thickness = 1; thickness<=5; thickness++){
    for (auto&& p :contour) {
      aBoards[thickness-1] << p;
    }
  }
  std::ofstream ofLength;
  ofLength.open("lengthNoiseTuto5.dat");

  typedef AlphaThickSegmentComputer<Z2i::Point> AlphaThickSegmentComputer2D;
  unsigned indexPt = 200;

  // Initialise a ScaleProfile object with size equal to 5:



  
  for(unsigned int thickness = 1; thickness<=5; thickness++){
    // By using the previous question of tuto3_TangentialCover compute
    // all segments of thickness "thickness", and display if in its associated board:
    
    

    









    // in the loop which display the segments, add into the
    // ScaleProfile object, a value in the index "thickness - 1" with
    // value (first.getSegmentLength()/thickness) ;

    
    // Don't forget to apply the same addition for the last segment. 



    // Add the display of the input point by using the drawCircle function of Board2D object.



    
    // Export each board object in eps format.


    
  }
  

  // From the ScaleProfile object get save into a file the multiscale profile 




  // Display the noise level of the considered point:




  return 0;
}





