cmake_minimum_required(VERSION 3.17)
project(Real_Estate_Tycoon)

set(CMAKE_CXX_STANDARD 14)

add_executable(Real_Estate_Tycoon main.cpp ApartmentComplex.cpp ApartmentComplex.h BusinessComplex.cpp BusinessComplex.h Event.cpp Event.h House.cpp House.h Property.cpp Property.h Tenant.cpp Tenant.h Transaction.cpp Transaction.h)