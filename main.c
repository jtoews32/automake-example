#include "rover.h"

int main()
{
        int _inc = 0;
        rover _rover;
        int SIZE = 300;
        char move1[SIZE];
        char move2[SIZE];

	max_x = 5;
	max_y = 5;

        move1[0] = 'L';
        move1[1] = 'M';
        move1[2] = 'L';
        move1[3] = 'M';
        move1[4] = 'L';
        move1[5] = 'M';
        move1[6] = 'L';
        move1[7] = 'M';
        move1[8] = 'M';
        move1[9] = '\0';

        _rover = move_rover(create_rover(1, 2, 'N'), &move1[0]);

        printf("%i %i %c\n", _rover._x, _rover._y, int_to_char(_rover._ori));

        move2[0] = 'M';
        move2[1] = 'M';
        move2[2] = 'R';
        move2[3] = 'M';
        move2[4] = 'M';
        move2[5] = 'R';
        move2[6] = 'M';
        move2[7] = 'R';
        move2[8] = 'R';
        move2[9] = 'M';
        move2[10] = '\0';

        _rover = move_rover(create_rover(3, 3, 'E'), &move2[0]);

        printf("%i %i %c\n", _rover._x, _rover._y, int_to_char(_rover._ori));

        return 0;
}

