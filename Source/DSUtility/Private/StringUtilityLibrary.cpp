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

TArray<FString>& UStringUtilityLibrary::SortStringArray(UPARAM(ref)TArray<FString>& In)
{
	In.Sort(ConstPredicate);
	return In;
}

/*
void UStringUtilityLibrary::StringSortHelper(TArray<FString>& Strings, int32 idxA, int32 idxB)
{
	if (idxB - 1 <= idxA)
	{
		return;
	}
	int half = idxA + ((idxB - idxA) / 2);
	StringSortHelper(Strings, idxA, half);
	StringSortHelper(Strings, half + 1, idxB);

	TArray<FString> scratchSpace;

	int i, j = 0;

	while (i <= half && j <= idxB)
	{
		if (SLessThan(Strings[i], Strings[j]))
		{
			scratchSpace.Push(Strings[i]);
			i++;
		}
		else
		{
			scratchSpace.Push(Strings[j]);
			j++;
		}
	}
	while (i <= half)
	{
		scratchSpace.Push(Strings[i]);
		i++;
	}
	while (j <= idxB)
	{
		scratchSpace.Push(Strings[j]);
		j++;
	}
}
*/
