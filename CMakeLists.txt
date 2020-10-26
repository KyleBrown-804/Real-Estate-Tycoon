cmake_minimum_required(VERSION 3.17)
project(Real_Estate_Tycoon)

set(CMAKE_CXX_STANDARD 14)

add_executable(Real_Estate_Tycoon driver.cpp ApartmentComplex.cpp ApartmentComplex.h BusinessComplex.cpp BusinessComplex.h Houses.cpp Houses.h Property.cpp Property.h Tenant.cpp Tenant.h game.cpp Game.h utilities.h Player.cpp Player.h utilities.cpp)