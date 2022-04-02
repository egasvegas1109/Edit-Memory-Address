#include <iostream>
#include <windows.h>
#include <TlHelp32.h>

using namespace std;


int main()
{
	HWND hwnd = FindWindowA(NULL, "GTA NAME");

	if (hwnd == NULL)
	{
		cout << "NOT FOUND" << endl;
	}
	else
	{
		cout << "FOUND" << endl;

		DWORD ProcId;
		HANDLE handle;
		DWORD money = 0xB7CE50;
		DWORD time = 0xB70153;
		DWORD health = 0xB6FB30;

		DWORD bytes; // вместо DWORD любой тип данных, который ты хочешь прочитать
		DWORD oldProtect = 0;
		int value;
		int newvalue = 51111111111111111;
		float health_value;
		float new_health_value = 100;

		GetWindowThreadProcessId(hwnd, &ProcId);
		handle = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcId);
		
		if (ProcId == NULL)
		{
			cout << "NOT FOUND PROC" << endl;
		}
		else
		{
			cout << "FOUND PROC" << endl;
			//ReadProcessMemory(handle, (void*)money, &value, sizeof(value), 0);
			//WriteProcessMemory(handle, (void*)money, &newvalue, 4, 0);
			//VirtualProtectEx(handle, (void*)health, sizeof(bytes), PAGE_EXECUTE_READWRITE, &oldProtect);
			// 
			ReadProcessMemory(handle, (void*)money, &value, sizeof(value), NULL);
			WriteProcessMemory(handle, (void*)money, &newvalue, sizeof(newvalue), 0);

			cout << value << endl;
		}
	}
}
