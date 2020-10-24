cmake_minimum_required(VERSION 3.17)
project(Real_Estate_Tycoon)

set(CMAKE_CXX_STANDARD 14)

add_executable(Real_Estate_Tycoon driver.cpp Apartment.cpp Apartment.h Business.cpp Business.h House.cpp House.h Property.cpp Property.h Tenant.cpp Tenant.h Transaction.cpp Transaction.h game.cpp Game.h utilities.h Player.cpp Player.h utilities.cpp)