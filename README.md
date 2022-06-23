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

### Steps 2. Create threads and forks
-[X] Declare and init with malloc pthread_t[number_of philosophers]
-[X] Declare and init with malloc pthread_mutex_t [number_of philosophers]
-[ ] Create threads in loop (aka philosophers)
-[ ] Create mutex in loop (aka fork)

### Don't forget
-[ ] Makefile: dependecies on Makefile

## Notes

* Check Data Race:
    gcc -fsanitize=thread -g

## Testers

* https://github.com/Yoo0lh/philosopher_tester
