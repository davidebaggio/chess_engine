#ifndef BOARD_GEN_H
#define BOARD_GEN_H

#include <iostream>
#include <string>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void std_board_init(std::string *init);
void array_to_bit_board(std::string *board, uint64_t &WP, uint64_t &WN, uint64_t &WB, uint64_t &WR, uint64_t &WQ, uint64_t &WK, uint64_t &BP, uint64_t &BN, uint64_t &BB, uint64_t &BR, uint64_t &BQ, uint64_t &BK);
void print_bit_board(uint64_t board);
void print_board(std::string *board);
void print_board_from_bits(uint64_t &WP, uint64_t &WN, uint64_t &WB, uint64_t &WR, uint64_t &WQ, uint64_t &WK, uint64_t &BP, uint64_t &BN, uint64_t &BB, uint64_t &BR, uint64_t &BQ, uint64_t &BK);
void pack_bits(uint64_t *pack, uint64_t &WP, uint64_t &WN, uint64_t &WB, uint64_t &WR, uint64_t &WQ, uint64_t &WK, uint64_t &BP, uint64_t &BN, uint64_t &BB, uint64_t &BR, uint64_t &BQ, uint64_t &BK);
void unpack_bits(uint64_t *bits, uint64_t &WP, uint64_t &WN, uint64_t &WB, uint64_t &WR, uint64_t &WQ, uint64_t &WK, uint64_t &BP, uint64_t &BN, uint64_t &BB, uint64_t &BR, uint64_t &BQ, uint64_t &BK);

#endif