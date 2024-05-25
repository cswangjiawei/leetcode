class FizzBuzz {
private:
    int n;
    std::condition_variable cond;
    std::mutex mutx;
    int cur_n;

public:
    FizzBuzz(int n):cur_n(1) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(1) {
            std::unique_lock<std::mutex> lk(mutx);
            cond.wait(lk, [&]{return (cur_n%3==0 && cur_n%5!=0) || cur_n > n;});
            if (cur_n > n) {
                break;
            }
            printFizz();
            ++cur_n;
            cond.notify_all();
        }
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(1) {
            std::unique_lock<std::mutex> lk(mutx);
            cond.wait(lk, [&]{return (cur_n%3!=0 && cur_n%5==0) || cur_n > n;});
            if (cur_n > n) {
                break;
            }
            printBuzz();
            ++cur_n;
            cond.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(1) {
            std::unique_lock<std::mutex> lk(mutx);
            cond.wait(lk, [&]{return (cur_n%3==0 && cur_n%5==0) || cur_n > n;});
            if (cur_n > n) {
                break;
            }
            printFizzBuzz();
            ++cur_n;
            cond.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(1) {
            std::unique_lock<std::mutex> lk(mutx);
            cond.wait(lk, [&]{return (cur_n%3!=0 && cur_n%5!=0) || cur_n > n;});
            if (cur_n > n) {
                break;
            }
            printNumber(cur_n);
            ++cur_n;
            cond.notify_all();
        }
    }
};