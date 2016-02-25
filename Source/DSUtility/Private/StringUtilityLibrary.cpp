#include "DSUtilityPrivatePCH.h"
#include "StringUtilityLibrary.h"
#include "CString.h"





bool UStringUtilityLibrary::SGreaterThan(FString StringA, FString StringB)
{
	return (FCString::Stricmp(*StringA, *StringB) > 0);
}


bool UStringUtilityLibrary::SLessThan(FString StringA, FString StringB)
{
	return (FCString::Stricmp(*StringA, *StringB) < 0);
}