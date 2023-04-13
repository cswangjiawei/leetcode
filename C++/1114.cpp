#include <semaphore.h>

class Foo {
private:
    sem_t sem_first;
    sem_t sem_second;
    sem_t sem_third;
public:
    Foo() {
        sem_init(&sem_first, 0, 1);
        sem_init(&sem_second, 0, 0);
        sem_init(&sem_third, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        sem_wait(&sem_first);
        printFirst();
        sem_post(&sem_second);
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        sem_wait(&sem_second);
        printSecond();
        sem_post(&sem_third);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        sem_wait(&sem_third);
        printThird();
        sem_post(&sem_first);
    }
};