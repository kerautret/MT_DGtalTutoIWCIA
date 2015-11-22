#include "DGtal/base/Common.h"
#include "DGtal/helpers/StdDefs.h"
#include "DGtal/io/readers/PointListReader.h"
#include "DGtal/io/boards/Board2D.h"

// To compute the AlphaThickSegments
#include "DGtal/geometry/curves/AlphaThickSegmentComputer.h"
// For tangential cover
#include "DGtal/geometry/curves/SaturatedSegmentation.h"

// To represent the multiscale profile
#include "DGtal/geometry/helpers/ScaleProfile.h"


using namespace DGtal;


int
main(int argc, char ** argv){
  typedef Z2i::Point Point;
  typedef AlphaThickSegmentComputer<Point> AlphaThickSegmentComputer2D;
  typedef  SaturatedSegmentation<AlphaThickSegmentComputer2D> AlphaSegmentation;
  
  
  std::vector<Point> contour = PointListReader<Point>::getPointsFromFile("../Samples/contourS.sdp");
  Board2D  aBoard;
  std::vector<ScaleProfile> vectProfiles;
  unsigned int scaleMax = 5;
  for (unsigned int i=0; i < contour.size(); i++) {
      ScaleProfile s;
      s.init(scaleMax);
      vectProfiles.push_back(s);
    }
  
  std::vector<Point>::const_iterator itInit = contour.begin();
  for(unsigned int thickness = 1; thickness <= scaleMax; thickness++){
    AlphaThickSegmentComputer2D aComputer(thickness);
    AlphaSegmentation segmentator(contour.begin(), contour.end(), aComputer);
    typename AlphaSegmentation::SegmentComputerIterator it = segmentator.begin();
    typename AlphaSegmentation::SegmentComputerIterator endSeg = segmentator.end();
    for( ; it != endSeg; ++it){
      trace.info() << ".";
      AlphaThickSegmentComputer2D seg(*it);
      double lengthSegment = seg.getSegmentLength();
      std::vector<Point>::const_iterator itS = seg.begin();
      for ( ; itS != seg.end(); ++itS) {
        unsigned int i = std::distance(itInit, itS);
        vectProfiles[i].addValue(thickness-1, lengthSegment/thickness);
      }
    }
  }
  
  unsigned int pos=0;
  for (auto&& p :contour) {
    aBoard.setFillColor(DGtal::Color(200, 200, 255));
    aBoard.setPenColor(DGtal::Color(150, 150, 255));
    double n = vectProfiles[pos].noiseLevel(1,0);
    n = n==0 ?  scaleMax-1 : n;
    aBoard.drawRectangle(p[0]-(n/2.0), p[1]+(n/2.0), n, n);
    pos++;
  }
  aBoard.setPenColor(DGtal::Color(50, 50, 150));
  aBoard.setLineWidth(5);
  Z2i::Point last = *(contour.begin());
  for (auto&& p :contour) {
      aBoard.drawLine(p[0], p[1], last[0], last[1]) ;
    last = p;
  }
  
  aBoard.saveEPS("resultTuto6.eps");

  return 0;
}





