#include <stdio.h>
#include <stdlib.h>
#include <float.h>


typedef struct Queue Queue;

// Complexity: O(1)
Queue* initPQ();
// Complexity: O(n)
void freePQ(Queue* pq);

/* Priority:
 *	In an ascending priority queue, the "maximum" element is the next to dequeue,
 *	whereas in a descending priority queue, the "minimum" element is next.
 */

 #define SECT_B
 typedef struct {
 	float distance;
 	unsigned int flightNumber;
 	unsigned short passengers;
 } Flight;

 // Complexity: O(n)
 int insertFlightDescendingPQ(Queue *pq, Flight *flight);
 // Complexity: O(n)
 Flight* peekMinFlight(Queue *pq);
 // Complexity: O(n)
 Flight* deQueueMinFlight(Queue *pq);
