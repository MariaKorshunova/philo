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

## Execution steps

### Steps 1. Parsing and validation arguments
-[X] Number of arguments
-[X] Check number value
-[X] Check positive int number value

### Steps 3. Initialize threads, mutex (aka forks) and data philo 
-[X] Declare and init with malloc pthread_t[number_of philosophers]
-[X] Declare and init with malloc pthread_mutex_t [number_of philosophers]
-[X] Declare and init with malloc t_data philo[number_of philosophers] (information about each philosophers)
-[X] Create threads in loop (aka philosophers)
-[X] In case for error creating threads free allocated date
-[ ] In case for error creating threads function for destroy mutex for already created threads
-[X] Create mutex in loop (aka fork)

### Steps 4. Philo_routine function
There are three kinds of problems:
* data races
* deadlock
* time of life (philosophers should avoid dying)

**Main algorithm:**
* The order of taking the forks:
    - Even philosophers are left-handed
    - Odd philosophers are right-handed


### Don't forget
-[ ] Makefile: dependecies on Makefile
-[ ] Destroy mutex
-[ ] Case of one philosopher

## Notes

* Check Data Race:
    gcc -fsanitize=thread -g

## Testers

* https://github.com/Yoo0lh/philosopher_tester
