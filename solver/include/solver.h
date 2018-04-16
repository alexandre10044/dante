/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef SOLVER_
	#define SOLVER_

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <stdbool.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <limits.h>
	#include <time.h>
	#include <math.h>

	#define EXIT_NORMAL (0)
	#define EXIT_FAIL (84)

	#define NO_SOLUTION ("no solution found\n")

struct request {
	struct cell **cells;
	int cells_len;
	int real_len;
	int map_width;
	int map_height;
};

struct cell {
	int id;
	int x;
	int y;
	int start;
	int end;
	int state;
};

enum cell_state {
	EMPTY,
	FILL,
	USED
};

// engine.c
void process(struct request *req);
int find_path(struct request *req, struct cell *start, struct cell *end);
struct cell *find_nearest(struct request *req, struct cell *current,
	struct cell *end);
void compute_result(struct request *req);

// instances.c
struct request *get_instance(const char *file_name);
struct cell *get_cell(int id, int x, int y, int state);
int serialize_instance(struct request *req, char *content);
void free_instance(struct request *req);

// main.c
int check_file(char *content);

// map.c
int get_map_width(char *str);
int get_map_height(char *str);
void clear_map(struct request *req);
struct cell *get_cell_by_id(struct request *req, int id);
int get_state(char c);

// math.c
int manhattan_distance(struct cell *start, struct cell *end);
struct cell *clean_bucket(struct request *req, struct cell **bucket,
	struct cell *end);

// output.c
void my_put_char(char c);
void my_put_str(const char *str);

// output.c
void my_put_char(char c);
void my_put_str(const char *str);

// reader.c
char *read_file(const char *file_name);
char *get_line(char *str, int start);

// utils.c
int my_strlen(const char *str);
int string_len(char *str, char c);

#endif /* SOLVER */