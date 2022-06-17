#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void f(){
		
	int a;
	//100 instructions:	
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1; a=1;
	}

void g(){ //each f() function is 100 instructions, So g() function is 100×100 = 10,000 instructions:
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
	f(); f(); f(); f(); f(); f(); f(); f(); f(); f();
}

void h(){ //each g() function is 10,000 instructions, So h() function is 100×10,000 = 1,000,000 instructions.
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	g(); g(); g(); g(); g(); g(); g(); g(); g(); g();
	}
		
void x(){ //each h() function is 1,000,000 instructions, So each x() function is 100×1,000,000 = 100,000,000 instructions.
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
	h(); h(); h(); h(); h(); h(); h(); h(); h(); h();
}

void mips(int thread_number){
	long i=0;
	
	uint64_t start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
	
	while(i < 1000000000){
		i=i+100000000;
		x();
	}
	
	uint64_t end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
	
	std::cout << "Thread ";
	std::cout << thread_number;
	std::cout << ", MIPS: ";
	std::cout << ((i*1000)/(end - start));
	std::cout << " from t=";
	std::cout << start;
	std::cout << "ns measured in ";
	std::cout << (end-start);
	std::cout << "ns. \n";
}
	
int main()
{
	//Get number of supported concurrent threads by CPU cores:
	int i, n_threads= std::thread::hardware_concurrency();
	//Create a vector of threads.
	std::vector<std::thread> threads;
	//Add number of threads object to the vector.
	for(i=0;i<n_threads;i++){
		threads.push_back(std::thread(mips, i));
	}
	//Iterate over the thread vector to joining each thread object.
	for(std::thread & th : threads){
		th.join();
	}
	
	std::cout << " By c++ ... . \n";
	return 0;
}
