//James Adams

#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int key;
    node *next;};

int main(int argc, char* argv[]) {
    if (argc > 3) {
        int i, N = atoi(argv[1]), M = atoi(argv[2]), P = atoi(argv[3]);

        node *t, *x;
        t = new node;
        t->key = 1;
        x = t;
        for (i = 2; i <= N; i++) {
            t->next = new node;
            t = t->next;
            t->key = i;
        }
        t->next = x;

        int rounds = 0;
        while (t != t->next) {

            rounds = rounds + 1;

            if (rounds % 2 != 0) {
                for (i = 1; i < M; i++)
                    t = t->next;
                cout << t->next->key << " has dropped out " << endl;
                x = t->next;
                t->next = x->next;
                delete x;


            } else {

                for (i = 1; i < P; i++)

                    t = t->next;
                cout << t->next->key << " has dropped out " << endl;
                x = t->next;
                t->next = x->next;
                delete x;
            }
        }
        cout << "winner is " << t->next->key << endl;
    }
}