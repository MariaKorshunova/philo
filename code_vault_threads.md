# Listing Code Vaults

* Playlist "Unix Threads in C": https://code-vault.net/course/6q6s9eerd0:1609007479575 

## Short introduction to threads

    #include <pthread.h>

	void	*routine()
	{
		printf("Test from threads\n");
		sleep(3);
		printf("Ending thread\n");
	}

	int	main(int argc, char **argv)
	{
		//variable where api can store info about thread
		pthread_t	t1;
		pthread_t	t2;

		//1st arg - pointer to variable pthread_t
		//2st arg - attributes (NULL - default)
		//3st arg - pointer to function
		//4st arg - arguments
		if (pthread_create(&t1, NULL, &routine, NULL))
			return 1;
		if (pthread_create(&t2, NULL, &routine, NULL))
			return 2;
		if (pthread_join(t1, NULL))
			return 3;
		if (pthread_join(t2, NULL))
			return 4;
		return (0);
	}

## Difference between processes and threads

	// main_processes.c
	int	main(int argc, char **argv)
	{
		int pid = fork();
		int x = 2;
		if (pid == -1)
			return (1);
		if (pid == 0)
			x++;
		sleep(2);
		printf("Value of x: %d\n", x);
		printf("Process id %d\n", getpid());
		if (pid != 0)
			wait(NULL);
		return (0);
	}

	// main_threads.c

	int x = 2;

	void	*routine()
	{
		x++;
		sleep(2);
		printf("Value of x: %d\n", x);
		printf("Process id %d\n", getpid());
	}

	void	*routine2()
	{
		sleep(2);
		printf("Value of x: %d\n", x);
		printf("Process id %d\n", getpid());
	}

	int	main(int argc, char **argv)
	{
		pthread_t	t1, t2;

		if (pthread_create(&t1, NULL, &routine, NULL))
			return 1;
		if (pthread_create(&t2, NULL, &routine2, NULL))
			return 2;
		if (pthread_join(t1, NULL))
			return 3;
		if (pthread_join(t2, NULL))
			return 4;
		return (0);
	}

## Race Conditions

	//compile into assembly
	//gcc -S main.c

## Mutex (pthread_mutex)
	
	'cc main.c -fsanitize=thread -g && ./a.out'

	int				g_mails = 0;
	pthread_mutex_t	g_mutex;

	void	routine(void)
	{
		int	i;

		i = 0;
		while (i++ < 100000)
		{
			pthread_mutex_lock(&g_mutex);
			g_mails++;
			pthread_mutex_unlock(&g_mutex);
		}
	}

	int	main(int argc, char **argv)
	{
		pthread_t	t1;
		pthread_t	t2;
		pthread_t	t3;
		pthread_t	t4;

		pthread_mutex_init(&g_mutex, NULL);
		if (pthread_create(&t1, NULL, (void *)&routine, NULL))
			return (1);
		if (pthread_create(&t2, NULL, (void *)&routine, NULL))
			return (2);
		if (pthread_create(&t3, NULL, (void *)&routine, NULL))
			return (3);
		if (pthread_create(&t4, NULL, (void *)&routine, NULL))
			return (4);
		if (pthread_join(t1, NULL))
			return (5);
		if (pthread_join(t2, NULL))
			return (6);
		if (pthread_join(t3, NULL))
			return (7);
		if (pthread_join(t4, NULL))
			return (8);
		pthread_mutex_destroy(&g_mutex);
		printf("Number of mails: %d\n", g_mails);
		return (0);
	}

## Create threads in a loop

	int	main(int argc, char **argv)
	{
		pthread_t	th[8];
		int			i;

		pthread_mutex_init(&g_mutex, NULL);
		i = 0;
		while (i < 8)
		{
			if (pthread_create(&th[i], NULL, (void *)&routine, NULL))
			{
				perror("Failed to create thread");
				return (1);
			}
			printf("Thread %d has started\n", i);
			i++;
		}
		i = 0;
		while (i < 8)
		{
			if (pthread_join(th[i], NULL))
				return (2);
			printf("Thread %d has finished execution\n", i);
			i++;
		}
		pthread_mutex_destroy(&g_mutex);
		printf("Number of mails: %d\n", g_mails);
		return (0);
	}

## Get return value from a thread (pthread_join)

	#include <time.h>

	void	*roll_dice(void)
	{
		int	value;
		int	*result;

		value = (rand() % 6) + 1;
		result = malloc(sizeof(int));
		*result = value;
		printf("Thread result: %p\n", result);
		return ((void *)result);
	}

	int	main(int argc, char **argv)
	{
		pthread_t	th;
		int			*res;

		srand(time(NULL));
		if (pthread_create(&th, NULL, &roll_dice, NULL))
			return (1);
		if (pthread_join(th, (void **)&res))
			return (2);
		printf("Main res: %p\n", res);
		printf("Result: %d\n", *res);
		free(res);
		return (0);
	}

## How to pass arguments to threads in C

	int	g_primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

	void	*routine(void *arg)
	{
		int	index;

		sleep(1);
		index = *(int *)arg;
		printf("%d ", g_primes[index]);
		free(arg);
	}

	int	main(int argc, char **argv)
	{
		pthread_t	th[10];
		int			i;
		int			*a;

		i = 0;
		while (i < 10)
		{
			a = malloc(sizeof(int));
			*a = i;
			if (pthread_create(&th[i], NULL, (void *)&routine, a))
			{
				perror("Failed to create thread");
				return (1);
			}
			i++;
		}
		i = 0;
		while (i < 10)
		{
			if (pthread_join(th[i], NULL))
				return (2);
			i++;
		}
		return (0);
	}