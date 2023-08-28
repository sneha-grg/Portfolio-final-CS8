cmake_minimum_required(VERSION 3.23)
project(Portfolio)

set(CMAKE_CXX_STANDARD 14)

add_executable(Portfolio main.cpp Window.cpp Window.h States.cpp States.h statesEnum.h Fonts.cpp Fonts.h
        fontsEnum.h Position.cpp Position.h MouseEvents.cpp MouseEvents.h ListItem.cpp
        ListItem.h List.cpp List.h Menu.cpp Menu.h Images.cpp Images.h
        ImageEnum.h Screen.cpp Screen.h GreenBall.cpp GreenBall.h NewImages.cpp NewImages.h ImageDisplay.cpp ImageDisplay.h
        BouncingBall.cpp BouncingBall.h PongGame.cpp PongGame.h TopHatGuy.cpp TopHatGuy.h DrawCard.cpp DrawCard.h PokerGame.cpp PokerGame.h suitEnums.h rankEnums.h SnakeFinalGame.cpp SnakeFinalGame.h)

target_link_libraries(Portfolio sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
