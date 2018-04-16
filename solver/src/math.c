/*
** EPITECH PROJECT, 2018
** math.c
** File description:
**
*/

#include "solver.h"

int manhattan_distance(struct cell *start, struct cell *end)
{
	double res = sqrt((start->x - end->x) * (start->x - end->x) +
		(start->y - end->y) * (start->y - end->y));

	return ((int)res);
}

struct cell *clean_bucket(struct request *req, struct cell **bucket,
	struct cell *end)
{
	const int bucket_size = 4;
	int dist = INT_MAX;
	struct cell *nearest = NULL;

	for (int i = 0; i < bucket_size; i++) {
		if (bucket[i] == NULL || bucket[i]->state != EMPTY ||
		!(bucket[i]->id >= 0 && bucket[i]->id <= req->real_len - 1))
			continue;
		if (bucket[i]->end == true)
			return (bucket[i]);
		if (manhattan_distance(bucket[i], end) < dist ||
			(manhattan_distance(bucket[i], end) <= dist
			&& rand() % 2 == 1)) {
			dist = manhattan_distance(bucket[i], end);
			nearest = bucket[i];
		}
	}
	return (nearest);
}