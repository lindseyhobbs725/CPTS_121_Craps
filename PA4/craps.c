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

void print_game_rules(void)
// prints out the rules of the game of "craps"
{
	printf("Hello playa, wanna test your luck?  Then let's play a game, shall we?  This here is CRAPS.\n");
	printf("\nHere are the rules: First you tell me how much money you're holding and you'll place a bet.\nThen you get to roll 2 standard dice. I swear there's no funny business with these 2 die here.\n");
	printf("You're gonna roll 'em, and when they stop I'll add 'em up. Don't worry you can check my work if you don't believe me.\n");
	printf("\nIf they equal 7 or 11, BAM you double your money!\nThey equal 2, 3, or 12, CRAPS! I keep your money.\n\nThey equal 4, 5, 6, 8, 9 or 10, that'll be your 'point'. In order to double your money, you gotta 'make your point' bud.\nRoll until you get what you originally rolled. But don't roll a 7 cuz CRAPS you lose.\n");
	printf("\nSimple enough? Then let's play, shall we?\n\n");
	system("pause");
}

double get_bank_balance(void)
// prompts the player for an initial bank balance from which wagering
// will be added or subtracted. The player entered bank balanced is returned.
{
	double bank_balance = 0.0, add_balance = 0.0;
	int balance_verify = 0;
	printf("\nAlright bud, how much money you holding: ");
	scanf("%lf", &bank_balance);
	printf("Ok so you got $%.2lf, huh? ", bank_balance);
	do
	{
		printf("Wanna add anymore?  (1 to add money, 2 to play): ");
		scanf("%d", &balance_verify);
		if (balance_verify > 2)
		{
			printf("Um... Are you alright there bud?\nLet's try again.\n");
		}
		else if (balance_verify == 1)
		{
			printf("That's what I thought... How much more you got?: ");
			scanf("%lf", &add_balance);
			bank_balance += add_balance;
		}
	} while (balance_verify > 2);
	printf("\nAll right, just so we are clear. You've got $%.2lf to wager.\n\n", bank_balance);

	return bank_balance;
}


double get_wager_amount(double wager, double balance)
// checks to see if the wager is within the limits of the player's available
// balance. If the wager exceeds the player's allowable balance, then 0 is 
// returned, otherwise 1 is returned
{
	double wager_amount = 0.0;
	do
	{
		printf("Place your bet: ");
		scanf("%lf", &wager_amount);
		if (wager_amount > balance)
		{
			printf("C'mon bud, are you being serious?\n");
		}
	} while (wager_amount > balance);
	return wager_amount;
}

double additional_wager(double wager, double balance)
// prompts the player for a potential additional wager on successive rolls
// if the player wants to bet more
{
	int additional_prompt = 0;
	double wager_amount = 0.0, added_wager = 0.0;
	if(wager != balance)	
	{
		do
		{
			printf("\nBefore you try to 'make your point,' *which you won't*\nDo you want to bet more money? (1 to wager more, 2 to continue with current bet): ");
			scanf("%d", &additional_prompt);
			if (additional_prompt > 2)
			{
				printf("Um... Are you alright there bud?\nLet's try again.\n");
			}
			else if (additional_prompt == 1)
			{
				do
				{
					printf("How much more you wanna bet?: ");
					scanf("%lf", &wager_amount);
					added_wager = wager + wager_amount;
					if (added_wager > balance)
					{
						printf("C'mon bud, are you being serious?\n");
					}
				} while (added_wager > balance);
				printf("Alright that's what I'm talking about!! Your bet is now $%.2lf. Let's see if you double it...\n", added_wager);
				system("pause");
			}
			else
			{
				added_wager = wager;
			}
		} while (additional_prompt > 2);
	}
	else
	{
		printf("Well, I'd ask you for more money... but you already bet it all! Let's see if you can double it...\n");
		system("pause");
		added_wager = wager;
	}
	return added_wager;
}

int roll_die(void)
// rolls one die. this function should randomly generate a value between 1-6
// returns the value of the die
{
	int die = 0;
	die = rand() % 6 + 1;
	printf("Dice Roll: %d\n", die);
	return die; 
}

int calculate_sum_dice(int die1_value, int die2_value)
// sums together the values of the two dice and returns the result.
{
	int sum = 0;
	sum = die1_value + die2_value;
	printf("Let's see what you got... %d!\n\n", sum);
	return sum;
}

int is_win_loss_or_point(int sum_dice)
// determines the result of the first dice roll. sum = 7 or 11, player wins and 1
// returned. sum = 2, 3, 12 on first roll, player loses and 0 is returned. 
// sum = 4, 5, 6, 8, 9, 10 on first roll, then the sum becomes the player's 
//"point" and -1 is returned
{
	int result = 0;
	
	
	if (sum_dice == 7 || sum_dice == 11)
	{
		printf("I guess you're luck is up. YOU WON!\n\n");
		result = 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		printf("CRAPS!!!! You lose!\n\n");
		result = 0;
	}
	else
	{
		printf("Alright, now you gotta 'make your point.' Let's roll again.\n\n");
		result = -1;
	}
	return result;
}

int is_point_loss_or_neither(int sum_dice, int point_value)
// determines the result of any successive roll after the first roll.
// sum of roll = point_value, then 1 is returned. sum of roll = 7, 0 is returned.
// otherwise, -1 is returned.
{
	int die1 = 0, die2 = 0, sum = 0, result = 0;
	
	if (sum_dice == 4 || sum_dice == 5 || sum_dice == 6 || sum_dice == 8 || sum_dice == 9 || sum_dice == 10)
	{
		do 
		{
			die1 = roll_die();
			die2 = roll_die();
			printf("Did you 'make your point?' ");
			sum = calculate_sum_dice(die1, die2);
			if (sum_dice == sum)
			{
				printf("Wow. That's impressive... YOU WON!!\n\n");
				result = 1;
			}
			else if (sum == 7)
			{
				printf("That's rough buddy... CRAPS! YOU LOSE!!!\n\n");
				result = 0;
			}
			else
			{
				printf("That's not a %d. Roll again.\n\n", sum_dice);
				result = -1;
				system("pause");
			}
		} while (result == -1);
	}
	else
	{
		result = point_value;
	}
	
	return result;
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
// If add_or_subtract = 1, wager amount is added to the bank_balance.
// If add_or_subtract = 0, wager amount is subtracted from bank_balance.
// otherwise bank_balance remains same. bank_balance result is returned.
{
	double balance = 0.0;
	if (add_or_subtract == 1)
	{
		balance = bank_balance + wager_amount;
	}
	else if (add_or_subtract == 0)
	{
		balance = bank_balance - wager_amount;
	}

	printf("After that, here's what you've got: $%.2lf \n", balance);
	return balance;
}

int replay_game(double bank_balance)
// prompts the player to see if they want to play again
{
	int replay = 0;
	if (bank_balance == 0)
	{
		printf("Have a nice day... unless you have more money you're hiding? (1 to play again, 2 to close game): \n");
		scanf("%d", &replay);
		if (replay == 1)
		{
			printf("\nAlright! But you're gonna have to cough up some more dough. ");
		}
		else
		{
			replay = 0;
		}
		system("pause");
	}
	else if (bank_balance != 0)
	{
		printf("Wanna test your luck again? (1 to play again, 2 to close game): \n");
		scanf("%d", &replay);
		
	}
	system("cls");
	return replay;
}