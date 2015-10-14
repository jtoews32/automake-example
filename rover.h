#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

typedef struct {
        int _x;
        int _y;
        int _inc;
        int _ori;       // 0, 1, 2, 3;          0=N, 1=E, S=2, W=3
} rover;

int char_to_inc(char c);
char int_to_char(int i);
rover create_rover(int _x, int _y, char _ori);
int get_ori(int i);
rover move_rover(rover _rover, char* _moves);

int max_x;
int max_y;
