// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

FQuestInfo AQuestManager::SearchForQuest_Implementation(FName QuestID, bool& success)
{
	success = false;

	FQuestInfo Quest;
	if (QuestDatabase == nullptr) { return Quest; }

	for (int i = 0; i < QuestDatabase->QuestData.Num(); i++)
	{
		if (QuestDatabase->QuestData[i].QuestID == QuestID)
		{
			success = true;
			return QuestDatabase->QuestData[i];
			
		}
	}

	return Quest;
}
void AQuestManager::GiveQuest(FName questID)
{
	//checks if player already has this quest
	if(!CheckPlayerQuestList(questID))
	{
		AcceptQuest(questID);
	}
	
}
bool AQuestManager::CheckPlayerQuestList(FName questID)
{
	for (int i = 0; i < m_playerQuestList.Num(); i ++)
	{
		if(m_playerQuestList[i].QuestID == questID)
		{
			return true;
		}
	}
	return false;
}

void AQuestManager::AcceptQuest(FName questID)
{
	FPlayerQuests NewQuest;
	NewQuest.QuestID = questID;
	NewQuest.IsCompleted = false;
	m_playerQuestList.Add(NewQuest);
	UE_LOG(LogTemp, Warning, TEXT("quest given"));
	UpdateQuestList();
}

void AQuestManager::CompleteQuest(FName questID)
{
	for (int i = 0; i < m_playerQuestList.Num(); i ++)
	{
		if((m_playerQuestList[i].QuestID==questID) && (!m_playerQuestList[i].IsCompleted))
		{
			m_playerQuestList[i].IsCompleted = true;
			break;
		}
	}
	UpdateQuestList();
}


void AQuestManager::UpdateQuestList()
{
	UE_LOG(LogTemp, Warning, TEXT("update quest list reached"));
	TArray<FText> questTextList;
	for (int i = 0; i <m_playerQuestList.Num();i++)
	{
		if(!m_playerQuestList[i].IsCompleted)
		{
			bool succcess = false;
			//get the quest
			FQuestInfo quest = SearchForQuest(m_playerQuestList[i].QuestID,succcess);
			if(succcess)
			{
				UE_LOG(LogTemp, Warning, TEXT("quest found"));
				questTextList.Add(quest.Description);
			}
		}
	}
	OnShowUpdatedQuestList(questTextList);
}
