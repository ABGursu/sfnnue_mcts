#include <winsock2.h>
#include <windows.h>
class Spinlock
{
	volatile long dest = 0;
	long exchange = 100;
	int compare = 0;
public:
	void acquire()
	{
		while(true)
		{
		if(InterlockedCompareExchange(&dest, exchange,compare)==0)
			break;
		}
		
	}
	void release()
	{
		dest = 0;
	}
};