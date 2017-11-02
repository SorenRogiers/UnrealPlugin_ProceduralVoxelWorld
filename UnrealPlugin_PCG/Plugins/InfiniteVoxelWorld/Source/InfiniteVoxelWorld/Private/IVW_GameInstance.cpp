// Fill out your copyright notice in the Description page of Project Settings.

#include "IVW_GameInstance.h"
#include "SaveGameSystem.h"
#include "PlatformFeatures.h"
#include <wtypes.h>


void UIVW_GameInstance::Init()
{
	UGameInstance::Init();
	
}

TArray<FSaveData> UIVW_GameInstance::GetAllSaveGameSlotNames()
{
	TArray<FSaveData> saveFiles;
	ISaveGameSystem* SaveSystem = IPlatformFeaturesModule::Get().GetSaveGameSystem();

	// If SaveGameSystem is valid
	if (SaveSystem)
	{
		// Finding 
		FString saveGamePath = FString::Printf(TEXT("%s/SaveGames/*"), *FPaths::GameSavedDir());

		WIN32_FIND_DATA fd;
		HANDLE hFind = ::FindFirstFile(*saveGamePath, &fd);
		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				// Check empty names
				if (fd.cFileName[0] == '\0' ||
					fd.cFileName[0] == '.' && fd.cFileName[1] == '\0' ||
					fd.cFileName[0] == '.' && fd.cFileName[1] == '.' && fd.cFileName[2] == '\0')
				{
				}
				else if (fd.cFileName[0] != '.')	// read file
				{
					SYSTEMTIME stUTC, stLocal;
					FileTimeToSystemTime(&fd.ftCreationTime, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

					FString name = FString(fd.cFileName);
					FDateTime date = FDateTime(stUTC.wYear, stUTC.wMonth, stUTC.wDay, stUTC.wHour, stUTC.wMinute, stUTC.wSecond, stUTC.wMilliseconds);

					if (name.Contains(".sav")) {
						saveFiles.Add(FSaveData(name, date));
					}
				}
			} while (::FindNextFile(hFind, &fd));
			::FindClose(hFind);
		}
	}
	return saveFiles;
}
