#include "wsh.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <unistd.h>
#include <stdlib.h>
using namespace std;



wsh::wsh()
{
	// recognized commands
	char*	commands[] = { "-place holder-", "exit", "copy" };


	// builds command name hash map
	for (unsigned i = 1; i < sizeof(commands)/sizeof(char*); i++)
		command_table[commands[i]] = i;

	system("clear");
	// LAB 1: initialize the cwd member variable here.
//    char *cwd;
//    getcwd(cwd, sizeof(cmd));
//    cout << cwd << "=> ";

}



int wsh::next_command()
{
	// LAB 1: place assignment code here.
	// Note that the program will not run until this part is completed.
	// define a command buffer and a place for the current working directory string

    static char cmd[PATH_MAX];
    char *token;

    getcwd(cwd, sizeof(cmd));
    cout << cwd << "=> ";
    cin.getline(cmd, PATH_MAX);
    token = strtok(cmd, " \t");
//    argv[0] = token;

    for (int i = 1; token != NULL; i++)
    {
        printf("%s\n",token);
        token = strtok(NULL, " \t");
//        argv[i] = token;
//        argc = 1 + i;
    }

//    cout << cwd << "=> ";
    return 0;
}

void wsh::copy()
{

}

void wsh::interpret()		// loops executing commands from the command line.
{
	bool	running = true;

	while (running)
	{
		int	c = next_command();

		switch(c)
		{
			case EXIT :
				running = false;
				break;

			case COPY :
				copy();
				break;

			case NONE :		// no command entered
				break;

			default:		// tests command line parsing
				for (int i = 0; i < argc; i++)
					cout << argv[i] << endl;
			      break;
		}
	}
}

int main()		// execution startup.
{
	wsh	cli;

	cli.interpret();

	return 0;
}

