/* CS261- Assignment 3 - Problem 3*/
/* Name: Joseph DePrey
 * Date: 4/24/2016
 * Solution description: Circular List Implementation 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(  struct CircularList* list )
{
	assert( list != 0 );
	
	// Allocate memory for sentinel
	list->sentinel = malloc( sizeof( struct Link ) );
	assert( list->sentinel != 0 );
	
	list->size = 0;

	// Make sentinel point to itself
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink( TYPE value )
{
	struct Link* newLink = malloc( sizeof( struct Link ) );
	assert( newLink != 0 );
	newLink->value = value;
	newLink->next = 0;
	newLink->prev = 0;
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter( struct CircularList* list, struct Link* link, TYPE value )
{
	assert( list != 0 );
	assert( link != 0 );
	struct Link* newLink = createLink( value );
	
	newLink->prev = link;
	newLink->next = link->next;
	link->next->prev = newLink;
	link->next = newLink;
	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink( struct CircularList* list, struct Link* link )
{
	assert( list != 0 );
	assert( link != 0 );
	// reassign pointers around link
	link->prev->next = link->next;
	link->next->prev = link->prev;

	free( link );
	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate(  )
{
	struct CircularList* list = malloc( sizeof ( struct CircularList ) );
	init( list );
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy( struct CircularList* list )
{
	assert( list != 0 );
	while( !circularListIsEmpty( list ) )
	{
		circularListRemoveFront( list );
	}
	free( list->sentinel );
	free( list );
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront( struct CircularList* list, TYPE value )
{
	// Add link after the sentinel
	addLinkAfter( list, list->sentinel, value );
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack( struct CircularList* list, TYPE value )
{
	// Add link after the link before the sentinel
	addLinkAfter( list, list->sentinel->prev, value );
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront( struct CircularList* list )
{
	assert( list != 0 );
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack( struct CircularList* list )
{
	assert( list != 0 );
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront( struct CircularList* list )
{
	removeLink( list, list->sentinel->next );
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack( struct CircularList* list )
{
	removeLink( list, list->sentinel->prev );
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty( struct CircularList* list )
{
	assert( list != 0 );
	return list->size == 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint( struct CircularList* list )
{
	assert( list != 0 );
	// Make sure list is not empty
	assert( !circularListIsEmpty( list ) );
	// Assign temp the value of the link at the front of list
	struct Link* temp = list->sentinel->next;
	assert( temp != 0 );
	// Use a temp variable to iterate through the list
	printf( "Printing entire list...\n" );
	while( temp != list->sentinel ){
		printf( "%g\n", temp->value );
		temp = temp->next;
	}
}

/**
 * Reverses the deque.
 */
void circularListReverse( struct CircularList* list )
{
	assert( list != 0 );
	// Make sure list is not empty
	assert( !circularListIsEmpty( list ) );
	// Assign temp the value of the link at the front of list
	struct Link* temp = list->sentinel->next;
	assert( temp != 0 );

	// Use a temp variable to iterate through the list, reversing the pointers
	while( temp != list->sentinel ){
		struct Link* nextTemp = temp->next;
		struct Link* prevTemp = temp->prev;
		temp->prev = temp->next;
		temp->next = prevTemp;
		//Go to next node
		temp = nextTemp;
	}
	// Reassign temp to reverse the sentinel pointers
	temp = list->sentinel->next;
	list->sentinel->next = list->sentinel->prev;
	list->sentinel->prev = temp;
	printf( "List reversed\n" );

}
