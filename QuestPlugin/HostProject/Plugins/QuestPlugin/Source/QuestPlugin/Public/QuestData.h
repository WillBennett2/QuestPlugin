// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FQuestInfo
{
	GENERATED_BODY()

    	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Quest")
    	FName CharacterName;
    	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Quest")
    	FName QuestID;
    	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Quest")
    	FText Description;
};

USTRUCT(BlueprintType)
struct FPlayerQuests // used for player's quest list
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Quest")
	FName QuestID;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Quest")
	bool IsCompleted;
	
};
UCLASS(BlueprintType)
class UQuestData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Quest")
	TArray<FQuestInfo> QuestData;
};

class QUESTPLUGIN_API QuestData
{
};
