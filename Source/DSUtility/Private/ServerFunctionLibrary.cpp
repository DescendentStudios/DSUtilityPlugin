// (c) 2015 Descendent Studios, Inc.

#include "DSUtilityPrivatePCH.h"

#ifdef POSIX
#include <sys/types.h>
#include <unistd.h>
#endif

#ifdef WIN32
#include <Processthreadsapi.h>
#endif

#include "ServerFunctionLibrary.h"
#include "CoreGlobals.h"


void UServerFunctionLibrary::RequestExit(bool bForce)
{
	// Ideas from https://answers.unrealengine.com/questions/231809/dedicated-server-wont-quit.html

	UE_LOG(LogInit, Log, TEXT("RequestExit: exit requested"));

	// The following has the possibility to force exit(it calls abort, the output streams might just be terminated)
	FGenericPlatformMisc::RequestExit(bForce);
}

bool UServerFunctionLibrary::IsRequestingExit()
{
	return GIsRequestingExit;
}

int32 UServerFunctionLibrary::GetProcessId()
{
#if defined(POSIX)
	return getpid();
#elif defined(WIN32) 
	return GetCurrentProcessId();
#else
#warning getpid unsupported
	return 0;
#endif
}