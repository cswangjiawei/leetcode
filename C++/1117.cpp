class H2O {
public:
    sem_t sem_H;
    sem_t sem_O;
    H2O() {
        sem_init(&sem_H, 0, 2);
        sem_init(&sem_O, 0, 2);
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        sem_wait(&sem_H);
        releaseHydrogen();
        sem_post(&sem_O);
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        sem_wait(&sem_O);
        sem_wait(&sem_O);
        releaseOxygen();
        sem_post(&sem_H);
        sem_post(&sem_H);
    }
};