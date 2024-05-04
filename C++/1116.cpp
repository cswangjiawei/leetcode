class ZeroEvenOdd {
private:
    int n;
    int num_;
    std::mutex mutx;
    std::condition_variable cond;
    int flag;

public:
    ZeroEvenOdd(int n):flag(0) {
        this->n = n;
        this->num_ = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(1) {
            std::unique_lock<std::mutex> lk(mutx);
            cond.wait(lk, [&]{return num_ > n || flag == 0;});
            if (num_ > n) break;
            printNumber(0);
            if (num_%2==0)
                flag = 1;
            else
                flag = 2;
            cond.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(1) {
            std::unique_lock<std::mutex> lk(mutx);
            cond.wait(lk, [&]{return num_>n || flag==1;});
            if (num_ > n) break;
            printNumber(num_);
            flag = 0;
            ++num_;
            cond.notify_all();
        }     
    }

    void odd(function<void(int)> printNumber) {
        while(1) {
            std::unique_lock<std::mutex> lk(mutx);
            cond.wait(lk, [&]{return num_>n || flag==2;});
            if (num_ > n) break;
            printNumber(num_);
            flag = 0;
            ++num_;
            cond.notify_all();
        }
    }
};