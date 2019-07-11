#include<stdio.h>

typedef struct coordinate{

                           int x, y;
                           char facing;
} coordinate;


coordinate getCoordinate (char *command){

int xAxis = 0, yAxis = 0;
coordinate result = {.x = 0,
                     .y = 0 };

/*
 * Steps which can be taken respective to direction
 * respective to facing. if to go forward or backward
 */
const int xCoor[] = {0, 1, 0, -1},
          yCoor[] = {1, 0, -1, 0};

const char *direction = "NESW";
/*
 * Facing is int variable where below is the mapping with
 * direction
 * 0 - North
 * 1 - East
 * 2 - South
 * 3 - West
 * It will be in circuler form means if it's > 3 than will
 * reset it to 0 and if it's < 0 than reset to 3.
*/
int facing = 0;

   while(*command){

      switch (*command){

         case 'R':
                  ++facing;
                  break;
         case 'L':
                  --facing;
                  break;
         case 'F':
                  xAxis += xCoor[facing];
                  yAxis += yCoor[facing];
                  break;
         default:
                  xAxis -= xCoor[facing];
                  yAxis -= yCoor[facing];
      }

      if (facing < 0)
         facing = 3;
      else if (facing > 3)
         facing = 0;

      ++(command);
   }

   result.x = xAxis;
   result.y = yAxis;
   result.facing = direction[facing];

   return result;
}

int main()
{
char *command = "RRRRRLFFBRLRF";

   coordinate result = getCoordinate(command);

   printf ("(%d, %d)\n", result.x, result.y);
   printf ("Facing is %c\n",result.facing);

   return 0;
}
