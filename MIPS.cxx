#include <iostream>
#include <thread>
#include <vector>
#include <ctime>

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
	int j;
	time_t start, end;
	
	start = time(NULL);
	
	while(i < 50000000000){
		i=i+10000000000;
		j=0;
		while(j<10){ //Do 100 times x() function = 100×100,000,000 instructions = 10,000,000,000 instructions.
			x(); x(); x(); x(); x();
			x(); x(); x(); x(); x();
			j++;
		}
	}
	
	end = time(NULL);
	
	std::cout << "Thread ";
	std::cout << thread_number;
	std::cout << ", MIPS: ";
	std::cout << ((i/(end - start))/1000000);
	std::cout << " from t=";
	std::cout << start;
	std::cout << " s measured in ";
	std::cout << (end-start);
	std::cout << " s. \n";
}
	
int main()
{
	//You can increase or decrease threads number according to CPU cores number at below line
	int i, n_threads= 8;
	
	std::vector<std::thread> threads;
	
	for(i=0;i<n_threads;i++){
		threads.push_back(std::thread(mips, i));
	}
	
	for(std::thread & th : threads){
		th.join();
	}
	
	/*
	std::thread th1(mips, 1);
	std::thread th2(mips, 2);
	std::thread th3(mips, 3);
	std::thread th4(mips, 4);
	std::thread th5(mips, 5);
	std::thread th6(mips, 6);
	std::thread th7(mips, 7);
	std::thread th8(mips, 8);
	std::thread th9(mips, 9);
	std::thread th10(mips, 10);
	std::thread th11(mips, 11);
	std::thread th12(mips, 12);
	std::thread th13(mips, 13);
	std::thread th14(mips, 14);
	std::thread th15(mips, 15);
	std::thread th16(mips, 16);
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	th6.join();
	th7.join();
	th8.join();
	th9.join();
	th10.join();
	th11.join();
	th12.join();
	th13.join();
	th14.join();
	th15.join();
	th16.join();
	*/
	
	std::cout << " By c++ ... .";
	return 0;
}
