cmake_minimum_required (VERSION 3.8)

project ("LearningGraphics")

add_executable (LearningGraphics 
	"src/Main.cpp"
	"src/glad.c"
	"src/Loader.cpp"
	"src/Shaders.cpp"
	"src/Utils.cpp"
	"src/Renderer.cpp"
)

target_include_directories(LearningGraphics PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_directories(LearningGraphics PUBLIC ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(LearningGraphics PUBLIC glfw3)

