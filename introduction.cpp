#include<iostream>
#include<thread>

using namespace std;

void function_1(){
    cout<<"Beauty of thing is joy forever"<<endl;
}

int main(){
    thread t1(function_1);
    //t1.join(); //main thread waits for t1 to finish
    t1.detach(); // t1 is free on its own and main thread may exit before the exc of child

    // you can only join or detatch once. thread::join failed: Invalid argument
    //t1.join();
    //alternatively you can check if the thread is joinable and then do join, which wont crash, but not joins.

    cout<<"Im out"<<endl;

}
