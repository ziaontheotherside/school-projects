/* File:      Process.cpp
Author:       Zia Animashaun
Date:         12/08/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a process manager.
*/

#include "Process.h"

Process::Process() {
    m_name = "test";
    m_id = -1;
    m_call = -1;
    m_duration = -1;
}

Process::Process(string name, int id, int call, int duration) :
        m_name(name), m_id(id), m_call(call), m_duration(duration) { }

ostream& operator<< (ostream& output, Process& proc) {
    output << proc.m_name << " " << proc.m_id << " " << proc.m_call << " " << proc.m_duration;
    return output;
}