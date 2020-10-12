	set(SOURCE_FILES 
	Board.cpp
	Vector2.cpp)
	
	set(HEADER_FILES
	../include/Application.h 
	../include/Board.h
	../include/Vector2.h)
	
	add_library(GameFramework STATIC ${SOURCE_FILES} ${HEADER_FILES})
	
	target_include_directories(GameFramework PUBLIC ${PROJECT_SOURCE_DIR}/include)