	set(SOURCE_FILES 
	SandBoxApp.cpp)
	
	set(HEADER_FILES
	SandBoxApp.h) 
	
	add_library(SandBoxApp STATIC ${SOURCE_FILES} ${HEADER_FILES})
	
	target_link_libraries(SandBoxApp PUBLIC GameFramework)
	
	target_include_directories(SandBoxApp PUBLIC ${PROJECT_SOURCE_DIR}/include)

