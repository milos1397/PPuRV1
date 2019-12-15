/*
 * queue.c

 *
 *  Created on: Oct 17, 2019
 *      Author: rtrk
 */
#include "queue.h"



void queue_initialize(queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

bool queue_empty(queue* queue)
{
	if(queue->front == NULL){
		return true;
	}else
	{
		return false;
	}
}


void queue_add_element(queue* queue, uint_least8_t val, uint_least8_t x_coord, uint_least8_t y_coord)
{

	queue_el* elem=(queue_el*)(malloc(sizeof(queue_el)));
	elem->value = val;
	elem->x_coordinate = x_coord;
	elem->y_coordinate = y_coord;
	elem->next = NULL;


	if(queue_empty(queue))
	{
		queue->front = elem;
		queue->rear = elem;
	}else
	{
		queue->rear->next = elem;
		queue->rear = elem;
	}
}

queue_el queue_get_element(queue* queue)
{
	queue_el element = *(queue->front);
	//printf("nesto");

	//printf("Koordinate %d%d",element.x_coordinate,element.y_coordinate);
	if(!queue_empty(&queue))
	{
		free(queue->front);
		queue->front = element.next;
		//printf("Koordinate %d%d",queue->front->x_coordinate,queue->front->y_coordinate);
		element.next = NULL;
	}

	return element;
}

void queue_print_element(queue_el element)
{
	printf("Element at x:%"PRIxLEAST8" y:%"PRIxLEAST8" value:%"PRIxLEAST8"\n",element.x_coordinate,
			element.y_coordinate,element.value);

}
