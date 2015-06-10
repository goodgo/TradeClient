#ifndef DOORBELL_H_2010_11_29_LINSH
#define DOORBELL_H_2010_11_29_LINSH

#include "VApp.h"
#include <pthread.h>
#include <io.h>

typedef SOCKET HBELL;
typedef int (*Ring_Func)(VApp *,void *);
typedef int (*OnUp_Func)(VApp *,void *);

#if defined(_WIN32)
//#define socketpair(a,b,c,d) dumb_socketpair(d,c)

typedef int socklen_t ;

#define ioctl ioctlsocket
#define close _close
#endif

//extern int dumb_socketpair(SOCKET socks[2], int make_overlapped);
class DoorBell
{
	public:
		DoorBell();
		~DoorBell();
		int Create(VApp *app);	//Ϊָ����APP����һ������
		void SetRing(Ring_Func ring,void *arg);   //������յ������Ժ���õĺ���
		void Close();
		void PressBell(int sig);	//�ͻ�������
		HBELL GetBell();			//�ͻ���ȡ����
		int doorBellRing(struct thread *t);
		int UpListener(struct thread *t);
		void UpBell();
		void RegistUpListener(VApp *app,OnUp_Func func,void *arg);
		void UnRegistUpListener();
	private:
		enum
		{
			SRV = 0,
			CLI = 1
		};
		typedef enum
		{
		    PressUp,    /*����û����*/
			PressDown   /*���尴����*/
		} DoorBellStatus;
		Ring_Func ringFunc;
		void *m_arg;
		VApp *m_app;

		OnUp_Func onUpFunc;
		void *m_cliArg;
		VApp *m_cliApp;
		struct thread *m_ringThread;
		volatile struct thread *m_uplistener;
		
		HBELL m_sock[2];
		int active;
		int referent;
		DoorBellStatus status;
		pthread_rwlock_t m_lock;
	protected:

};
#endif
