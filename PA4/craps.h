/*
* Programmer: Lindsey Hobbs
* Class: Cpts 121; Lab Section 8
* Programming Assignment: PA4
* Date: 10/12/2020
* 
* Description: Based on the given assignment, the program will
*				allow the user to pay in a game of craps until
*				they win or lose. The game will include placing
*				bets and chatter to keep the player interested 
*				in the game.
*/

#ifndef CRAPS_H
#define CRAPS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

void print_game_rules(void);
// prints out the rules of the game of "craps"

double get_bank_balance(void);
// prompts the player for an initial bank balance from which wagering
// will be added or subtracted. The player entered bank balanced is returned.

double get_wager_amount(double wager, double balance);
// checks to see if the wager is within the limits of the player's available
// balance. If the wager exceeds the player's allowable balance, then 0 is 
// returned, otherwise 1 is returned

double additional_wager(double wager, double balance);
// prompts the player for a potential additional wager on successive rolls
// if the player wants to bet more

int roll_die(void);
// rolls one die. this function should randomly generate a value between 1-6
// returns the value of the die

int calculate_sum_dice(int die1_value, int die2_value);
// sums together the values of the two dice and returns the result.

int is_win_loss_or_point(int sum_dice);
// determins the result of the first dice roll. sum = 7 or 11, player wins and 1
// returned. sum = 2, 3, 12 on first roll, player loses and 0 is returned. 
// sum = 4, 5, 6, 8, 9, 10 on first roll, then the sum becomes the player's 
//"point" and -1 is returned

int is_point_loss_or_neither(int sum_dice, int point_value);
// determines the result of any successive roll after the first roll.
// sum of roll = point_value, then 1 is returned. sum of roll = 7, 0 is returned.
// otherwise, -1 is returned.

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
// If add_or_subtract = 1, wager amount is added to the bank_balance.
// If add_or_subtract = 0, wager amount is subtracted from bank_balance.
// otherwise bank_balance remains same. bank_balance result is returned.


int replay_game(double bank_balance);
// prompts the player to see if they want to play again


#endif