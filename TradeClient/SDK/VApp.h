#ifndef VTHREAD_H_2011_11_23_LINSHUX
#define VTHREAD_H_2011_11_23_LINSHUX

#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>


#if defined(_WIN32) /* VC++, 32-Bit */
#include <Winsock2.h>

#define bzero(b,s) memset(b,0,s)

//#include <windows.h>

#endif
 
#if defined(linux) || defined(__LYNX)
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#endif

	/* Macros. */
#define THREAD_ARG(X) ((X)->arg)
#define THREAD_FD(X)  ((X)->u.fd)
#define THREAD_VAL(X) ((X)->u.val)
#define THREAD_VTHREAD(X) ((X)->vthread)

#define DECLARE_APP_FUNC(class_name,func_name)   \
static int func_name(struct thread *t)  \
{ \
	class_name *app = (class_name *)THREAD_VTHREAD(t);  \
	app->func_name(t);  \
}



struct thread_list
{
  struct thread *head;
  struct thread *tail;
  int count;
};

/* Master of the theads. */
struct thread_master
{
  struct thread_list read;
  struct thread_list write;
  struct thread_list timer;
  struct thread_list event;
  struct thread_list ready;
  struct thread_list unuse;
  fd_set readfd;
  fd_set writefd;
  fd_set exceptfd;
  unsigned long alloc;
};

//class VApp;




typedef int (*FUNC)(struct thread *);

extern "C"{
	class _declspec(dllexport) VApp
	{
	public:
		VApp();
		virtual ~VApp();
		virtual int Init();
		void Run(int bthread);
		int Join(void **status);
		pthread_t getMyId() {
			 return myid;
		};
	private:
		pthread_t myid;
		struct thread_master *m;
		struct thread_master *thread_make_master ();
		void thread_list_add (struct thread_list *list, struct thread *thread);
		void thread_list_add_before (struct thread_list *list, 
				struct thread *point, 
				struct thread *thread);
		struct thread *thread_list_delete (struct thread_list *list,
				struct thread *thread);
		void thread_clean_unuse ();
		void thread_add_unuse (struct thread *thread);
		void	thread_destroy_master ();
		struct thread *thread_trim_head (struct thread_list *list);
		struct thread *thread_new ();
		int 	thread_timer_cmp (struct timeval a, struct timeval b);
		struct timeval thread_timer_sub (struct timeval a, struct timeval b);
		unsigned long int thread_get_id ();

	#ifdef DEBUG
		void thread_timer_dump (struct timeval tv);
		void thread_list_debug (struct thread_list *list);
	#endif
	public:
		/* Prototypes. */
	
		struct thread *thread_add_read (FUNC func, void *arg, int fd);

		struct thread *thread_add_write (FUNC func, void *arg, int fd);

		struct thread *thread_add_timer (FUNC func, void *arg, long timer);

		struct thread *thread_add_event (FUNC func, void *arg, int val);

		void thread_cancel (struct thread *thread);

		void thread_cancel_event (void *arg);

		struct thread *thread_fetch (struct thread *fetch);

		void thread_call (struct thread *thread);

		struct thread *thread_execute (FUNC func, void *arg, int val);
	
	#ifdef DEBUG
		void thread_master_debug ();
	#endif /* DEBUG */
	};
}

/* Thread itself. */
struct thread
{
  unsigned long id;
  unsigned char type;		/* thread type */
  struct thread *next;		/* next pointer of the thread */
  struct thread *prev;		/* previous pointer of the thread */
  struct thread_master *master;	/* pointer to the struct thread_master. */
  int (*func) (struct thread *); /* event function */
  void *arg;			/* event argument */
  union {
    int val;			/* second argument of the event. */
    int fd;			/* file descriptor in case of read/write. */
    struct timeval sands;	/* rest of time sands value. */
  } u;
  VApp *vthread;
};

#endif

