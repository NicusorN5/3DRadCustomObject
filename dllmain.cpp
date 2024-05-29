// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

DWORD unknownInitializationArray[602] = {};

extern "C"
{
    DLLEXPORT int* __cdecl LibInit(int* a1)
    {
        OutputDebugStringA("LibInit\r\n");
        size_t possibleSize = sizeof(DWORD) * 602;

        memcpy_s(unknownInitializationArray, possibleSize, a1, sizeof(DWORD) * 602);
        return a1;
    }

    DLLEXPORT int __cdecl ObjectLibInit(int* a1)
    {
        OutputDebugStringA("ObjectLibInit \r\n");

        return 0;
    }

    DLLEXPORT int __cdecl ObjectMessages(unsigned long* message)
    {
        OutputDebugStringA("ObjectMessages \r\n");
        return 0;
    }

    DLLEXPORT void __cdecl ObjectPostExit(void** handle)
    {
        OutputDebugStringA("ObjectPostExit \r\n");
    }

    DLLEXPORT int* __cdecl ObjectPreInit(int** param_CounterPtr, int a2)
    {
        OutputDebugStringA("ObjectPreInit \r\n");
        return nullptr;
    }

    DLLEXPORT int __cdecl ObjectPropertiesRead(int a1, void* a2)
    {
        OutputDebugStringA("ObjectPropertiesRead \r\n");
        return false;
    }

    DLLEXPORT int __cdecl ObjectPropertiesWrite(int a1, void* a2)
    {
        OutputDebugStringA("ObjectPropertiesWrite \r\n");
        return false;
    }

    DLLEXPORT int* __cdecl ObjectRun(int* a1)
    {
        OutputDebugStringA("ObjectRun \r\n");
        return nullptr;
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        OutputDebugStringA("attached to process\r\n");
        break;
    case DLL_THREAD_ATTACH:
        OutputDebugStringA("attached to thread\r\n");
        break;
    case DLL_THREAD_DETACH:
        OutputDebugStringA("detached from thread\r\n");
        break;
    case DLL_PROCESS_DETACH:
        OutputDebugStringA("detached from process\r\n");
        break;
    }
    return TRUE;
}

