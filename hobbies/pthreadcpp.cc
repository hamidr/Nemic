// A C++ pthread wrapper example.
//
// Copyright 2009 (c) Likai Liu <liulk@cs.bu.edu>
// Permitted for use in CS350 only.

#include <pthread.h>
#include <errno.h>

// The abstract base Thread class.  Derive a subclass and override the
// protected main() virtual method to implement your own thread main.

class Thread
{
 public:
  Thread()
    : status_(STATUS_UNINIT) {}

  ~Thread() {
    while (status_ == STATUS_PENDING)
      (void) 0;  // a spin lock.
    if (status_ == STATUS_HAS_PTH)
      pthread_detach(pth_);
  }

 protected:
  virtual void main() = 0;

  static void *trampoline(void *arg)
  {
    Thread *obj = static_cast<Thread *>(arg);
    obj->main();
    return NULL;
  }

 public:
  int start()
  {
    if (status_ != STATUS_UNINIT)
      return EAGAIN;

    status_ = STATUS_PENDING;
    int res = pthread_create(&pth_, NULL, trampoline, this);

    if (res == 0)
      status_ = STATUS_HAS_PTH;
    else
      status_ = STATUS_UNINIT;

    return res;
  }

  int join()
  {
    status_ = STATUS_PENDING;
    int res = pthread_join(pth_, NULL);
    status_ = STATUS_UNINIT;
    return res;
  }

 private:
  pthread_t pth_;

  // The status_ flag indicates how pth_ is currently used right now.
  // It enforces that a Thread object be associated with zero or one
  // running pthread.  It allows the destructor to detach a running
  // thread if it has not been joined.

  volatile enum {
    STATUS_UNINIT,      // pth_ is uninitialized.
    STATUS_PENDING,     // status of pth_ is changing.
    STATUS_HAS_PTH,     // pth_ is should be valid.
  } status_;
};

// This is your thread class.

class MyThread : public Thread
{
 public:
  MyThread() : result_(0) {}
  virtual ~MyThread() {}

 protected:
  virtual void main()
  {
    result_ = 1;
  }

 private:
  int result_;
};

int main()
{
  MyThread th;
  th.start();
  th.join();
  return 0;
}
