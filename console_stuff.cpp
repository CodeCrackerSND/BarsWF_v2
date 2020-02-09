#include "console_stuff.h"
#include <iostream>
#include <assert.h>
#include "perm.h"
#include <math.h>

using namespace std;

void console_color(ui theColour)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Get handle to standard output
	SetConsoleTextAttribute(hConsole,theColour);  // set the text attribute of the previous handle
}

void console_xy(int x, int y)
{
	COORD coord = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

void clrscr()
{
	WORD wColor = 0;//((15 & 0x0F) << 4) + (7 & 0x0F);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {0, 0};
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	SetConsoleTextAttribute(hStdOut, wColor);
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
		SetConsoleCursorPosition(hStdOut, coord);
	}
}

void dup(unsigned char character, int n)
{
	for(int i=0;i<n;i++)cout<<character;
}

void print_status_nonlocked(char *status, int color)//for internal use only
{
	console_xy(0, g->ui_total_y+6);console_color(13);
	dup('\xcd', 61);
	console_xy(2, g->ui_total_y+6);console_color(color);
	printf("%s", status);
}

void print_special_char(wchar_t value)
{
	wchar_t   szwOut[10];
	szwOut[0] = value;
	szwOut[1] = 0;
	DWORD      dwBytesWritten;
	WriteConsoleW( GetStdHandle(STD_OUTPUT_HANDLE), szwOut, (DWORD)wcslen(szwOut), &dwBytesWritten, 0);
}

void print_status(char *status, int color)
{
	Poco::ScopedLock<Poco::FastMutex> lock(g->console_mutex);
	print_status_nonlocked(status, color);
}

void set_title(string title)
{
	SetConsoleTitle((string("BarsWF: ")+title).c_str());
}

void printUsage()
{
	Poco::ScopedLock<Poco::FastMutex> lock(g->console_mutex);

	cout << "" << endl;
	cout << "Usage: " << endl;
	cout << " -?			  		Prints this help " << endl;
	cout << " -r					Continue previous work from barswf.save BarsWF updates it every 5 minutes or on exit" << endl;
	cout << " -h 1b0e9fd3086d90a159a1d6cb86f11b4c	Set hash to attack " << endl;
	cout << " -c 0aA~  				Set charset. 0 - digits, a - small chars, A - capitals, ~ - special symbols" << endl;
	cout << " -C \"abc23#\"  				Add custom characters to charset." << endl << endl;
	cout << " -X \"0D0A00\"  				Add custom characters in hex to charset." << endl << endl;
	cout << " -min_len 3  				Minimal password length. Default 0. MAX 15!!! :-]" << endl;
	cout << " -cpu_n 3  				Number of CPU workers. Default is detected number of cores." << endl;
#ifdef GPU
	cout << " -gpu_time 1500  			How long GPU kernel allowed to work, in milliseconds. \n					1500 - a bit faster, 50 - a bit slower, but windows is more responsive. \n					Default 100." << endl;
	cout << " -gpu_mask 15  				Enable/disable GPUs. 1 - to use first GPU, 2- 2nd, 4-3rd,\n					e.t.c You may combine values. GPUs over 32th are always used ;-)." << endl;
#endif
#ifdef CUDA	
	cout << " -thread_n 128  			| Might increase speed on GTX260 and later." << endl;
	cout << " -grid_n 128  				| Try 192, 256 e.t.c. for both" << endl << endl;
#endif
}


void draw_header()
{
	Poco::ScopedLock<Poco::FastMutex> lock(g->console_mutex);

	/*for(int i=0;i<16;i++) //Just to guess colors
	{
		console_color(i);cout << i << " ";
	}
	getch();*/
	console_color(7);

	cout<<"\xc9";dup('\xcd', 59);cout<<'\xbb'<<endl;
	cout<<"\xba";dup(' ', 59);cout<<'\xba'<<endl;
	cout<<"\xba";dup(' ', 59);cout<<'\xba'<<endl;
	cout<<"\xc8";dup('\xcd', 59);cout<<'\xbc'<<endl;


	console_xy(2, 1);console_color(7);
	printf("BarsWF MD5 bruteforcer v%s", VERSION);
	console_xy(2, 2);console_color(7);
	printf("by Svarychevski Michail");
	console_xy(38, 1);console_color(11);
	printf("http://3.14.by/en/md5");
	console_xy(38, 2);
	printf("http://3.14.by/ru/md5");
	console_xy(5, 20);console_color(7);
	console_xy(0, 4);console_color(7);

}

void draw_stat()
{
	Poco::ScopedLock<Poco::FastMutex> lock(g->console_mutex);

	console_xy(0,3);
	//cout<<"\xc7";
	print_special_char(0x255F);dup('\xc4', 59);print_special_char(0x2562);cout<<endl;
	//cout<<'\xb6'<<endl;
	for(int i=0;i<max(g->gpu_count, g->cpu_count)+1;i++)
	{
		char blank[]  = "                            ";
		printf("\xba  ");
		if(i<g->gpu_count)printf(" GPU%-2d: ....... MHash/sec   ", i);else printf(blank);
		if(i<g->cpu_count)printf(" CPU%-2d: ....... MHash/sec   ", i);else printf(blank);
		printf(" \xba\n");
	};
	printf("\xba   GPU* : ....... MHash/sec    CPU* : ....... MHash/sec    \xba\n");

	print_special_char(0x255F);dup('\xc4', 59);print_special_char(0x2562);cout<<endl;
	printf("\xba Key:                      Avg.Total: ....... MHash/sec    \xba\n");
	printf("\xba Hash:%.32s                     \xba\n", g->hash.c_str());
	printf("\xba Progress: ..... %% ETC:.... days .. hours .. min .. sec    \xba\n");
	cout<<"\xc8";dup('\xcd', 59);cout<<'\xbc'<<endl;
	g->ui_total_y = 3+max(g->cpu_count, g->gpu_count)+2;

}

//!!!todo move to algo-specific
void extract_key(char *buffer)
{
	union
	{
		unsigned char pass_c[64];
		int pass_i[16];
	};

	memset(pass_c, 0, sizeof(pass_c));
	for(int i=0;i<4;i++)pass_i[i] = g->final_key[i];//common_h->res[i];

	int pos=0;
	for(unsigned int i=0;i*8<g->final_len;i++)
		buffer[pos++]=pass_c[i];//looks not very optimal
}

void print_result()
{
	Poco::ScopedLock<Poco::FastMutex> lock(g->console_mutex);

	if(!g->is_key_found)
	{
		if(g->is_corrupted)
		{
			print_status_nonlocked("", 13);
			printf(" Wrong computation, results are incorrect.\nMight be GPU driver problem, overclocking or DNA error :crazy: \n");

			//special case for multiline output
			console_xy(12, g->ui_total_y+8);console_color(14);
			console_color(7);
//			printf("\nPress any key to exit");
			return;

		} else
		if(!g->is_error_detected)
		{
			print_status_nonlocked("", 13);
			printf(" Key was not found. \n");
		}
	} else
	{
		print_status_nonlocked("", 13);
		printf(" Key is: ");

		char buffer[256];
		memset(buffer, 0, sizeof(buffer));
		extract_key(buffer);
		cout << buffer;  // SHOULD PRINT THE KEY!
		set_title("Key found.");
		g->log->information("Key found: "+string(buffer));
	}

	console_xy(12, g->ui_total_y+10);
	console_color(7);
//	printf("\nPress any key to exit");
}

