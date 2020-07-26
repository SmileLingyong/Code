#include <iostream>
#include <sys/time.h>
using namespace std;
int main() {
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    gettimeofday(&start, NULL);

    cout << "Hello, World!" << endl;

    gettimeofday(&end, NULL);
    timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    cout << "timer: " << timer << " us" << endl;
    return 0;
}