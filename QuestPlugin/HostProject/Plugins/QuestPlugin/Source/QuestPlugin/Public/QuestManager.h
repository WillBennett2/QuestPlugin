// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestData.h"
#include "GameFramework/GameModeBase.h"
#include "QuestManager.generated.h"

/**
 * 
 */
UCLASS()
class QUESTPLUGIN_API AQuestManager : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent, Category="Quest System")
	FQuestInfo SearchForQuest(FName QuestID, bool& success);

	FQuestInfo SearchForQuest_Implementation(FName QuestID, bool& success);

	TArray<FPlayerQuests> m_playerQuestList;
	bool CheckPlayerQuestList(FName questID);
	void AcceptQuest(FName questID);
	void CompleteQuest(FName questID);
	void GiveQuest(FName questID);
	//ui
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowUpdatedQuestList(const TArray<FText>& questTextList);
	
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Quest System")
	class UQuestData* QuestDatabase;

	void UpdateQuestList();
};

    

