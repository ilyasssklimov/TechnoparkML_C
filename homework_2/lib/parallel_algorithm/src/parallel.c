#include "parallel.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <signal.h>


static inline int count_predicate_truth_gap(int *array, predicate *pred, int first, int last)
{
    if (unlikely(array == NULL || pred == NULL || first < 0 || first > last))
        return PARAM_ERROR;
    
    int count = 0;
    
    for (int i = first; i < last; i++)
        count += do_predicate(pred, array[i]);
    
    return count;
}


static inline int execute_proccess(int *array, int *total, predicate *pred, int first, int last)
{
    int pid = fork();
    if (pid == 0)
    {
        int count = count_predicate_truth_gap(array, pred, first, last);
        *total += count;
        
		free_predicate(&pred);
		free(array);
		
        if (likely(count != PARAM_ERROR))
            exit(EXIT_SUCCESS);
        else
            exit(PARAM_ERROR);
    }
    
    return pid;
}


static inline void kill_proccess(int *pid_array, int k)
{
    for (int i = 0; i < k; i++)
    {
        kill(pid_array[i], SIGKILL);
    }
}


// Количество ядер = 4
inline int count_predicate_truth(int *array, int n, predicate *pred)
{    
    if (array == NULL || n <= 0 || pred == NULL)
        return -1;
        
    int *total = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (total == MAP_FAILED)
        return MAP_ERROR;
        
    *total = 0;
    const int amount = PROCCESS_4;
    int step = n / amount;
    
    int pid_array[amount];
    pid_t result_array[amount];
    int status_array[amount];
    
    for (int i = 0; i < amount; i++)
    {
        pid_array[i] = execute_proccess(array, total, pred, i * step, (i + 1) * step);
        if (unlikely(pid_array[i] == -1))
        {
            kill_proccess(pid_array, i);
            return FORK_ERROR;
        }
        result_array[i] = waitpid(pid_array[i], &status_array[i], 0);
    }
    
    for (int i = 0; i < amount; i++)
    {
        if (unlikely(result_array[i] <= 0 || WEXITSTATUS(status_array[i]) != EXIT_SUCCESS))
            return PARAM_ERROR;
    }
    
    return *total;
}
