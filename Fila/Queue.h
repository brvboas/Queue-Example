/*
 * Queue.h
 *
 *  Created on: 07/10/2009
 *      Author: 317527
 */
#include <iostream>
using namespace std;
#ifndef QUEUE_H_
#define QUEUE_H_

//#define MAX_SIZE 10
class Queue{
	private:
                int tam_max;
		int *entry;
		int rear, front, count;
	public:
		Queue(int t);
		//~Queue();
		bool append(const int &item);
		bool serve( );
		bool retrieve(int &item) const;
		bool empty() const;
		bool full() const;
		void print();
		void print2();
		Queue move(Queue &Aux);
		Queue copy(Queue &Aux);
                Queue concat(Queue &f1, Queue &f2);
                Queue concatInter(Queue &f1, Queue &f2);
                Queue concatOrdem(Queue &f1, Queue &f2);
		};

#endif /* QUEUE_H_ */
