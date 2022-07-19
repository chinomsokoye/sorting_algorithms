#include "deck.h"

/**
 * sort_deck - Sorts a deck of cards
 *
 * @deck: The card deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	size_t len;
	deck_node_t *one, *two, *three, *four;

	len = list_len_deck(*deck);

	if (!deck || !*deck || len < 2)
		return;
	current = *deck;
	while (current)
	{
		if (current->prev && card_value(current) < card_value(
			    current->prev))
		{
			one = current->prev->prev;
			two = current->prev;
			three = current;
			four = current->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			current = *deck;
			continue;
		}
		else
			current = current->next;
	}
}

/**
 * card_value - Returns card value
 *
 * @node: The card node in the deck
 * Return: value
 */
int card_value(deck_node_t *node)
{
	char *valu[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			  "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, kinds_of_valu = 0;

	for (i = 0; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, valu[i - 1]))
			kinds_of_valu = i;
	}
	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
			kinds_of_valu = kinds_of_valu + (13 * i);
	}
	return (kinds_of_valu);
}

/**
 * _strcmp - Compare strings
 *
 * @s1: First string
 * @s2: Second string
 * Return: value
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * list_len_deck - Function for list length
 *
 * @list: List
 * Return: length value
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
