set(main_sources insiderApp.cpp)
add_executable(insiderApp ${main_sources})
target_link_libraries(insiderApp common insider)
set(visibility hidden)