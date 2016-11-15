add_executable(${EXECUTABLE_NAME}
	graphics.cc
	world.cc
	gameobjects.cc

	main.cc
	)

# SFML
find_package(SFML 2 REQUIRED system window graphics)
if (SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
