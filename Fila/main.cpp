/*
 * main.cpp
 *
 *  Created on: 07/10/2009
 *      Author: 317527
 */ 
#include "Queue.h"
int main(){

        int t, x;
        cout << "digite o tamanho da fila q deseja" << endl;
        cin >> t;
        cout << "digite os valores na pilha" << endl;
        Queue q(t), q2(t), qcopy(t), qconcat(2*t);
        Queue qconcat2(3*t);
        while(!q.full()){
            cin >> x;
            q.append(x);
        }
	
	cout << "q: ";
	q.print();
	cout << endl;
	cout << "q(print2): ";
	q.print2();
	cout << endl;
	q.move(q2);
	cout << "q2: ";
	q2.print2();
	cout << endl;
	q2.copy(qcopy);
	cout << "qcopy: ";
	qcopy.print2();
        qconcat.concat(q2,qcopy);
        cout << endl << "qconcat: ";
        qconcat.print2();
        cout << endl;
        qconcat2.concatInter(q2, qconcat);
        cout << endl << "qconcat2: ";
        qconcat2.print2();
        cout << endl;
	return 0;
}
//112233445512345