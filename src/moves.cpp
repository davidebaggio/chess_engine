#include "moves.hpp"

std::string possibleMovesW(const std::string history, const uint64_t &WP, const uint64_t &WN, const uint64_t &WB, const uint64_t &WR, const uint64_t &WQ, const uint64_t &WK, const uint64_t &BP, const uint64_t &BN, const uint64_t &BB, const uint64_t &BR, const uint64_t &BQ, const uint64_t &BK)
{
	uint64_t NON_WHITE_PIECES = ~(WP | WN | WB | WR | WQ | WK | BK);
	uint64_t WHITE_CAPTURABLE = (BP | BN | BB | BR | BQ);
	uint64_t OCCUPIED = WP | WN | WB | WR | WQ | WK | BP | BN | BB | BR | BQ | BK;
	uint64_t EMPTY = ~OCCUPIED;

	std::string list = "";
	list += possibleWP(history, WP, NON_WHITE_PIECES, WHITE_CAPTURABLE, EMPTY, BP) + "\n";
	list += possibleWB(OCCUPIED, WB, NON_WHITE_PIECES) + "\n";
	list += possibleWR(OCCUPIED, WR, NON_WHITE_PIECES);
	return list;
}

std::string possibleWP(const std::string history, const uint64_t &WP, const uint64_t &NON_WHITE_PIECES, const uint64_t &WHITE_CAPTURABLE, const uint64_t &EMPTY, const uint64_t &BP)
{
	std::string list = "";
	uint64_t PAWN_MOVES;
	uint64_t possible;

	// capture right
	PAWN_MOVES = (WP >> 7) & WHITE_CAPTURABLE & ~FILE_A & ~RANK_8;
	possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	while (possible != 0)
	{
		int index = __builtin_ctzll(possible);
		list += std::to_string(index / 8 + 1) + std::to_string(index % 8 - 1) + std::to_string(index / 8) + std::to_string(index % 8);
		PAWN_MOVES &= ~possible;
		possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	}

	// left capture
	PAWN_MOVES = (WP >> 9) & WHITE_CAPTURABLE & ~FILE_H & ~RANK_8;
	possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	while (possible != 0)
	{
		int index = __builtin_ctzll(possible);
		list += std::to_string(index / 8 + 1) + std::to_string(index % 8 + 1) + std::to_string(index / 8) + std::to_string(index % 8);
		PAWN_MOVES &= ~possible;
		possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	}

	// 1 forward
	PAWN_MOVES = (WP >> 8) & EMPTY & ~RANK_8;
	possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	while (possible != 0)
	{
		int index = __builtin_ctzll(possible);
		list += std::to_string(index / 8 + 1) + std::to_string(index % 8) + std::to_string(index / 8) + std::to_string(index % 8);
		PAWN_MOVES &= ~possible;
		possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	}
	// 2 forward
	PAWN_MOVES = (WP >> 16) & EMPTY & (EMPTY >> 8) & RANK_4;
	possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	while (possible != 0)
	{
		int index = __builtin_ctzll(possible);
		list += std::to_string(index / 8 + 2) + std::to_string(index % 8) + std::to_string(index / 8) + std::to_string(index % 8);
		PAWN_MOVES &= ~possible;
		possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	}

	// pawn promotion by capture right
	PAWN_MOVES = (WP >> 7) & WHITE_CAPTURABLE & RANK_8 & ~FILE_A;
	possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	while (possible != 0)
	{
		int index = __builtin_ctzll(possible);
		list += std::to_string(index % 8 - 1) + std::to_string(index % 8) + "QP" + std::to_string(index % 8 - 1) + std::to_string(index % 8) + "RP" + std::to_string(index % 8 - 1) + std::to_string(index % 8) + "BP" + std::to_string(index % 8 - 1) + std::to_string(index % 8) + "NP";
		PAWN_MOVES &= ~possible;
		possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	}

	// pawn promotion by capture left
	PAWN_MOVES = (WP >> 9) & WHITE_CAPTURABLE & RANK_8 & ~FILE_H;
	possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	while (possible != 0)
	{
		int index = __builtin_ctzll(possible);
		list += std::to_string(index % 8 + 1) + std::to_string(index % 8) + "QP" + std::to_string(index % 8 + 1) + std::to_string(index % 8) + "RP" + std::to_string(index % 8 + 1) + std::to_string(index % 8) + "BP" + std::to_string(index % 8 + 1) + std::to_string(index % 8) + "NP";
		PAWN_MOVES &= ~possible;
		possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	}

	PAWN_MOVES = (WP >> 8) & EMPTY & RANK_8; // pawn promotion by move 1 forward
	possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	while (possible != 0)
	{
		int index = __builtin_ctzll(possible);
		list += std::to_string(index % 8) + std::to_string(index % 8) + "QP" + std::to_string(index % 8) + std::to_string(index % 8) + "RP" + std::to_string(index % 8) + std::to_string(index % 8) + "BP" + std::to_string(index % 8) + std::to_string(index % 8) + "NP";
		PAWN_MOVES &= ~possible;
		possible = PAWN_MOVES & ~(PAWN_MOVES - 1);
	}

	// en passant
	if (history.length() >= 4)
	{
		int p = history.length();
		if (history[p - 1] == history[p - 3] && abs(history[p - 2] - history[p - 4]) == 2)
		{
			int eFile = (int)(history[p - 1] - '0');
			possible = (WP << 1) & BP & RANK_5 & ~FILE_A & FileMasks8[eFile]; // shows piece to remove, not the destination
			if (possible != 0)
			{
				int index = __builtin_ctzll(possible);
				list += std::to_string(index % 8 - 1) + std::to_string(index % 8) + " E";
			}
			possible = (WP >> 1) & BP & RANK_5 & ~FILE_H & FileMasks8[eFile]; // shows piece to remove, not the destination
			if (possible != 0)
			{
				int index = __builtin_ctzll(possible);
				list += std::to_string(index % 8 + 1) + std::to_string(index % 8) + " E";
			}
		}
	}

	return list;
}

std::string possibleWB(const uint64_t &OCCUPIED, const uint64_t &WB, const uint64_t &NON_WHITE_PIECES)
{
	std::string list = "";
	uint64_t i = WB & ~(WB - 1);
	uint64_t cp = WB;
	uint64_t possibility;
	while (i != 0)
	{
		int iLocation = __builtin_ctzll(i);
		possibility = possibleDAD(OCCUPIED, iLocation) & NON_WHITE_PIECES;
		// print_bit_board(possibility);
		uint64_t j = possibility & ~(possibility - 1);
		while (j != 0)
		{
			int index = __builtin_ctzll(j);
			list += std::to_string(iLocation / 8) + std::to_string(iLocation % 8) + std::to_string(index / 8) + std::to_string(index % 8) + "/";
			possibility &= ~j;
			j = possibility & ~(possibility - 1);
		}
		cp &= ~i;
		i = cp & ~(cp - 1);
	}
	return list;
}

std::string possibleWR(const uint64_t &OCCUPIED, const uint64_t &WR, const uint64_t &NON_WHITE_PIECES)
{
	std::string list = "";
	uint64_t i = WR & ~(WR - 1);
	uint64_t cp = WR;
	uint64_t possibility;
	while (i != 0)
	{
		int iLocation = __builtin_ctzll(i);
		print_bit_board(OCCUPIED);
		possibility = possibleHV(OCCUPIED, iLocation) & NON_WHITE_PIECES;
		// print_bit_board(possibility);
		uint64_t j = possibility & ~(possibility - 1);
		while (j != 0)
		{
			int index = __builtin_ctzll(j);
			list += std::to_string(iLocation / 8) + std::to_string(iLocation % 8) + std::to_string(index / 8) + std::to_string(index % 8) + "/";
			possibility &= ~j;
			j = possibility & ~(possibility - 1);
		}
		cp &= ~i;
		i = cp & ~(cp - 1);
	}
	return list;
}

uint64_t possibleHV(const uint64_t &OCCUPIED, int s)
{
	uint64_t binaryS = 1L << s;
	uint64_t possibilitiesHorizontal = (OCCUPIED - 2 * binaryS) ^ reverseBits(reverseBits(OCCUPIED) - 2 * reverseBits(binaryS));
	uint64_t possibilitiesVertical = ((OCCUPIED & FileMasks8[s % 8]) - (2 * binaryS)) ^ reverseBits(reverseBits(OCCUPIED & FileMasks8[s % 8]) - (2 * reverseBits(binaryS)));
	return (possibilitiesHorizontal & RankMasks8[s / 8]) | (possibilitiesVertical & FileMasks8[s % 8]);
}

uint64_t possibleDAD(const uint64_t &OCCUPIED, int s)
{
	uint64_t binaryS = 1L << s;
	uint64_t possibilitiesDiagonal = ((OCCUPIED & DiagonalMasks8[(s / 8) + (s % 8)]) - (2 * binaryS)) ^ reverseBits(reverseBits(OCCUPIED & DiagonalMasks8[(s / 8) + (s % 8)]) - (2 * reverseBits(binaryS)));
	uint64_t possibilitiesAntiDiagonal = ((OCCUPIED & AntiDiagonalMasks8[(s / 8) + 7 - (s % 8)]) - (2 * binaryS)) ^ reverseBits(reverseBits(OCCUPIED & AntiDiagonalMasks8[(s / 8) + 7 - (s % 8)]) - (2 * reverseBits(binaryS)));
	return (possibilitiesDiagonal & DiagonalMasks8[(s / 8) + (s % 8)]) | (possibilitiesAntiDiagonal & AntiDiagonalMasks8[(s / 8) + 7 - (s % 8)]);
}

uint64_t reverseBits(const uint64_t num)
{
	uint64_t n = num;
	n = (n >> 1) & 0x5555555555555555ULL | (n & 0x5555555555555555ULL) << 1;
	n = (n >> 2) & 0x3333333333333333ULL | (n & 0x3333333333333333ULL) << 2;
	n = (n >> 4) & 0x0F0F0F0F0F0F0F0FULL | (n & 0x0F0F0F0F0F0F0F0FULL) << 4;
	n = (n >> 8) & 0x00FF00FF00FF00FFULL | (n & 0x00FF00FF00FF00FFULL) << 8;
	n = (n >> 16) & 0x0000FFFF0000FFFFULL | (n & 0x0000FFFF0000FFFFULL) << 16;
	n = (n >> 32) | (n << 32);
	return n;
}

/* std::string other_method(std::string history, uint64_t &WP, uint64_t &NON_WHITE_PIECES, uint64_t &WHITE_CAPTURABLE, uint64_t &EMPTY)
{
	std::string list = "";
	uint64_t PAWN_MOVES;
	// capture right
	PAWN_MOVES = (WP >> 7) & WHITE_CAPTURABLE & ~FILE_A & ~RANK_8;
	for (size_t i = __builtin_ctzll(PAWN_MOVES); i < 64 - __builtin_clzll(PAWN_MOVES); i++)
	{
		if ((PAWN_MOVES >> i) & 1)
			list += std::to_string(i / 8 + 1) + std::to_string(i % 8 - 1) + std::to_string(i / 8) + std::to_string(i % 8);
	}
	// left capture
	PAWN_MOVES = (WP >> 9) & WHITE_CAPTURABLE & ~FILE_H & ~RANK_8;
	for (size_t i = __builtin_ctzll(PAWN_MOVES); i < 64 - __builtin_clzll(PAWN_MOVES); i++)
	{
		if ((PAWN_MOVES >> i) & 1)
			list += std::to_string(i / 8 + 1) + std::to_string(i % 8 + 1) + std::to_string(i / 8) + std::to_string(i % 8);
	}
	// 1 forward
	PAWN_MOVES = (WP >> 8) & EMPTY & ~RANK_8;
	for (size_t i = __builtin_ctzll(PAWN_MOVES); i < 64 - __builtin_clzll(PAWN_MOVES); i++)
	{
		if ((PAWN_MOVES >> i) & 1)
			list += std::to_string(i / 8 + 1) + std::to_string(i % 8) + std::to_string(i / 8) + std::to_string(i % 8);
	}
	// 2 forward
	PAWN_MOVES = (WP >> 16) & EMPTY & (EMPTY >> 8) & RANK_4;
	for (size_t i = __builtin_ctzll(PAWN_MOVES); i < 64 - __builtin_clzll(PAWN_MOVES); i++)
	{
		if ((PAWN_MOVES >> i) & 1)
			list += std::to_string(i / 8 + 2) + std::to_string(i % 8) + std::to_string(i / 8) + std::to_string(i % 8);
	}

	// pawn promotion by capture right
	PAWN_MOVES = (WP >> 7) & WHITE_CAPTURABLE & RANK_8 & ~FILE_A;
	for (size_t i = __builtin_ctzll(PAWN_MOVES); i < 64 - __builtin_clzll(PAWN_MOVES); i++)
	{
		if ((PAWN_MOVES >> i) & 1)
			list += std::to_string(i % 8 - 1) + std::to_string(i % 8) + "QP" + std::to_string(i % 8 - 1) + std::to_string(i % 8) + "RP" + std::to_string(i % 8 - 1) + std::to_string(i % 8) + "BP" + std::to_string(i % 8 - 1) + std::to_string(i % 8) + "NP";
	}

	// pawn promotion by capture left
	PAWN_MOVES = (WP >> 9) & WHITE_CAPTURABLE & RANK_8 & ~FILE_H;
	for (size_t i = __builtin_ctzll(PAWN_MOVES); i < 64 - __builtin_clzll(PAWN_MOVES); i++)
	{
		if ((PAWN_MOVES >> i) & 1)
			list += std::to_string(i % 8 + 1) + std::to_string(i % 8) + "QP" + std::to_string(i % 8 + 1) + std::to_string(i % 8) + "RP" + std::to_string(i % 8 + 1) + std::to_string(i % 8) + "BP" + std::to_string(i % 8 + 1) + std::to_string(i % 8) + "NP";
	}

	// pawn promotion by move 1 forward
	PAWN_MOVES = (WP >> 8) & EMPTY & RANK_8;
	for (size_t i = __builtin_ctzll(PAWN_MOVES); i < 64 - __builtin_clzll(PAWN_MOVES); i++)
	{
		if ((PAWN_MOVES >> i) & 1)
			list += std::to_string(i % 8) + std::to_string(i % 8) + "QP" + std::to_string(i % 8) + std::to_string(i % 8) + "RP" + std::to_string(i % 8) + std::to_string(i % 8) + "BP" + std::to_string(i % 8) + std::to_string(i % 8) + "NP";
	}

	return list;
} */