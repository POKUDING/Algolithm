#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt = 0;
	string randomnum;
	string	aoutput;
	string  foutput;
	string 	sstartbuff;
	sstartbuff += "9 5\n";
	while(1)
	{
		pid_t pid;
		int infd[2];
		int outfd[2];
		pipe(infd);
		pipe(outfd);
		pid = fork();
		if (pid == 0)
		{
			dup2(infd[0], 0);
			dup2(outfd[1], 1);
			close(infd[0]);
			close(infd[1]);
			close(outfd[0]);
			close(outfd[1]);
			execv("makerandom.py", NULL);
		}
		write(infd[1], sstartbuff.c_str(), sstartbuff.size());
		close (infd[1]);
		close(infd[0]);
		close(outfd[1]);
		char buff[2048];
		memset(buff, 0, 2048);
		read(outfd[0],buff, 2048);
		close(outfd[0]);
		randomnum += sstartbuff;
		randomnum += buff;
		memset(buff, 0, 2048);

		pipe(infd);
		pipe(outfd);
		pid = fork();
		if (pid == 0)
		{
			dup2(infd[0], 0);
			dup2(outfd[1], 1);
			close(infd[0]);
			close(infd[1]);
			close(outfd[0]);
			close(outfd[1]);
			execv("a.out", NULL);
			return 0;
		}
		write(infd[1], randomnum.c_str(), randomnum.length());
		read(outfd[0], buff, 2048);
		aoutput += buff;
		close(infd[0]);
		close(infd[1]);
		close(outfd[0]);
		close(outfd[1]);


		pipe(infd);
		pipe(outfd);
		pid = fork();
		if (pid == 0)
		{
			dup2(infd[0], 0);
			dup2(outfd[1], 1);
			close(infd[0]);
			close(infd[1]);
			close(outfd[0]);
			close(outfd[1]);
			execv("f.out", NULL);
		}
		write(infd[1], randomnum.c_str(), randomnum.length());
		read(outfd[0], buff, 2048);

		foutput += buff;
		close(infd[0]);
		close(infd[1]);
		close(outfd[0]);
		close(outfd[1]);
		if (aoutput != foutput)
			break;
		// cout << "random num : " << randomnum << "\n=============" << aoutput << foutput<< "\n" << "\n";
		randomnum.clear();
		aoutput.clear();
		foutput.clear();
		cout << ++cnt << "\n";
	}
	cout << "random num : " << randomnum << "\n=============" << aoutput << foutput<< "\n" << "\n";
		
}