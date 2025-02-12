/* File:      Processor.cpp
Author:       Zia Animashaun
Date:         12/08/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a process manager.
*/

#include "Processor.h"

Processor::Processor(string filename) : m_fileName(filename) { }
Processor::~Processor() {
    for(Process* proc : m_processes) {
        delete proc;
    }
    m_processes.clear();
    for(Lstack<Process*>* stack : m_threads) {
        delete stack;
    }
    m_threads.clear();
}

void Processor::InitializeProcessor() {
    DisplayTitle();
    LoadProcesses(m_fileName);
    PopulateThreads();
    //DisplayProcesses(); //for ensuring file read correctly
    MainMenu();
    cout << "Thank you for trying UMBC Processor!" << endl;
}

bool Processor::LoadProcesses(string filename) {
    ifstream in(filename);
    if(!in) return false;
    string name, text;
    int id, call, duration;
    while(in.good()) {
        getline(in, name, '|');
        getline(in, text, '|');
        id = stoi(text);
        getline(in, text, '|');
        call = stoi(text);
        getline(in, text);
        duration = stoi(text);
        if(name.length() > 0) {
            //assuming process read correctly if name is not empty
            Process* proc = new Process(name, id, call, duration);
            m_processes.push_back(proc);
        }
    }
    in.close();
    for(int i=0; i<NUM_THREADS; i++) {
        //The very first processes in file-read-order are added as the first Process to each thread
        //PopulateThread will later recursively add further processes based on its first Process' callID
        AddThread(m_processes[i]);
    }
    return true;
}

void Processor::AddThread(Process* proc) {
    Lstack<Process*>* stack = new Lstack<Process*>();
    stack->Push(proc);
    m_threads.push_back(stack);
}

int Processor::GetProcessCalled(int id) {
    for(int i=0; i<m_processes.size(); i++) {
        if(m_processes[i]->m_id == id) return i;
    }
    return -1;
}

void Processor::PopulateThreads() {
    for(int i=0; i<NUM_THREADS; i++) {
        Process* proc = m_threads[i]->Top();
        int nextCall = proc->m_call;
        while(nextCall != -1) {
            int nextIndex = GetProcessCalled(nextCall);
            if(nextIndex != -1) {
                m_threads[i]->Push(m_processes[nextIndex]);
                nextCall = m_processes[nextIndex]->m_call;
            }
            else nextCall = -1;
        }
    }
}

void Processor::MainMenu() {
    bool running = true;
    while(running) {
        int choice;
        do {
            cout << "Choose an option." << endl;
            cout << "1. Display Threads" << endl;
            cout << "2. Start Threads" << endl;
            cout << "3. Quit" << endl;
            cin >> choice;
            cin.ignore(1000, '\n');
            if(choice < 1 || choice > 3) {
                cout << "Please Enter a valid option." << endl;
            }
        } while(choice < 1 || choice > 3);
        if(choice == 1) {
            DisplayThread();
        }
        else if(choice == 2) {
            StartThreads();
        }
        else if(choice == 3) {
            running = false;
        }
    }
}

void Processor::DisplayProcesses() {
    if(m_processes.size() < 1) {
        cout << "There are no processes." << endl;
        return;
    }
    for(Process* proc : m_processes) {
        cout << *proc << endl;
    }
}

void Processor::ListThreads() {
    for(int i=0; i<NUM_THREADS; i++) {
        cout << i+1 << ". Thread " << i+1 << " (" << m_threads[i]->GetSize() << " processes)" << endl;
    }
}

int Processor::ChooseThread() {
    cout << "What thread would you like to view?" << endl;
    ListThreads();
    int choice;
    do {
        cin >> choice;
        cin.ignore(1000, '\n');
        if(choice < 1 || choice > NUM_THREADS) {
            cout << "Please enter a valid option." << endl;
        }
    } while(choice < 1 || choice > NUM_THREADS);
    return choice-1;
}

void Processor::DisplayThread() {
    int thread = ChooseThread();
    cout << "Thread " << thread+1 << endl;
    for(int i=0; i<m_threads[thread]->GetSize(); i++) {
        cout << *m_threads[thread]->At(i) << endl;
    }
}

void Processor::StartThreads() {
    for(int thread=0; thread<NUM_THREADS; thread++) {
        int durationSum = 0;
        while(!m_threads[thread]->IsEmpty()) {
            durationSum += m_threads[thread]->Top()->m_duration;
            m_threads[thread]->Pop();
        }
        cout << "Thread " << thread+1 << " took " << durationSum << " milliseconds to complete" << endl;
    }
}

void Processor::DisplayTitle() {
    cout << "Welcome to UMBC Processor!" << endl;
}