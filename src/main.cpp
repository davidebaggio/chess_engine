#include "board_gen.hpp"
#include "moves.hpp"

#include <chrono>

int main(int argc, char const *argv[])
{
	uint64_t WP = 0x0ULL, WN = 0x0ULL, WB = 0x0ULL, WR = 0x0ULL, WQ = 0x0ULL, WK = 0x0ULL;
	uint64_t BP = 0x0ULL, BN = 0x0ULL, BB = 0x0ULL, BR = 0x0ULL, BQ = 0x0ULL, BK = 0x0ULL;

	std::string board[12];
	std_board_init(board);
	std::cout << "Board: " << std::endl;
	array_to_bit_board(board, WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK);
	print_board_from_bits(WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK);
	std::cout << std::endl;

	auto start = std::chrono::high_resolution_clock::now();
	std::string p1 = possibleMovesW("", WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << p1 << std::endl;
	std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
	return 0;
}