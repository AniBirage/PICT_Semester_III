/*
Queues are frequently used in computer programming, and a 
typical example is the creation of a job queue by an operating 
system. If the operating system does not use priorities, then 
the jobs are processed in the order they enter the system. 
Write C++ program for simulating job queue. Write 
functions to add job, display job and delete job from queue.
*/

#include<iostream>
#include<string>
using namespace std ;

class queue{
public :
    string data[20] ; 
    int front = -1; 
    int back = -1;

    void add(string job){
        if(front ==-1){
            front ++ ;
            back ++ ; 
            data[front] = job ;
        }
        else{
            back ++ ; 
            data [ back ] = job ; 
        }
        cout<<"Job Added";
    }

    void display (){
        cout<<"Jobs Are:"<<endl;
        for (int i = front ; i <= back ; i++ ){
            cout << data [ i ] << endl ;
        }
    }

    void delete_job(){
        if(front > back){
            cout<<"there are no jobs to delete"<<endl ; 
        }
        else {
            front ++ ;
            cout<<"Job Deleted";
        }
    }
}; 

int main(){
    queue Q ;
    while(1>0){
        cout<<"\nEnter the option you want to perform \n1)Add Job\n2)Remove job\n3)display all jobs\n0)Exit"<<endl ;
        int menu ; 
        cin >> menu ; 
        if(menu == 0 ){
            break ;
        }
        else if(menu == 1){
            cout<<"enter the new job name"<<endl ;
            string new_job ; 
            cin >> new_job ; 
            Q.add(new_job) ; 
        }
        else if(menu == 2){
            Q.delete_job();
        }
        else if(menu == 3){
            Q.display();
        }
        else {
            cout<<"enter a valid option "<<endl ;
        }
    }
    return 1 ; 
}