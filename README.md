# philo

## Useful source

* Playlist "Unix Threads in C": https://code-vault.net/course/6q6s9eerd0:1609007479575

* https://www.youtube.com/watch?v=dOVdsd31WNg

* https://www.youtube.com/watch?v=_ruovgwXyYs


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



### Don't forget
-[ ] Makefile: dependecies on Makefile
-[ ] Destroy mutex
-[ ] Case of one philosopher

## Notes

* Check Data Race:
    gcc -fsanitize=thread -g

## Testers

* https://github.com/Yoo0lh/philosopher_tester
