/*
 * queue.h
 *
 *  Created on: Oct 17, 2019
 *      Author: rtrk
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct queue_el
{
	uint_least8_t value;
	uint_least8_t x_coordinate;
	uint_least8_t y_coordinate;
	struct queue_el* next;
}queue_el;

typedef struct queue
{
	queue_el* front;
	queue_el* rear;

}queue;


void queue_initialize(queue* queue_q);

bool queue_empty(queue* queue_q);

void queue_add_element(queue* queue_q, uint_least8_t val, uint_least8_t x_coord, uint_least8_t y_coord);

queue_el queue_get_element(queue* queue_q);

void queue_print_element(queue_el el);





#endif /* QUEUE_H_ */
