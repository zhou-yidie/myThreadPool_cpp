#pragma once
#include "TaskQueue.h"
#include "TaskQueue.cpp"
template <typename T>
class ThreadPool
{
public:
    
    // �����̳߳ز���ʼ��
    ThreadPool(int min, int max);
    ~ThreadPool();
    // �����߳�

    // ���̳߳��������
    void addTask(Task<T> task);

    // ��ȡ�̳߳��й������̵߳ĸ���
    int getBusyNum();

    // ��ȡ�̳߳��л��ŵ��̵߳ĸ���
    int getAliveNum();
private:
    //////////////////////
    // �������߳�(�������߳�)������
    static void* worker(void* arg);
    // �������߳�������
    static void* manager(void* arg);
    // �����߳��˳�
    void threadExit();


private:
    TaskQueue<T>* taskQ;
    

    pthread_t managerID;    // �������߳�ID
    pthread_t* threadIDs;   // �������߳�ID
    int minNum;             // ��С�߳�����
    int maxNum;             // ����߳�����
    int busyNum;            // æ���̵߳ĸ���
    int liveNum;            // �����̵߳ĸ���
    int exitNum;            // Ҫ���ٵ��̸߳���
    pthread_mutex_t mutexPool;  // ���������̳߳�
    pthread_cond_t notEmpty;    // ��������ǲ��ǿ���

    bool shutdown;           // �ǲ���Ҫ�����̳߳�, ����Ϊ1, ������Ϊ0
    static const int NUMBER = 2;


};

