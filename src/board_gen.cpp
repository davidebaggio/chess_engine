#include "board_gen.hpp"

void print_board(std::string *board)
{
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void print_bit_board(uint64_t board)
{
	for (int i = 0; i < 64; i++)
	{
		if (board & (0x1ULL << i))
			std::cout << 1 << " ";
		else
			std::cout << 0 << " ";
		if (i % 8 == 7)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

void print_board_from_bits(uint64_t &WP, uint64_t &WN, uint64_t &WB, uint64_t &WR, uint64_t &WQ, uint64_t &WK, uint64_t &BP, uint64_t &BN, uint64_t &BB, uint64_t &BR, uint64_t &BQ, uint64_t &BK)
{
	std::string board[] = {
		{"        "},
		{"        "},
		{"        "},
		{"        "},
		{"        "},
		{"        "},
		{"        "},
		{"        "}};

	for (size_t i = 0; i < 64; i++)
	{
		if (WP & (0x1ULL << i))
			board[i / 8][i % 8] = 'P';
		if (WN & (0x1ULL << i))
			board[i / 8][i % 8] = 'N';
		if (WB & (0x1ULL << i))
			board[i / 8][i % 8] = 'B';
		if (WR & (0x1ULL << i))
			board[i / 8][i % 8] = 'R';
		if (WQ & (0x1ULL << i))
			board[i / 8][i % 8] = 'Q';
		if (WK & (0x1ULL << i))
			board[i / 8][i % 8] = 'K';
		if (BP & (0x1ULL << i))
			board[i / 8][i % 8] = 'p';
		if (BN & (0x1ULL << i))
			board[i / 8][i % 8] = 'n';
		if (BB & (0x1ULL << i))
			board[i / 8][i % 8] = 'b';
		if (BR & (0x1ULL << i))
			board[i / 8][i % 8] = 'r';
		if (BQ & (0x1ULL << i))
			board[i / 8][i % 8] = 'q';
		if (BK & (0x1ULL << i))
			board[i / 8][i % 8] = 'k';
	}
	print_board(board);
}

void std_board_init(std::string *init)
{
	init[0] = "rnbqkbnr";
	init[1] = "pppppppp";
	init[2] = "        ";
	init[3] = "   B  R ";
	init[4] = "    p   ";
	init[5] = "        ";
	init[6] = "PPPPPPPP";
	init[7] = "RNBQKBNR";
	// init = {"rnbqkbnr", "pppppppp", "        ", "        ", "        ", "        ", "PPPPPPPP", "RNBQKBNR"};
}

void array_to_bit_board(std::string *board, uint64_t &WP, uint64_t &WN, uint64_t &WB, uint64_t &WR, uint64_t &WQ, uint64_t &WK, uint64_t &BP, uint64_t &BN, uint64_t &BB, uint64_t &BR, uint64_t &BQ, uint64_t &BK)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (board[i][j])
			{
			case 'P':
				WP |= (0x1ULL << (i * 8 + j));
				break;
			case 'N':
				WN |= (0x1ULL << (i * 8 + j));
				break;
			case 'B':
				WB |= (0x1ULL << (i * 8 + j));
				break;
			case 'R':
				WR |= (0x1ULL << (i * 8 + j));
				break;
			case 'Q':
				WQ |= (0x1ULL << (i * 8 + j));
				break;
			case 'K':
				WK |= (0x1ULL << (i * 8 + j));
				break;
			case 'p':
				BP |= (0x1ULL << (i * 8 + j));
				break;
			case 'n':
				BN |= (0x1ULL << (i * 8 + j));
				break;
			case 'b':
				BB |= (0x1ULL << (i * 8 + j));
				break;
			case 'r':
				BR |= (0x1ULL << (i * 8 + j));
				break;
			case 'q':
				BQ |= (0x1ULL << (i * 8 + j));
				break;
			case 'k':
				BK |= (0x1ULL << (i * 8 + j));
				break;
			default:
				break;
			}
		}
	}
}

void pack_bits(uint64_t *pack, uint64_t &WP, uint64_t &WN, uint64_t &WB, uint64_t &WR, uint64_t &WQ, uint64_t &WK, uint64_t &BP, uint64_t &BN, uint64_t &BB, uint64_t &BR, uint64_t &BQ, uint64_t &BK)
{
	// pack all bitboards into a single array
	pack[0] = WP;
	pack[1] = WN;
	pack[2] = WB;
	pack[3] = WR;
	pack[4] = WQ;
	pack[5] = WK;
	pack[6] = BP;
	pack[7] = BN;
	pack[8] = BB;
	pack[9] = BR;
	pack[10] = BQ;
	pack[11] = BK;
}

void unpack_bits(uint64_t *bits, uint64_t &WP, uint64_t &WN, uint64_t &WB, uint64_t &WR, uint64_t &WQ, uint64_t &WK, uint64_t &BP, uint64_t &BN, uint64_t &BB, uint64_t &BR, uint64_t &BQ, uint64_t &BK)
{
	// unpack an array of bitboards into their respective variables
	WP = bits[0];
	WN = bits[1];
	WB = bits[2];
	WR = bits[3];
	WQ = bits[4];
	WK = bits[5];
	BP = bits[6];
	BN = bits[7];
	BB = bits[8];
	BR = bits[9];
	BQ = bits[10];
	BK = bits[11];
}