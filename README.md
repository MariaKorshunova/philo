# philo

## Useful source

* Playlist "Unix Threads in C": https://code-vault.net/course/6q6s9eerd0:1609007479575

* https://www.youtube.com/watch?v=dOVdsd31WNg

* https://www.youtube.com/watch?v=_ruovgwXyYs

## Allowed external functions

|Function             |Prototype                                |Description                          |
|---------------------|-----------------------------------------|-------------------------------------|
|memset               |void *memset(void *b, int c, size_t len);|writes len bytes of value c (converted to an unsigned char) to the string b|
|printf               |int printf(const char * restrict format, ...)|writes output to stdout|
|malloc               |void *malloc(size_t size)| allocate memory
|free                 |void free(void *ptr)|frees allocations that were created|
|write                |ssize_t write(int fildes, const void *buf, size_t nbyte)|write nbyte of data to the object referenced by the descriptor fildes from the buffer pointed to by buf|
|usleep               |int usleep(useconds_t microseconds)|suspends execution of the calling thread until either microseconds microseconds have elapsed or a signal is delivered to the thread and its action is to invoke a signal-catching function or to terminate the process|
|gettimeofday         |int gettimeofday(struct timeval *restrict tp, void *restrict tzp)|The time is expressed in seconds and microseconds since midnight (0 hour), January 1, 1970|
|pthread_create       |int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)|create a new thread|
|pthread_detach       |int pthread_detach(pthread_t thread)|indicate to the implementation that storage for the thread thread can be reclaimed when the thread terminates|
|pthread_join         |int pthread_join(pthread_t thread, void **value_ptr)|suspends execution of the calling thread until the target thread terminates unless the target thread has already terminated|
|pthread_mutex_init   |int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)|creates a new mutex|
|pthread_mutex_destroy|int pthread_mutex_destroy(pthread_mutex_t *mutex)|frees the resources allocated for mutex|
|pthread_mutex_lock   |int pthread_mutex_lock(pthread_mutex_t *mutex)|locks mutex|
|pthread_mutex_unlock |int pthread_mutex_unlock(pthread_mutex_t *mutex)|unlocks mutex|

## Notes

* Check Data Race:
    gcc -fsanitize=thread -g

## Testers

* https://github.com/Yoo0lh/philosopher_tester
