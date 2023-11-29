#include "ThreadPool.h"
#include "ThreadPool.cpp"
#include<unistd.h>
#include<stdio.h>
void taskFunc(void* arg)
{
    int num = *(int*)arg;
    printf("thread %ld is working, number = %d\n",
        pthread_self(), num);
    sleep(1);
}

int main()
{
    // 存在一些中文乱码
    ThreadPool<int> pool (3, 10);
    for (int i = 0; i < 100; ++i)
    {
        int* num = new int(i + 100);
        pool.addTask(Task<int>( taskFunc , num ) );
    }

    sleep(23);

    cout << "------Congreatulations , the test was successful----- ! !\n";
    return 0;
}

