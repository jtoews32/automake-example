#include "rover.h"

int char_to_inc(char c)
{
	switch(c)
	{
		case 'N' : return 0; break;
		case 'E' : return 1; break;
		case 'S' : return 2; break;
		case 'W' : return 3; break;
		default : return -1; break;
	}
	return -1;
}

char int_to_char(int i)
{
        switch(i)
        {
                case 0 : return 'N'; break;
                case 1 : return 'E'; break;
                case 2 : return 'S'; break;
                case 3 : return 'W'; break;
                default : return -1; break;
        }
        return -1;	
}

rover create_rover(int _x, int _y, char _ori) 
{
	rover _rover;
	_rover._x = _x;
	_rover._y = _y;
	_rover._inc = char_to_inc(_ori);
	_rover._ori = char_to_inc(_ori);	// 0, 1, 2, 3 : 
	return _rover;
}

int get_ori(int i) 
{
	int val = 0;
	if(i < 0)
        	val = (4+i) % 4;
  	else 
          	val = i % 4;

	return val;
}

rover move_rover(rover _rover, char* _moves)
{
	int _inc = 0;  
	while(_moves[_inc] != '\0') 
	{	
		char _move = _moves[_inc];		
		if (_move == 'L')
		{
			#if DEBUG	
				printf("%c \n", _move);
			#endif	

			_rover._ori = get_ori(--_rover._inc);
		}	

		if (_move == 'R')
		{	
			#if DEBUG
				printf("%c \n", _move);
			#endif

			_rover._ori = get_ori(++_rover._inc);
		}

		if( _move == 'M' )
		{
			#if DEBUG
				printf("%c %i", _move, _rover._ori);
			#endif

			switch(_rover._ori)
			{
				case 0 :  
					if(_rover._y < max_y ) // max_y	
					{
						++_rover._y;
						#if DEBUG 
							printf("%s \n", "++_rover._y");
						#endif
					} break;

				case 1 :  
					if(_rover._x < max_x) // max_x
					{
						++_rover._x;

						#if DEBUG
							printf("%s \n", "++_rover._x");
						#endif
					} break;

				case 2 :  
					if(_rover._y > 0)
					{
						--_rover._y;

						#if DEBUG
							printf("%s \n", "--_rover._y"); 
						#endif
					} break;

				case 3 :  
					if(_rover._x > 0)
					{
						--_rover._x;			

						#if DEBUG		
							printf("%s \n", "--_rover._x");
						#endif 
					} break;

				default: 
					#if DEBUG
						printf("<error>: default clause in case stmt reached");
					#endif
					break;
			}	
		}
		++_inc;
	}
	
	return _rover;
}
