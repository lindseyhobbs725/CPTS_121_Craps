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
#include "craps.h"

int main(void)
{
	double bank_balance = 0.0, wager = 0.0, earnings = 0.0;
	int die1 = 0, die2 = 0, sum = 0, result = 0,  replay = 0;

	print_game_rules();
	do
	{
		bank_balance = get_bank_balance();
		wager = get_wager_amount(wager, bank_balance);
		printf("Alright, finally... let's test your luck!\n\n");
		srand((unsigned int)time(NULL));
		die1 = roll_die();
		die2 = roll_die();
		sum = calculate_sum_dice(die1, die2);
		result = is_win_loss_or_point(sum);
		if (result == -1)
		{
			wager = additional_wager(wager, bank_balance);
		}
		result = is_point_loss_or_neither(sum, result);
		earnings = adjust_bank_balance(bank_balance, wager, result);
		replay = replay_game(earnings);
	} while (replay == 1);

	return 0;
}

