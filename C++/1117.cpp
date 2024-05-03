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


class H2O {
public:
    std::condition_variable cond;
    std::mutex mutx;
    int num;
    H2O():num(2) {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        std::unique_lock<std::mutex> lk(mutx);
        cond.wait(lk, [&]{return num > 0;});
        releaseHydrogen();
        --num;
        if (num == 0) {
            cond.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        std::unique_lock<std::mutex> lk(mutx);
        cond.wait(lk, [&] {return num == 0;});
        releaseOxygen();
        num += 2;
        cond.notify_all();
    }
};