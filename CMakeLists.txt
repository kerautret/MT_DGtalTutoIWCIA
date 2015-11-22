PROJECT(MT_DGtalTutoIWCIA)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(Progs
    tuto1_readInput
    tuto2_compAlphaThickSegment
    tuto3_TangentialCover
    tuto4_SaturatedSegmentation
    tuto5_MeaningfulThickness1Pt
    tuto6_MeaningfulThicknessAllPt)



FIND_PACKAGE(DGtal REQUIRED)
INCLUDE_DIRECTORIES(${DGTAL_INCLUDE_DIRS})
LINK_DIRECTORIES(${DGTAL_LIBRARY_DIRS})

FIND_PACKAGE(Boost 1.46.0 REQUIRED COMPONENTS program_options)
if ( Boost_FOUND )
  message(STATUS "Boost and boost_program_options found.")
  include_directories( ${Boost_INCLUDE_DIRS} )
     SET(DGtalToolsLibDependencies ${DGtalToolsLibDependencies} 
     ${Boost_LIBRAIRIES}  
     ${Boost_PROGRAM_OPTIONS_LIBRARY})
   SET(DGtalLibInc ${Boost_INCLUDE_DIRS})
endif( Boost_FOUND) 


FOREACH(FILE ${Progs})
   ADD_EXECUTABLE(${FILE} ${FILE}  )
   TARGET_LINK_LIBRARIES(${FILE}  ${DGTAL_LIBRARIES}  ${DGtalToolsLibDependencies} )

ENDFOREACH(FILE)
