/*
 * main.c
 *
 *  Created on: Oct 17, 2019
 *      Author: rtrk
 */

#include <queue.h>

// M x N matrix
#define M 8
#define N 10

#define SIZE 40

// Below arrays details all 8 possible movements
static int_least8_t row[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
static int_least8_t col[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

static int_least8_t num_col;
static int_least8_t num_row;

// check if it is possible to go to pixel (x, y) from
// current pixel. The function returns false if the pixel
// has different color or it is not a valid pixel
bool isSafe(uint_least8_t* array, uint_least8_t x, uint_least8_t y, uint_least8_t target)
{
    return (x >= 0 && x < num_row && y >= 0 && y < num_col)
        && *(array + x*num_col + y) == target;
}

// Flood fill using BFS
void floodfill(uint_least8_t* array, uint_least8_t x,uint_least8_t y,uint_least8_t replacement)
{
    // create a queue and enqueue starting pixel
	queue my_queue;
	queue_initialize(&my_queue);

    queue_add_element(&my_queue,*(array+num_col*x+y),x,y);

    // get target color
    uint_least8_t target = *(array+num_col*x+y);

    // run till queue is not empty
    while (!queue_empty(&my_queue))
    {
        // pop front node from queue and process it

    	queue_el element = queue_get_element(&my_queue);

    	//queue_print_element(element);

        // (x, y) represents current pixel
    	uint_least8_t el_x = element.x_coordinate;
    	uint_least8_t el_y = element.y_coordinate;

        // replace current pixel color with that of replacement
    	*(array+num_col*el_x+el_y) = replacement;

        // process all 8 adjacent pixels of current pixel and
        // enqueue each valid pixel
        uint_least8_t k;
        for (k = 0; k < 8; k++)
        {
            // if adjacent pixel at position (x + row[k], y + col[k]) is
            // a valid pixel and have same color as that of current pixel
            if (isSafe(array, el_x + *(row + k), el_y + *(col + k), target))
            {
                // enqueue adjacent pixel
            	queue_add_element(&my_queue, *(array + num_col * (el_x + *(row + k)) + (el_y + *(col + k))),
            			el_x + *(row + k), el_y+ *(col + k));
                //queue_add_element(&my_queue, mat[el_x+row[k]][el_y+col[k]], el_x+row[k], el_y+col[k]);
                //printf("x = %d, y = %d",x1+row[k],y1+col[k]);
                fflush(stdout);
            }
        }
    }
}

// main function
int main()
{
    // matrix showing portion of the screen having different colors
	uint_least8_t my_array[SIZE];

	char c;
	FILE *file;
	file = fopen("matrix.txt", "r");
	if (file)
	{
		uint_least8_t i = 0;
		while ((c = getc(file)) != EOF)
	    {
			if(c != '\n')
			{
		    	*(my_array+i) = ((uint_least8_t)c)-48;
		    	i++;
		    	num_col++;
			}
			else
			{
				num_col=0;
				num_row++;
			}
	    }
	    fclose(file);
	}
	num_row++;

	printf("%d, %d \n",num_row,num_col);
	uint_least8_t n;
	/*for(n = 0; n < 40 ; n++){
		printf("%d ",*(my_array+n));
		//fflush(stdout);
	}*/



    uint_least8_t x_coord = 4;
    uint_least8_t y_coord = 4;

    // replacement color

    uint_least8_t replacement = 8;

    // replace target color with replacement color
    floodfill(my_array, x_coord, y_coord, replacement);

    /*printf("kraj\n");
    //print the colors after replacement*/
    uint_least8_t j;
    uint_least8_t i;
    for (i = 0; i < num_row; i++)
    {
        for (j = 0; j < num_col; j++)
            printf("%d ",*(my_array + i*num_col + j));
        printf("\n");
    }
    return 0;
}

