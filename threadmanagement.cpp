#include<iostream>
#include<thread>

using namespace std;

void function_1(){
    cout<<"Beauty of a thing is joy forever" <<endl;
}


class Fctor{
    public:
        void operator()(string& msg){
            // for(int i=0;i>-100;i--){
            //     cout<<"from t1 "<<i<<endl;
            // }
            cout<<"From t1: "<<msg<<endl;
        }
};

int main(){
    string s="To err is human, to forgive is idiotic";
    //thread t1(function_1);
    
    thread t1((Fctor()),std::ref(s));// even though we pass by reference, for athread a copy is always maede
    
    // we are taking a function and a pointer. it wont work as thread
    // the main thread must do some other work after it spawns a child thread. else wont makle sense. If the main thread exceptions out before joining the thread, it will be terminated,

    // try{
    //     for(int i=0;i<100;i++){
    //         cout<<"from main "<<i<<endl;
    //     }
    // }catch(exception e){
    //     t1.join();
    // }
     cout<<"From main: "<<s<<endl;

     // its recommeded to create only number of threads which  umber of cores
     std::thread::hardware_concurrency();//indication
    t1.join();

    // A thread can also be joined, using functor or lambda

}