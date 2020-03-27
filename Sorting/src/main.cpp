#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include "mergesort.hh"
#include "quicksort.hh"
#include "introsort.hh"

void reverse (int *tab,int size)
{
	int i, h;

	for (i = 0; i < size/2;i++)
	{
		h = tab[i];
		tab[i] = tab[size-1-i];
		tab[size-1-i] = h;
	}
}

bool check(int *tab, int size)
{
	int i;
	for (i = 0; i< size-2;i++)
	{
		if (tab[i+1] < tab[i])
		{
			std::cout << tab[i+1] <<"  " <<tab[i];
			return 1;
		}
	}
	return 0;
}

bool check_rev(int *tab, int size)
{
	int i;
	for (i = 0; i< size-2;i++)
	{
		if (tab[i+1] > tab[i])
		{
			std::cout << tab[i+1] <<"  " <<tab[i];
			return 1;
		}
	}
	return 0;
}

int random(int bot_range, int top_range)
{
	int range = top_range - bot_range+1;
	int rnd = bot_range + std::rand() % range;
	return rnd;
}

int main()
{
	std::ofstream fName;
	int rep = 100;
	int size = 1000000;
	char option;
	int i,o = 0,r,a;
	int *tab = new int[size];
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = std::chrono::high_resolution_clock::now();
	for(i = 0;i<size;i++)
	{
		tab[i]=random(0,size);
	}

	std:: cout << "Menu:"<<std::endl;
	std:: cout << " s - new size (default 1 000 000)"<<std::endl;
	std:: cout << " r - reverse sorted table"<<std::endl;
	std:: cout << " p - sort partialy"<<std::endl;
	std:: cout << " v - show table"<<std::endl;
	std:: cout << " q - quicksort"<<std::endl;
	std:: cout << " i - introsort"<<std::endl;
	std:: cout << " m - mergesort"<<std::endl;
	std:: cout << " k - end program"<<std::endl;

	a = 0;
	o = 0;

	while (option != 'k' )
	{
		std:: cout << std::endl;
		std:: cout << " option (h - menu):";
		std:: cout << std::endl;
		std:: cin >> option;
		std:: cout << std::endl;

		switch(option){

			case 'h':
				std:: cout << "Menu:"<<std::endl;
				std:: cout << " h - show menu"<<std::endl;
				std:: cout << " s - new size (default 1 000 000)"<<std::endl;
				std:: cout << " r - reverse sorted table"<<std::endl;
				std:: cout << " p - sort partialy"<<std::endl;
				std:: cout << " v - show table"<<std::endl;
				std:: cout << " q - quicksort"<<std::endl;
				std:: cout << " i - introsort"<<std::endl;
				std:: cout << " m - mergesort"<<std::endl;
				std:: cout << " k - end program"<<std::endl;
				break;
			case 's':
				std:: cout << "\n New table size: ";
				std:: cin >> size ;
				std::cout << "\n New size :" << size << std::endl;

				for(i = 0;i<size;i++)
				{
					tab[i]=random(0,size);
				}

				break;

			case 'r':
					a = 1;
				break;

			case 'p':
				std::cout << "\n Choose sorted part: \n";
				std::cout << "\n  0 - no sorting\n  1 - 25%\n  2 - 50%\n  3 - 75%\n  4 - 95%\n  5 - 99%\n  6 - 99,7%"<<std::endl;
				std::cin >> o;

				break;

			case 'v':
				for (i = 0; i<size-1;i++)
				{
					std::cout<< tab[i] <<" ";
				}
				std::cout<< tab[i] <<" \n";
				break;
			case 'q':
				fName.open("data/quicksort.txt");
				for(r = 0; r<rep; r++){

					for(i = 0;i<size;i++)
					{
						tab[i]=random(0,size);
					}

					if (o == 1)
					{
						introsort<int>(tab,0 ,size*0.25);
					}
					else if (o == 2)
					{
						introsort<int>(tab,0 ,size*0.5);
					}
					else if (o == 3)
					{
						introsort<int>(tab,0 ,size*0.75);
					}
					else if (o == 4)
					{
						introsort<int>(tab,0 ,size*0.95);
					}
					else if (o == 5)
					{
						introsort<int>(tab,0 ,size*0.99);
					}
					else if (o == 6)
					{
						introsort<int>(tab,0 ,size*0.997);
					}

					if (a == 1){
						introsort<int>(tab,0, size-1);
						reverse(tab, size);
						if(check_rev(tab,size) !=0)
						{
							std::cout << "\n\n NOT sorted \n\n";
						}
					}
					start = std::chrono::high_resolution_clock::now();
					quicksort<int>(tab,0, size-1);
					stop = std::chrono::high_resolution_clock::now();

					if (check(tab,size) != 0)
					{
						std::cout << "\n\n NOT sorted \n\n";
					}

					fName << std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count()<< " ms. \n";


				}
				fName.close();
				break;

			case 'i':
				fName.open("data/introsort.txt");
				for(r = 0; r<rep; r++){

					for(i = 0;i<size;i++)
					{
						tab[i]=random(0,size);
					}

					if (o == 1)
					{
						introsort<int>(tab,0 ,size*0.25);
					}
					else if (o == 2)
					{
						introsort<int>(tab,0 ,size*0.5);
					}
					else if (o == 3)
					{
						introsort<int>(tab,0 ,size*0.75);
					}
					else if (o == 4)
					{
						introsort<int>(tab,0 ,size*0.95);
					}
					else if (o == 5)
					{
						introsort<int>(tab,0 ,size*0.99);
					}
					else if (o == 6)
					{
						introsort<int>(tab,0 ,size*0.997);
					}

					if (a == 1){
						introsort<int>(tab,0 ,size);
						reverse(tab, size);
						if(check_rev(tab,size) !=0)
						{
							std::cout << "\n\n NOT sorted \n\n";
						}
					}
					start = std::chrono::high_resolution_clock::now();
					introsort<int>(tab,0, size-1);
					stop = std::chrono::high_resolution_clock::now();

					if (check(tab,size) != 0)
					{
						std::cout << "\n\n NOT sorted \n\n";
					}

					fName << std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count()<< " ms. \n";

				}
				fName.close();
				break;

			case 'm':
				fName.open("data/mergesort.txt");
				for(r = 0; r<rep; r++){

					for(i = 0;i<size;i++)
					{
						tab[i]=random(0,size);
					}

					if (o == 1)
					{
						introsort<int>(tab,0 ,size*0.25);
					}
					else if (o == 2)
					{
						introsort<int>(tab,0 ,size*0.5);
					}
					else if (o == 3)
					{
						introsort<int>(tab,0 ,size*0.75);
					}
					else if (o == 4)
					{
						introsort<int>(tab,0 ,size*0.95);
					}
					else if (o == 5)
					{
						introsort<int>(tab,0 ,size*0.99);
					}
					else if (o == 6)
					{
						introsort<int>(tab,0 ,size*0.997);
					}

					if (a == 1){
						introsort<int>(tab,0, size-1);
						reverse(tab, size);
						if(check_rev(tab,size) !=0)
						{
							std::cout << "\n\n NOT sorted \n\n";
						}

					}
					start = std::chrono::high_resolution_clock::now();
					mergesort<int>(tab,0, size-1);
					stop = std::chrono::high_resolution_clock::now();

					if (check(tab,size) != 0)
					{
						std::cout << "\n\n NOT sorted \n\n";
					}
					fName << std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count()<< " ms. \n";
				}
				fName.close();
				break;
		}

	}


	delete [] tab;

	return 0;
}
