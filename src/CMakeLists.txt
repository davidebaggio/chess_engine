

add_executable(chess_engine
	main.cpp
	board_gen.cpp
	moves.cpp
)
target_link_libraries(chess_engine PRIVATE include_interface)