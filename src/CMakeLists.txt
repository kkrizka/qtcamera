SET(SRCS main.cpp
  mainwindow.cpp)

IF(${CMAKE_VERSION} VERSION_LESS 3.0) # No AUTOUIC in latest SLC7
  QT5_WRAP_UI(FORM_HEADERS mainwindow.ui)
  INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
  SET(CMAKE_CXX_FLAGS "-std=c++0x")
ENDIF()

ADD_EXECUTABLE(qtcamera ${SRCS} ${FORM_HEADERS})
TARGET_LINK_LIBRARIES(qtcamera Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)
