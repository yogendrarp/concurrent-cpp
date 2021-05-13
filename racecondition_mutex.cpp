#include<iostream>
#include<thread>
#include<string>
#include<mutex>

using namespace std;
std::mutex mu;

class Logfile{
    std::mutex m_mutex;
    ofstream f;
public:
    Logfile(){
        f.open("log.txt");
    }
    void share_printer(string id, int value){
        std::lock_guard<mutex> locker(m_mutex);
        f << "from " <<id<< " : "<<value<<endl;
    }
// But never expose f nor create another print function for example like below
    ofstream& getStream(){return f;}
    void processf(void fun(ofstream&)){
        fun(f);
    }


};


// void shared_printer(string msg, int id){
// //     mu.lock();
// //     cout<<msg<<id<<endl; // what if this line throws an exceptiom?? so its recommended to use lock_gauard
// //     mu.unlock();
// // 
//     lock_guard<mutex> guard(mu); // scope based locking,  but this wont lock cout in anycase, its only a lock on sh_poi function
//     cout<<msg<<id<<endl;
// }

void function_f1(Logfile& log){
    for(int i=0;i>-100;i--){
        log.share_printer("from t1 : ",i);
    }
}

int main(){
    Logfile log;
    std::thread t1(function_f1, std::ref(log));
    for(int i=0;i<100;i++){
        log.share_printer("from main : ",i);
    }

    t1.join();
}