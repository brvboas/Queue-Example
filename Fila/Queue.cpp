/*
 * Queue.cpp
 *
 *  Created on: 07/10/2009
 *      Author: 317527
 */
#include "Queue.h"

//CONSTRUTOR: inicializa o count =0 o front =0 e o rear = MAX_SIZE -1
Queue::Queue(int t){
	count = 0;
	front = 0;
        tam_max = t;
	rear = tam_max -1;
        entry= new int[tam_max];
}

//EMPTY: verifica se a fila est� vazia
bool Queue::empty() const{
	if (count == 0) return true;
	return false;
}

//FULL: verifica se a fila est� cheia
bool Queue::full()const{
	if (count == tam_max) return true;
	return false;
}

//APPEND: insere um elemento no final da fila, se a fila n�o estiver cheia
bool Queue::append(const int &item){
	if (count >= tam_max) return false; //overflow
	count++;
	rear = (rear+1)%tam_max;
	/*// rear = (rear+1)%MAX_SIZE; � equivalente a
		if (rear == MAX_SIZE � 1)
		rear = 0;
		else
		rear ++;
		*/
	entry[rear] = item;
	return true;
}

//SERVE: remove o primeiro elemento da fila, se a fila n�o estiver vazia
bool Queue::serve( ){
	if (count <= 0) return false;
	count--;
	front = (front+1)%tam_max;
	return true;
}

//RETRIEVE: consulta qual o elemento que est� no in�cio da fila
bool Queue::retrieve(int &item) const{
	if (count <= 0) return false; //underflow
	item = entry[front];
	return true;
}

/* The front of the Queue retrieved to the output
parameter item. If the Queue is empty return an
Error_code of underflow.
bool Queue :: retrieve(int &item) const
{
if (count <= 0) return underflow;
item = entry[front];
return success;
}*/

//PRINT: imprime os dados da lista acrescentando seus elementos temporariamente em uma lista AUX.
void Queue::print(){
	Queue Aux(tam_max);
	int x;
	while(!empty()){
		retrieve(x);
		cout << x ;
		serve();
		Aux.append(x);
	}
	while(!Aux.empty()){
		Aux.retrieve(x);
		Aux.serve();
		append(x);
	}
}

//PRINT2: imprime os dados da fila sem usar uma fila auxiliar.
void Queue::print2(){
	int x;
	for(int i=0; i<count; i++){
		retrieve(x);
		cout << x;
		serve();
		append(x);
	}
}

//MOVE: move os dados de uma fila para outra.
Queue Queue::move(Queue &Aux){
	int x;
	while(!empty()){
			retrieve(x);
			serve();
			Aux.append(x);
		}
	return Aux;
}

//COPY: copia os elementos da fila 1 pra fila 2;
Queue Queue::copy(Queue &Aux){
	int x;
	for(int i=0; i<count; i++){
		retrieve(x);
		serve();
		Aux.append(x);
		append(x);
	}
	return Aux;
}

//CONCAT: contatena duas filas em uma terceira fila
Queue Queue::concat(Queue &f1, Queue &f2){
    int x;
    for(int i=0 ; i<f1.count ; i++){
        f1.retrieve(x);
        append(x);
        f1.serve();
        f1.append(x);
    }
    for(int j=0 ; j<f2.count ; j++){\
        f2.retrieve(x);
        append(x);
        f2.serve();
        f2.append(x);
    }
}

//CONCATINTER: Concatena dulas fila intercalando-as em uma terceira
Queue Queue::concatInter(Queue &f1, Queue &f2){
    int x, t, t2, t3;
    if (f1.count <= f2.count){
        t=f2.count;
        t2=f2.count-f1.count;
    }
    else {
        t=f1.count;
        t3=f1.count-f2.count;
    }
    for(int i=0 ; i<t ; i++){
        f1.retrieve(x);
        append(x);
        f1.serve();
        f1.append(x);
        f2.retrieve(x);
        append(x);
        f2.serve();
        f2.append(x);
    }
    for(int i=0 ; i<t2 ; i++){
        f2.retrieve(x);
        append(x);
        f2.serve();
        f2.append(x);
    }
    for(int i=0 ; i<t3 ; i++){
        f1.retrieve(x);
        append(x);
        f1.serve();
        f1.append(x);
    }

}

//CONCATORDEM: Concatena duas filas ordenando-as em uma terceira fila
Queue Queue::concatOrdem(Queue &f1, Queue &f2){

}