#ifndef MOVES_H
#define MOVES_H

#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include "board_gen.hpp"

static const uint64_t FILE_A = 0x8080808080808080;
static const uint64_t FILE_H = 0x0101010101010101;
static const uint64_t FILE_AB = 0xC0C0C0C0C0C0C0C0;
static const uint64_t FILE_GH = 0x0303030303030303;
static const uint64_t RANK_1 = 0xFF00000000000000;
static const uint64_t RANK_4 = 0x000000FF00000000;
static const uint64_t RANK_5 = 0x00000000FF000000;
static const uint64_t RANK_8 = 0x00000000000000FF;
static const uint64_t CENTRE = 0x0000001818000000;
static const uint64_t EXTENDED_CENTRE = 0x00003C3C3C3C0000;
static const uint64_t KING_SIDE = 0x0F0F0F0F0F0F0F0F;
static const uint64_t QUEEN_SIDE = 0xF0F0F0F0F0F0F0F0;
static const uint64_t RankMasks8[] = {
	0xFFL, 0xFF00L, 0xFF0000L, 0xFF000000L, 0xFF00000000L, 0xFF0000000000L, 0xFF000000000000L, 0xFF00000000000000L};
static const uint64_t FileMasks8[] = {
	0x0101010101010101L, 0x0202020202020202L, 0x0404040404040404L, 0x0808080808080808L,
	0x1010101010101010L, 0x2020202020202020L, 0x4040404040404040L, 0x8080808080808080L};
static const uint64_t DiagonalMasks8[] = {
	0x1L, 0x102L, 0x10204L, 0x1020408L, 0x102040810L, 0x10204081020L, 0x1020408102040L,
	0x102040810204080L, 0x204081020408000L, 0x408102040800000L, 0x810204080000000L,
	0x1020408000000000L, 0x2040800000000000L, 0x4080000000000000L, 0x8000000000000000L}; /*from top left to bottom right*/
static const uint64_t AntiDiagonalMasks8[] = {
	0x80L, 0x8040L, 0x804020L, 0x80402010L, 0x8040201008L, 0x804020100804L, 0x80402010080402L,
	0x8040201008040201L, 0x4020100804020100L, 0x2010080402010000L, 0x1008040201000000L,
	0x804020100000000L, 0x402010000000000L, 0x201000000000000L, 0x100000000000000L}; /*from top right to bottom left*/

//~

std::string possibleMovesW(const std::string history, const uint64_t &WP, const uint64_t &WN, const uint64_t &WB, const uint64_t &WR, const uint64_t &WQ, const uint64_t &WK, const uint64_t &BP, const uint64_t &BN, const uint64_t &BB, const uint64_t &BR, const uint64_t &BQ, const uint64_t &BK);
std::string possibleWP(const std::string history, const uint64_t &WP, const uint64_t &NON_WHITE_PIECES, const uint64_t &WHITE_CAPTURABLE, const uint64_t &EMPTY, const uint64_t &BP);
std::string possibleWB(const uint64_t &OCCUPIED, const uint64_t &WB, const uint64_t &NON_WHITE_PIECES);
std::string possibleWR(const uint64_t &OCCUPIED, const uint64_t &WR, const uint64_t &NON_WHITE_PIECES);
uint64_t possibleHV(const uint64_t &OCCUPIED, int s);
uint64_t possibleDAD(const uint64_t &OCCUPIED, int s);
uint64_t reverseBits(uint64_t n);

#endif